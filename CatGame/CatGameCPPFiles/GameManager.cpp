//
// Created by Arttu Paldán on 11/05/2021.
//

#include "../CatGameHeaderFiles/GameManager.h"

namespace SDL{

    GameManager* GameManager::sInstance = NULL;

    GameManager* GameManager::Instance() {

        if(sInstance == NULL){

            sInstance = new GameManager();

            return sInstance;
        }
    }

    void GameManager::Release() {

        delete sInstance;
        sInstance = NULL;
    }

    GameManager::GameManager() {

        mQuit = false;

        mGraphics = Graphics::Instance();

        if(!Graphics::Initialized())
            mQuit = true;

        mAssetManager = AssetManager::Instance();
        mInputManager = InputManager::Instance();
        mAudioManager = AudioManager::Instance();
        mTimer = Timer::Instance();

        mPlayScreen = new PlayScreen();
    }

    GameManager::~GameManager() {

        AudioManager::Release();
        mAudioManager = NULL;

        AssetManager::Release();
        mAssetManager = NULL;

        Graphics::Release();
        mGraphics = NULL;

        Timer::Release();
        mTimer = NULL;
    }

    void GameManager::EarlyUpdate() {

        mInputManager->Update();
    }

    void GameManager::Update() {

        mPlayScreen->Update();
    }

    void GameManager::LateUpdate() {

        mInputManager->UpdatePrevInput();
        mTimer->Reset();
    }

    void GameManager::Render() {

        mGraphics->ClearBackBuffer();
        mPlayScreen->Render();
        mGraphics->Render();
    }

    void GameManager::Run() {

        while (!mQuit){

            mTimer->Update();

            while (SDL_PollEvent(&mEvents) != 0){

                if(mEvents.type == SDL_QUIT){
                    mQuit = true;
                }
            }

            if(mTimer->DeltaTime() >= (1.0f / FRAME_RATE)){

                EarlyUpdate();
                Update();
                LateUpdate();
                Render();
            }
        }
    }
}