//
// Created by Arttu Paldán on 11/05/2021.
//

#ifndef SDLTUTORIAL_GAMEMANAGER_H
#define SDLTUTORIAL_GAMEMANAGER_H

#include "AudioManager.h"
#include "Timer.h"
#include "InputManager.h"

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

        Timer* mTimer;

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
    };
}

#endif
