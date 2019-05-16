cmake_minimum_required(VERSION 3.14)
project(rogue_like)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS window network system graphics audio REQUIRED)

add_executable(rogue_like main.cpp Game.cpp Game.h entities/Entity.cpp entities/Entity.h states/State.cpp states/State.h states/GameState.cpp states/GameState.h states/MainMenuState.cpp states/MainMenuState.h Button.cpp Button.h entities/Player.cpp entities/Player.h components/MovementComponent.cpp components/MovementComponent.h components/AnimationComponent.cpp components/AnimationComponent.h states/EditorState.cpp states/EditorState.h components/HitBoxComponent.cpp components/HitBoxComponent.h)

target_link_libraries(rogue_like sfml-graphics sfml-audio sfml-system sfml-window sfml-network)