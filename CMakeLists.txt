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

# Add SDL framework to the project
add_executable(CatGameSDL SDL/main.cpp SDL/AnimatedTexture.cpp SDL/AnimatedTexture.h SDL/AssetManager.cpp SDL/AssetManager.h SDL/AudioManager.cpp SDL/AudioManager.h
        SDL/GameEntity.cpp SDL/GameEntity.h SDL/GameManager.cpp SDL/GameManager.h SDL/Graphics.cpp SDL/Graphics.h SDL/InputManager.cpp SDL/InputManager.h
        SDL/MathHelper.h SDL/Texture.cpp SDL/Texture.h SDL/Timer.cpp SDL/Timer.h Pathfinding/PathfindingClosedList.cpp
        Pathfinding/PathfindingClosedList.h Pathfinding/PathfindingOpenList.cpp Pathfinding/PathfindingOpenList.h Pathfinding/Pathfinding.cpp
        Pathfinding/Pathfinding.h Pathfinding/SearchLevel.cpp Pathfinding/SearchLevel.h Pathfinding/SearchNode.cpp Pathfinding/SearchNode.h)


target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
target_link_libraries(${PROJECT_NAME} SDL2_image)
target_link_libraries(${PROJECT_NAME} SDL2_ttf)
target_link_libraries(${PROJECT_NAME} SDL2_mixer)