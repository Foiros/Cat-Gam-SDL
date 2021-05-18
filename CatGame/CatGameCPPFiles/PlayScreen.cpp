//
// Created by arttu on 17/05/2021.
//

#include "../CatGameHeaderFiles/PlayScreen.h"


PlayScreen::PlayScreen() {

    mTimer = Timer::Instance();
    mInputManager = InputManager::Instance();
    mAudio = AudioManager::Instance();

    mGameStartTimer = 0.0f;
    mGameStartDelay = 1.0f;
    mGameStarted = false;

    mBackground = new Texture("LevelBackground.png");
    mBackground->Parent(this);
    mBackground->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
    mBackground->Scale(Vector2(1620.0f, 1080.0f));

    mGrid = new PathfindingGrid(1620.0f, 1080.0f);

    mMotherCat = new MotherCat();
}

PlayScreen::~PlayScreen() {

    mTimer = nullptr;
    mInputManager = nullptr;

    delete mBackground;
    mBackground = nullptr;

    delete mGrid;
    mGrid = nullptr;
}

void PlayScreen::StartGame() {

    mMotherCat->Visible(true);
    mGameStarted = true;
    mGameStartTimer = 0.0f;
}

bool PlayScreen::GameOver() {

    if(!mGameStarted)
        return false;
}

void PlayScreen::Update() {

    if(mGameStarted){


    }
    else{

        mGameStartTimer += mTimer->DeltaTime();
        if(mGameStartTimer >= mGameStartDelay){

            StartGame();
        }
    }
}

void PlayScreen::Render() {

    mBackground->Render();

    if(mGameStarted)
        mMotherCat->Render();

    if(mMotherCat->Active() && mGameStarted)
        mGrid->Render();
}

