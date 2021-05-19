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

    PathfindingGrid* mGrid;

    MotherCat* mMotherCat;


public:
    PlayScreen();
    ~PlayScreen();

    void StartGame();

    bool GameOver();

    void Update();

    void Render();
};

#endif //CATGAMESDL_PLAYSCREEN_H
