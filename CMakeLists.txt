cmake_minimum_required(VERSION 3.14)
project(rogue_like)

set(CMAKE_CXX_STANDARD 17)

add_executable(rogue_like main.cpp Game.cpp Game.h entities/Entity.cpp entities/Entity.h states/State.cpp states/State.h states/GameState.cpp states/GameState.h states/MainMenuState.cpp states/MainMenuState.h Button.cpp Button.h entities/Player.cpp entities/Player.h components/MovementComponent.cpp components/MovementComponent.h components/AnimationComponent.cpp components/AnimationComponent.h states/EditorState.cpp states/EditorState.h components/HitBoxComponent.cpp components/HitBoxComponent.h Tile/Tile.cpp Tile/Tile.h GUI/PauseMenuState.cpp GUI/PauseMenuState.h)

set(SFML_INCLUDE_DIR "/home/insperias/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/insperias/SFML-2.5.1/lib")
link_directories("/home/insperias/SFML-2.5.1/lib")
include_directories("/home/insperias/SFML-2.5.1/include")
set(SFML_DIR "/home/insperias/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)

    message(STATUS "SFML_INCLUDE_DIRS: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")

    include_directories(${SFML_INCLUDE_DIRS})

endif()

target_link_libraries (rogue_like sfml-graphics sfml-window sfml-system)