//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_PLAYSCREEN_H
#define CATGAMESDL_PLAYSCREEN_H

#include "../SDLHeaderFiles/GameEntity.h"
#include "../SDLHeaderFiles/Timer.h"
#include "../SDLHeaderFiles/InputManager.h"
#include "../SDLHeaderFiles/AudioManager.h"
#include "../SDLHeaderFiles/Texture.h"
#include "../CatGameHeaderFiles/MotherCat.h"
#include "../CatGameHeaderFiles/Kitten.h"
#include "../PathfindingHeaderFiles/PathfindingGrid.h"
#include "../PathfindingHeaderFiles/Pathfinding.h"
#include "../CatGameHeaderFiles/Meat.h"
#include "../CatGameHeaderFiles/Water.h"
#include "../CatGameHeaderFiles/Nest.h"
#include "../CatGameHeaderFiles/PlayerResources.h"
#include "../CatGameHeaderFiles/KittenNeeds.h"
#include "../FSMHeaderFiles/FSM.h"
#include "../SpawningHeaderFiles/Spawner.h"
#include "../CatGameHeaderFiles/Tree.h"
#include "../CatGameHeaderFiles/Mouse.h"
#include "../CatGameHeaderFiles/Flower.h"

#include <vector>
#include <map>

using namespace SDL;
using namespace Spawning;

namespace CatGame{

    class PlayScreen : public GameEntity{

    private:
        Timer* mTimer;
        InputManager* mInputManager;
        AudioManager* mAudio;
        Spawner* mSpawner;

        float mGameStartTimer;
        float mGameStartDelay;
        bool mGameStarted;

        float mGameEndTimer;
        float mGameEndDelay;
        bool mGameOver;

        bool mResourcesAddedToNest;

        Texture* mBackground;
        Texture* mPlayerMeat;
        Texture* mPlayerWater;
        Texture* mNestMeat;
        Texture* mNestWater;
        Texture* mKittenHunger;
        Texture* mKittenThirst;
        Texture* mKittenLove;
        Texture* victoryText;
        Texture* gameOverText;

        PathfindingGrid* mGrid;

        MotherCat* mMotherCat;
        Kitten* mKitten;
        Nest* mNest;

        std::vector<Meat*> mMeat;
        std::vector<Water*> mWater;

        std::vector<Tree*> trees;
        std::vector<Flower*> flowers;
        std::vector<Mouse*> mice;

        std::vector<Vector2*> treeLocations, flowerLocations, miceLocations;

        const int maxResources = 5;
        int meatAmount, waterAmount;

        PlayerResources* mPlayerResources;
        KittenNeeds* mKittenNeeds;


    private:
        void SetUpPlayScreen();
        void SetUpGrid();
        void SetUpGameObjects();

        void StartGame();
        void GameOver();

        void HandleResources();
        void UpdateTexts();
        void RefillResources();

    public:
        PlayScreen();
        ~PlayScreen();

        void Update();
        void Render();

        bool ReturnGameOver();
    };

}

#endif //CATGAMESDL_PLAYSCREEN_H
