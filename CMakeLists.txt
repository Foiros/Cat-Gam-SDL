cmake_minimum_required(VERSION 3.19)
project(CatGameSDL)

set(CMAKE_CXX_STANDARD 20)

# SDLFramework itself
set(SDL2_INCLUDE_DIR E:/SDL/SDL2-2.0.14/include)
set(SDL2_LIB_DIR E:/SDL/SDL2-2.0.14/lib/x86)

# SDLFramework image härpäke
set(SDL2_IMAGE_INCLUDE_DIR E:/SDL/SDL2-2.0.14/Images/include)
set(SDL2_IMAGE_LIB_DIR E:/SDL/SDL2-2.0.14/Images/lib/x86)

# SDLFramework fontit
set(SDL2_FONT_INCLUDE_DIR E:/SDL/SDL2-2.0.14/Fonts/include)
set(SDL2_FONT_LIB_DIR E:/SDL/SDL2-2.0.14/Fonts/lib/x86)

# SDLFramework audio mixeri
set(SDL2_AUDIO_INCLUDE_DIR E:/SDL/SDL2-2.0.14/Audio/include)
set(SDL2_AUDIO_LIB_DIR E:/SDL/SDL2-2.0.14/Audio/lib/x86)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_FONT_INCLUDE_DIR} ${SDL2_AUDIO_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR} ${SDL2_IMAGE_LIB_DIR} ${SDL2_FONT_LIB_DIR} ${SDL2_AUDIO_LIB_DIR})


add_executable(CatGameSDL CatGame/SDLFramework/SDLHeaderFiles/AnimatedTexture.h CatGame/SDLFramework/SDLHeaderFiles/AssetManager.h CatGame/SDLFramework/SDLHeaderFiles/AudioManager.h CatGame/SDLFramework/SDLHeaderFiles/GameEntity.h
        CatGame/CatGameHeaderFiles/GameManager.h CatGame/SDLFramework/SDLHeaderFiles/Graphics.h CatGame/SDLFramework/SDLHeaderFiles/InputManager.h CatGame/SDLFramework/SDLHeaderFiles/MathHelper.h CatGame/SDLFramework/SDLHeaderFiles/Texture.h
        CatGame/SDLFramework/SDLHeaderFiles/Timer.h

        CatGame/SDLFramework/SDLCPPFiles/AnimatedTexture.cpp CatGame/SDLFramework/SDLCPPFiles/AssetManager.cpp CatGame/SDLFramework/SDLCPPFiles/AudioManager.cpp CatGame/SDLFramework/SDLCPPFiles/GameEntity.cpp CatGame/CatGameHeaderFiles/GameManager.cpp
        CatGame/SDLFramework/SDLCPPFiles/Graphics.cpp CatGame/SDLFramework/SDLCPPFiles/InputManager.cpp CatGame/SDLFramework/SDLCPPFiles/Texture.cpp CatGame/SDLFramework/SDLCPPFiles/Timer.cpp CatGame/SDLFramework/SDLCPPFiles/SDLMain.cpp

        CatGame/Pathfinding/PathfindingCPPFiles/PathfindingClosedList.cpp CatGame/Pathfinding/PathfindingHeaderFiles/PathfindingClosedList.h CatGame/Pathfinding/PathfindingCPPFiles/PathfindingOpenList.cpp
        CatGame/Pathfinding/PathfindingHeaderFiles/PathfindingOpenList.h CatGame/Pathfinding/PathfindingCPPFiles/Pathfinding.cpp CatGame/Pathfinding/PathfindingHeaderFiles/Pathfinding.h
        CatGame/Pathfinding/PathfindingCPPFiles/SearchLevel.cpp CatGame/Pathfinding/PathfindingHeaderFiles/SearchLevel.h CatGame/Pathfinding/PathfindingCPPFiles/SearchNode.cpp CatGame/Pathfinding/PathfindingHeaderFiles/SearchNode.h

        CatGame/CatGameHeaderFiles/MainMenu.h CatGame/CatGameHeaderFiles/PlayScreen.h CatGame/CatGameCPPFiles/MainMenu.cpp CatGame/CatGameCPPFiles/PlayScreen.cpp CatGame/CatGameHeaderFiles/MotherCat.h CatGame/CatGameCPPFiles/MotherCat.cpp)


target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
target_link_libraries(${PROJECT_NAME} SDL2_image)
target_link_libraries(${PROJECT_NAME} SDL2_ttf)
target_link_libraries(${PROJECT_NAME} SDL2_mixer)