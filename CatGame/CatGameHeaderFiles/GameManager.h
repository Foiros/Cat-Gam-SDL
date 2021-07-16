//
// Created by Arttu Paldán on 11/05/2021.
//

#ifndef SDLTUTORIAL_GAMEMANAGER_H
#define SDLTUTORIAL_GAMEMANAGER_H

#include "../SDLHeaderFiles/AudioManager.h"
#include "../SDLHeaderFiles/Timer.h"
#include "../SDLHeaderFiles/InputManager.h"
#include "../CatGameHeaderFiles/PlayScreen.h"
#include "../PhysicsEngineHeaderFiles/PhysicsManager.h"

using namespace CatGame;
using namespace PhysicsEngine;

namespace SDL{

    class GameManager {

        // Variables
    private:

        static GameManager* sInstance;

        const int FRAME_RATE = 120;

        bool mQuit;
        Graphics* mGraphics;
        AssetManager* mAssetManager;
        InputManager* mInputManager;
        AudioManager* mAudioManager;
        PhysicsManager* mPhysicsManager;
        Timer* mTimer;

        PlayScreen* mPlayScreen;

        SDL_Event mEvents;

        // Functions
    public:

        static GameManager* Instance();
        static void Release();

        void Run();

    private:

        GameManager();
        ~GameManager();

        void EarlyUpdate();
        void Update();
        void LateUpdate();

        void Render();

        void EndGame();
    };
}

#endif
