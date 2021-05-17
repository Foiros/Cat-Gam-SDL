cmake_minimum_required(VERSION 3.19)
project(CatGameSDL)

set(CMAKE_CXX_STANDARD 20)

# SDL itself
set(SDL2_INCLUDE_DIR E:/SDL/SDL2-2.0.14/include)
set(SDL2_LIB_DIR E:/SDL/SDL2-2.0.14/lib/x86)

# SDL image härpäke
set(SDL2_IMAGE_INCLUDE_DIR E:/SDL/SDL2-2.0.14/Images/include)
set(SDL2_IMAGE_LIB_DIR E:/SDL/SDL2-2.0.14/Images/lib/x86)

# SDL fontit
set(SDL2_FONT_INCLUDE_DIR E:/SDL/SDL2-2.0.14/Fonts/include)
set(SDL2_FONT_LIB_DIR E:/SDL/SDL2-2.0.14/Fonts/lib/x86)

# SDL audio mixeri
set(SDL2_AUDIO_INCLUDE_DIR E:/SDL/SDL2-2.0.14/Audio/include)
set(SDL2_AUDIO_LIB_DIR E:/SDL/SDL2-2.0.14/Audio/lib/x86)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_FONT_INCLUDE_DIR} ${SDL2_AUDIO_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR} ${SDL2_IMAGE_LIB_DIR} ${SDL2_FONT_LIB_DIR} ${SDL2_AUDIO_LIB_DIR})


add_executable(CatGameSDL SDL/HeaderFiles/AnimatedTexture.h SDL/HeaderFiles/AssetManager.h SDL/HeaderFiles/AudioManager.h SDL/HeaderFiles/GameEntity.h
        SDL/HeaderFiles/GameManager.h SDL/HeaderFiles/Graphics.h SDL/HeaderFiles/InputManager.h SDL/HeaderFiles/MathHelper.h SDL/HeaderFiles/Texture.h
        SDL/HeaderFiles/Timer.h

        SDL/CPPFiles/AnimatedTexture.cpp SDL/CPPFiles/AssetManager.cpp SDL/CPPFiles/AudioManager.cpp SDL/CPPFiles/GameEntity.cpp SDL/CPPFiles/GameManager.cpp
        SDL/CPPFiles/Graphics.cpp SDL/CPPFiles/InputManager.cpp SDL/CPPFiles/Texture.cpp SDL/CPPFiles/Timer.cpp SDL/CPPFiles/SDLMain.cpp

        Pathfinding/CPPFiles/PathfindingClosedList.cpp Pathfinding/HeaderFiles/PathfindingClosedList.h Pathfinding/CPPFiles/PathfindingOpenList.cpp
        Pathfinding/HeaderFiles/PathfindingOpenList.h Pathfinding/CPPFiles/Pathfinding.cpp Pathfinding/HeaderFiles/Pathfinding.h
        Pathfinding/CPPFiles/SearchLevel.cpp Pathfinding/HeaderFiles/SearchLevel.h Pathfinding/CPPFiles/SearchNode.cpp Pathfinding/HeaderFiles/SearchNode.h)


target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
target_link_libraries(${PROJECT_NAME} SDL2_image)
target_link_libraries(${PROJECT_NAME} SDL2_ttf)
target_link_libraries(${PROJECT_NAME} SDL2_mixer)