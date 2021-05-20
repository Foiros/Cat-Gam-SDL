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

    SetUpPlayScreen();
    SetUpGrid();
    SetUpGameObjects();
}

PlayScreen::~PlayScreen() {

    mTimer = nullptr;
    mInputManager = nullptr;
    mAudio = nullptr;

    delete mBackground;
    mBackground = nullptr;

    delete mGrid;
    mGrid = nullptr;
}

void PlayScreen::StartGame() {

    mMotherCat->Visible(true);
    mKitten->Visible(true);
    mGameStarted = true;
    mGameStartTimer = 0.0f;
}

bool PlayScreen::GameOver() {

    if(!mGameStarted)
        return false;
}

void PlayScreen::Update() {

    if(mGameStarted){

        UpdateTexts();
        mMotherCat->Update();
        mKitten->Update(mGrid);
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

    if(mGameStarted){

        mPlayerMeat->Render();
        mPlayerWater->Render();
        mNestMeat->Render();
        mNestWater->Render();
        mKittenHunger->Render();
        mKittenThirst->Render();
        mKittenLove->Render();

        mMotherCat->Render();
        mKitten->Render();
        mNest->Render();

        mMeat->Render();
        mWater->Render();
    }
}

void PlayScreen::SetUpPlayScreen() {

    mBackground = new Texture("LevelBackground.png");
    mBackground->Parent(this);
    mBackground->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
    mBackground->Scale(Vector2(1620.0f, 1080));

    mPlayerMeat = new Texture("Player Meat: 0", "ARCADE_N.ttf", 20, {150, 0, 0});
    mPlayerMeat->Parent(this);
    mPlayerMeat->Pos(Vector2(200, 50));

    mPlayerWater = new Texture("Player Water: 0", "ARCADE_N.ttf", 20, {150, 0, 0});
    mPlayerWater->Parent(this);
    mPlayerWater->Pos(Vector2(200, 100));

    mNestMeat = new Texture("Nest Meat: 0", "ARCADE_N.ttf", 20, {150, 0, 0});
    mNestMeat->Parent(this);
    mNestMeat->Pos(Vector2(200, 150));

    mNestWater = new Texture("Nest Water: 0", "ARCADE_N.ttf", 20, {150, 0, 0});
    mNestWater->Parent(this);
    mNestWater->Pos(Vector2(200, 200));

    mKittenHunger = new Texture("Kitten Hunger: 100", "ARCADE_N.ttf", 20, {150, 0, 0});
    mKittenHunger->Parent(this);
    mKittenHunger->Pos(Vector2(1400, 50));

    mKittenThirst = new Texture("Kitten Thirst: 100", "ARCADE_N.ttf", 20, {150, 0, 0});
    mKittenThirst->Parent(this);
    mKittenThirst->Pos(Vector2(1400, 100));

    mKittenLove = new Texture("Kitten Love: 25", "ARCADE_N.ttf", 20, {150, 0, 0});
    mKittenLove->Parent(this);
    mKittenLove->Pos(Vector2(1400, 150));
}

void PlayScreen::SetUpGrid() {

    mGrid = new PathfindingGrid(mBackground->Scale(world).x, mBackground->Scale(world).y);
    mGrid->Parent(this);
    mGrid->Pos(Vector2());
}

void PlayScreen::SetUpGameObjects() {

    mMotherCat = new MotherCat();
    mMotherCat->Parent(this);
    mMotherCat->Pos(Vector2(300, 300));

    mKitten = new Kitten();
    mKitten->Parent(this);
    mKitten->Pos(Vector2(200, 200));

    mNest = new Nest();
    mNest->Parent(this);
    mNest->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));

    mMeat = new Meat();
    mMeat->Parent(this);
    mMeat->Pos(Vector2(500.0f, 500.0f));

    mWater = new Water();
    mWater->Parent(this);
    mWater->Pos(Vector2(100.0f, 100.0f));
}

void PlayScreen::UpdateTexts() {

    std::string newText = "100";

    std::string theText = "PlayerMeat: ";

    std::string theWholeThing = theText + newText;

    mPlayerMeat = new Texture(theWholeThing, "ARCADE_N.ttf", 20, {150, 0, 0});
    mPlayerMeat->Pos(Vector2(200, 50));
}

