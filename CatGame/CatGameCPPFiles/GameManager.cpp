//
// Created by Arttu Paldán on 11/05/2021.
//

#include "../CatGameHeaderFiles/GameManager.h"

using namespace CatGame;

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

        mPhysicsManager = PhysicsManager::Instance();

        // Mother's collision settings
        mPhysicsManager->SetLayerCollisionMask(PhysicsManager::CollisionLayers::MotherCat, PhysicsManager::CollisionFlags::Nest
        | PhysicsManager::CollisionFlags::Meat | PhysicsManager::CollisionFlags::Water | PhysicsManager::CollisionFlags::Wolf |
        PhysicsManager::CollisionFlags::Kitten);

        //Nest's collision settings
        mPhysicsManager->SetLayerCollisionMask(PhysicsManager::CollisionLayers::Nest, PhysicsManager::CollisionFlags::MotherCat
        | PhysicsManager::CollisionFlags::Kitten);

        // Meat's collision settings
        mPhysicsManager->SetLayerCollisionMask(PhysicsManager::CollisionLayers::Meat, PhysicsManager::CollisionFlags::MotherCat);

        // Water's collision settings
        mPhysicsManager->SetLayerCollisionMask(PhysicsManager::CollisionLayers::Water, PhysicsManager::CollisionFlags::MotherCat);

        // Kitten's collision settings
        mPhysicsManager->SetLayerCollisionMask(PhysicsManager::CollisionLayers::Kitten, PhysicsManager::CollisionFlags::Activity
        | PhysicsManager::CollisionFlags::Nest | PhysicsManager::CollisionFlags::Wolf | PhysicsManager::CollisionFlags::MotherCat);

        // Activity's collision settings
        mPhysicsManager->SetLayerCollisionMask(PhysicsManager::CollisionLayers::Activity, PhysicsManager::CollisionFlags::Kitten);

        // Wolf's collision settings
        mPhysicsManager->SetLayerCollisionMask(PhysicsManager::CollisionLayers::Wolf, PhysicsManager::CollisionFlags::Kitten
        | PhysicsManager::CollisionFlags::MotherCat);

        mPlayScreen = new PlayScreen();
    }

    GameManager::~GameManager() {

        PhysicsManager::Release();
        mPhysicsManager = nullptr;

        AudioManager::Release();
        mAudioManager = nullptr;

        AssetManager::Release();
        mAssetManager = nullptr;

        Graphics::Release();
        mGraphics = nullptr;

        Timer::Release();
        mTimer = nullptr;
    }

    void GameManager::EarlyUpdate() {

        mInputManager->Update();
    }

    void GameManager::Update() {

        mPlayScreen->Update();
    }

    void GameManager::LateUpdate() {

        mPhysicsManager->Update();
        mInputManager->UpdatePrevInput();
        mTimer->Reset();
        EndGame();
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

    void GameManager::EndGame() {

        if(mPlayScreen->ReturnGameOver()){

            SDL_Quit();
        }
    }
}