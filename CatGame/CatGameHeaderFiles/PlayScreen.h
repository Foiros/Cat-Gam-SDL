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

using namespace SDL;

class PlayScreen : public GameEntity{

private:
    Timer* mTimer;
    InputManager* mInputManager;
    AudioManager* mAudio;

    float mGameStartTimer;
    float mGameStartDelay;
    bool mGameStarted;

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


public:
    PlayScreen();
    ~PlayScreen();

    void SetUpPlayScreen();
    void SetUpGrid();
    void SetUpGameObjects();

    void StartGame();

    bool GameOver();

    void Update();
    void UpdateTexts();

    void Render();
};

#endif //CATGAMESDL_PLAYSCREEN_H
