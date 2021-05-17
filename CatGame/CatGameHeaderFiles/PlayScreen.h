//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_PLAYSCREEN_H
#define CATGAMESDL_PLAYSCREEN_H

#include "../SDLFramework/SDLHeaderFiles/GameEntity.h"
#include "../SDLFramework/SDLHeaderFiles/Timer.h"
#include "../SDLFramework/SDLHeaderFiles/InputManager.h"
#include "../SDLFramework/SDLHeaderFiles/AudioManager.h"
#include "../SDLFramework/SDLHeaderFiles/Texture.h"
#include "../CatGameHeaderFiles/MotherCat.h"

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
