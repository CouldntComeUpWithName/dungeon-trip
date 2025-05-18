set(EXECUTABLE_NAME dungeon-trip)

add_executable(${EXECUTABLE_NAME})

set(SOURCES src/main.cpp 
  src/singleton.hpp
  src/scenes/scene.hpp
  src/assets/sounds.hpp
  src/events/event.hpp
  src/layer.hpp
  src/app.hpp src/app.cpp
  src/audio_layer.hpp src/audio_layer.cpp
  src/scene_layer.hpp src/scene_layer.cpp
  src/scenes/game_level.hpp src/scenes/game_level.cpp
  src/scenes/main_menu.hpp)

file(GLOB_RECURSE RESOURCES res/*)

target_sources(${EXECUTABLE_NAME} PRIVATE ${SOURCES} PRIVATE ${RESOURCES})

target_link_libraries(${EXECUTABLE_NAME} PRIVATE ges PRIVATE raylib)

if(CMAKE_CONFIGURATION_TYPES)
  set_target_properties(${EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>")
else()
  set_target_properties(${EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")
endif()

if(MSVC)
  set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${EXECUTABLE_NAME})
  set_property(TARGET ${EXECUTABLE_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>")
  
  source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${RESOURCES})
endif()



