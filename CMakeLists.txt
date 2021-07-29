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


add_executable(CatGameSDL CatGame/SDLHeaderFiles/AnimatedTexture.h CatGame/SDLHeaderFiles/AssetManager.h CatGame/SDLHeaderFiles/AudioManager.h
        CatGame/SDLHeaderFiles/GameEntity.h CatGame/CatGameHeaderFiles/GameManager.h CatGame/SDLHeaderFiles/Graphics.h CatGame/SDLHeaderFiles/InputManager.h
        CatGame/SDLHeaderFiles/MathHelper.h CatGame/SDLHeaderFiles/Texture.h CatGame/SDLHeaderFiles/Timer.h

        CatGame/SDLCPPFiles/AnimatedTexture.cpp CatGame/SDLCPPFiles/AssetManager.cpp CatGame/SDLCPPFiles/AudioManager.cpp CatGame/SDLCPPFiles/GameEntity.cpp
        CatGame/CatGameCPPFiles/GameManager.cpp CatGame/SDLCPPFiles/Graphics.cpp CatGame/SDLCPPFiles/InputManager.cpp CatGame/SDLCPPFiles/Texture.cpp
        CatGame/SDLCPPFiles/Timer.cpp CatGame/SDLCPPFiles/SDLMain.cpp

        CatGame/CatGameHeaderFiles/MainMenu.h CatGame/CatGameHeaderFiles/PlayScreen.h CatGame/CatGameCPPFiles/MainMenu.cpp
        CatGame/CatGameCPPFiles/PlayScreen.cpp CatGame/CatGameHeaderFiles/MotherCat.h CatGame/CatGameCPPFiles/MotherCat.cpp

        CatGame/PathfindingHeaderFiles/PathfindingGrid.h CatGame/PathfindingCPPFiles/PathfindingGrid.cpp
        CatGame/PathfindingCPPFiles/Pathfinding.cpp CatGame/PathfindingHeaderFiles/Pathfinding.h
        CatGame/CatGameHeaderFiles/Kitten.h CatGame/CatGameCPPFiles/Kitten.cpp CatGame/PathfindingHeaderFiles/PathfindingUnit.h
        CatGame/PathfindingCPPFiles/PathfindingUnit.cpp CatGame/CatGameHeaderFiles/Nest.h CatGame/CatGameCPPFiles/Nest.cpp
        CatGame/CatGameHeaderFiles/Meat.h CatGame/CatGameHeaderFiles/Water.h
        CatGame/CatGameCPPFiles/Meat.cpp CatGame/CatGameCPPFiles/Water.cpp
        CatGame/CatGameHeaderFiles/Tree.h CatGame/CatGameHeaderFiles/Mouse.h CatGame/CatGameHeaderFiles/Flower.h CatGame/CatGameCPPFiles/Flower.cpp
        CatGame/CatGameCPPFiles/Mouse.cpp CatGame/CatGameCPPFiles/Tree.cpp CatGame/PhysicsEngineHeaderFiles/Collider.h CatGame/PhysicsEngineCPPFiles/Collider.cpp
        CatGame/PhysicsEngineHeaderFiles/BoxCollider.h CatGame/PhysicsEngineCPPFiles/BoxCollider.cpp CatGame/PhysicsEngineHeaderFiles/PhysicsEntity.h
        CatGame/PhysicsEngineHeaderFiles/PhysicsHelper.h CatGame/PhysicsEngineCPPFiles/PhysicsEntity.cpp CatGame/PhysicsEngineHeaderFiles/PhysicsManager.h

        CatGame/PhysicsEngineCPPFiles/PhysicsManager.cpp CatGame/PhysicsEngineHeaderFiles/CircleCollider.h CatGame/PhysicsEngineCPPFiles/CircleCollider.cpp
        CatGame/CatGameHeaderFiles/PlayerResources.h CatGame/CatGameCPPFiles/PlayerResources.cpp CatGame/CatGameHeaderFiles/KittenNeeds.h
        CatGame/CatGameCPPFiles/KittenNeeds.cpp
        CatGame/SpawningHeaderFiles/Spawner.h CatGame/SpawningCPPFiles/Spawner.cpp CatGame/FSMHeaderFiles/KittenFSM.h CatGame/FSMCPPFiles/KittenFSM.cpp CatGame/FSMHeaderFiles/KittenFSMHandler.h CatGame/FSMCPPFiles/KittenFSMHandler.cpp CatGame/FSMHeaderFiles/WolfFSM.h CatGame/FSMCPPFiles/WolfFSM.cpp CatGame/FSMHeaderFiles/WolfFSMHandler.h CatGame/FSMCPPFiles/WolfFSMHandler.cpp CatGame/CatGameHeaderFiles/Wolf.h CatGame/CatGameCPPFiles/Wolf.cpp)


target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
target_link_libraries(${PROJECT_NAME} SDL2_image)
target_link_libraries(${PROJECT_NAME} SDL2_ttf)
target_link_libraries(${PROJECT_NAME} SDL2_mixer)