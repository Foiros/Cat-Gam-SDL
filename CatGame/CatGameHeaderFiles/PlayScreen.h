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

using namespace SDL;

namespace CatGame{

    class PlayScreen : public GameEntity{

    private:
        Timer* mTimer;
        InputManager* mInputManager;
        AudioManager* mAudio;

        float mGameStartTimer;
        float mGameStartDelay;
        bool mGameStarted;

        bool mMeatGathered;
        bool mWaterGathered;
        bool mResourcesAddedToNest;
        bool mResourcesTakenFromNest;

        Texture* mBackground;
        Texture* mPlayerMeat;
        Texture* mPlayerWater;
        Texture* mNestMeat;
        Texture* mNestWater;
        Texture* mKittenHunger;
        Texture* mKittenThirst;
        Texture* mKittenLove;

        PathfindingGrid* mGrid;

        MotherCat* mMotherCat;
        Kitten* mKitten;
        Nest* mNest;

        Meat* mMeat;
        Water* mWater;

        PlayerResources* mPlayerResources;
        KittenNeeds* mKittenNeeds;

        const int reduceAmount = 10;

    private:
        void SetUpPlayScreen();
        void SetUpGrid();
        void SetUpGameObjects();

        void StartGame();
        bool GameOver();

        void HandleResources();
        void UpdateTexts();

    public:
        PlayScreen();
        ~PlayScreen();

        void Update();
        void Render();
    };

}

#endif //CATGAMESDL_PLAYSCREEN_H
