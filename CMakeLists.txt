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


add_executable(CatGameSDL CatGame/SDLHeaderFiles/AnimatedTexture.h CatGame/SDLHeaderFiles/AssetManager.h CatGame/SDLHeaderFiles/AudioManager.h CatGame/SDLHeaderFiles/GameEntity.h
        CatGame/CatGameHeaderFiles/GameManager.h CatGame/SDLHeaderFiles/Graphics.h CatGame/SDLHeaderFiles/InputManager.h CatGame/SDLHeaderFiles/MathHelper.h CatGame/SDLHeaderFiles/Texture.h
        CatGame/SDLHeaderFiles/Timer.h

        CatGame/SDLCPPFiles/AnimatedTexture.cpp CatGame/SDLCPPFiles/AssetManager.cpp CatGame/SDLCPPFiles/AudioManager.cpp CatGame/SDLCPPFiles/GameEntity.cpp CatGame/CatGameCPPFiles/GameManager.cpp
        CatGame/SDLCPPFiles/Graphics.cpp CatGame/SDLCPPFiles/InputManager.cpp CatGame/SDLCPPFiles/Texture.cpp CatGame/SDLCPPFiles/Timer.cpp CatGame/SDLCPPFiles/SDLMain.cpp

        CatGame/CatGameHeaderFiles/MainMenu.h CatGame/CatGameHeaderFiles/PlayScreen.h CatGame/CatGameCPPFiles/MainMenu.cpp CatGame/CatGameCPPFiles/PlayScreen.cpp CatGame/CatGameHeaderFiles/MotherCat.h CatGame/CatGameCPPFiles/MotherCat.cpp

        CatGame/PathfindingHeaderFiles/PathfindingGrid.h CatGame/PathfindingCPPFiles/PathfindingGrid.cpp CatGame/PathfindingCPPFiles/Pathfinding.cpp CatGame/PathfindingHeaderFiles/Pathfinding.h)


target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
target_link_libraries(${PROJECT_NAME} SDL2_image)
target_link_libraries(${PROJECT_NAME} SDL2_ttf)
target_link_libraries(${PROJECT_NAME} SDL2_mixer)