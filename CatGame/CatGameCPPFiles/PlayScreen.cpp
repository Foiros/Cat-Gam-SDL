//
// Created by arttu on 17/05/2021.
//

#include "../CatGameHeaderFiles/PlayScreen.h"

namespace CatGame{

    PlayScreen::PlayScreen() {

        mTimer = Timer::Instance();
        mInputManager = InputManager::Instance();
        mAudio = AudioManager::Instance();
        mSpawner = Spawner::Instance();

        mGameStartTimer = 0.0f;
        mGameStartDelay = 1.0f;
        mGameStarted = false;

        mResourcesAddedToNest = false;
        mResourcesTakenFromNest = false;

        SetUpPlayScreen();
        SetUpGrid();
        SetUpGameObjects();
    }

    PlayScreen::~PlayScreen() {

        mTimer = nullptr;
        mInputManager = nullptr;
        mAudio = nullptr;
        mSpawner = nullptr;

        delete mBackground;
        mBackground = nullptr;

        delete mGrid;
        mGrid = nullptr;

        delete mMotherCat;
        mMotherCat = nullptr;

        delete mKitten;
        mKitten = nullptr;

        delete mNest;
        mNest = nullptr;

        for(int i = 0; i < mMeat.size(); i++){

            delete mMeat[i];
            mMeat[i] = nullptr;
        }

        for(int i = 0; i < mWater.size(); i++){

            delete mWater[i];
            mWater[i] = nullptr;
        }

        delete mPlayerResources;
        mPlayerResources = nullptr;

        delete mKittenNeeds;
        mKittenNeeds = nullptr;
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

    void PlayScreen::HandleResources() {

        mResourcesAddedToNest = mNest->GetMotherVisited();
        mResourcesTakenFromNest = mNest->GetKittenVisited();

        for (int i = 0; i < mMeat.size(); i++) {

            if(mMeat[i] != nullptr){

                if(mMeat[i]->GetGathered()) {

                    if (mPlayerResources->GetResource("Meat") < 100){

                        mPlayerResources->AddResources(mMeat[i]->GetValue(), 0);
                        // mMeat[i] = nullptr;
                        mMeat.erase(mMeat.begin() + i);
                        meatAmount--;
                    }
                    else
                        mMeat[i]->GatherResource();
                }
            }
        }

        for (int i = 0; i < mWater.size(); i++) {

            if(mWater[i] != nullptr){

                if(mWater[i]->GetGathered()) {

                    if (mPlayerResources->GetResource("Water") < 100){

                        mPlayerResources->AddResources(0, mWater[i]->GetValue());
                        mWater[i] = nullptr;
                        mWater.erase(mWater.begin() + i);
                        waterAmount--;
                    }
                    else
                        mWater[i]->GatherResource();
                }
            }
        }


        if(mResourcesAddedToNest){

            int addedMeat = mPlayerResources->GetResource("Meat");
            int addedWater = mPlayerResources->GetResource("Water");

            mNest->AddResourcesToNest(addedMeat, addedWater);
            mPlayerResources->ReduceResources(addedMeat, addedWater);

            mResourcesAddedToNest = false;
        }

        if(mResourcesTakenFromNest){

            mNest->UseResources(reduceAmount, reduceAmount);
            mKittenNeeds->IncreaseNeed(0, reduceAmount);
            mKittenNeeds->IncreaseNeed(1, reduceAmount);
            mResourcesTakenFromNest = false;
        }

        RefillResources();
    }

    void PlayScreen::UpdateTexts() {

        std::string newPlayerMeat = "Player Meat: " + std::to_string(mPlayerResources->GetResource("Meat"));
        std::string newPlayerWater = "Player Water: " + std::to_string(mPlayerResources->GetResource("Water"));
        std::string newNestMeat = "Nest Meat: " + std::to_string(mNest->GetResource("Meat"));
        std::string newNestWater = "Nest Water: " + std::to_string(mNest->GetResource("Water"));
        std::string newKittenHunger = "Kitten Hunger: " + std::to_string(mKittenNeeds->GetNeed(0));
        std::string newKittenThirst = "Kitten Thirst: " + std::to_string(mKittenNeeds->GetNeed(1));
        std::string newKittenLove = "Kitten Love: " + std::to_string(mKittenNeeds->GetNeed(2));

        mPlayerMeat = new Texture(newPlayerMeat, "ARCADE_N.ttf", 20, {150, 0, 0});
        mPlayerMeat->Pos(Vector2(200, 50));

        mPlayerWater = new Texture(newPlayerWater, "ARCADE_N.ttf", 20, {150, 0, 0});
        mPlayerWater->Pos(Vector2(200, 100));

        mNestMeat = new Texture(newNestMeat, "ARCADE_N.ttf", 20, {150, 0, 0});
        mNestMeat->Pos(Vector2(200, 150));

        mNestWater = new Texture(newNestWater, "ARCADE_N.ttf", 20, {150, 0, 0});
        mNestWater->Pos(Vector2(200, 200));

        mKittenHunger = new Texture(newKittenHunger, "ARCADE_N.ttf", 20, {150, 0, 0});
        mKittenHunger->Pos(Vector2(1400, 50));

        mKittenThirst = new Texture(newKittenThirst, "ARCADE_N.ttf", 20, {150, 0, 0});
        mKittenThirst->Pos(Vector2(1400, 100));

        mKittenLove = new Texture(newKittenLove, "ARCADE_N.ttf", 20, {150, 0, 0});
        mKittenLove->Pos(Vector2(1400, 150));
    }

    void PlayScreen::Update() {

        if(mGameStarted){

            HandleResources();
            UpdateTexts();
            mMotherCat->Update();
            mKitten->Update(mKittenNeeds, mNest, mGrid);
            mNest->Update();
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


            for(auto & meat : mMeat){

                if(meat != nullptr){

                    meat->Render();
                }
            }

            for(auto & water : mWater){

                if(water != nullptr){

                    water->Render();
                }
            }
        }
    }

    void PlayScreen::SetUpPlayScreen() {

        mBackground = new Texture("LevelBackground.png");
        Spawning::Spawner::SpawnOne(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f), mBackground, this);
        mBackground->Scale(Vector2(1620.0f, 1080));

        mPlayerMeat = new Texture("Player Meat: 0", "ARCADE_N.ttf", 20, {150, 0, 0});
        Spawning::Spawner::SpawnOne(Vector2(200, 50), mPlayerMeat, this);

        mPlayerWater = new Texture("Player Water: 0", "ARCADE_N.ttf", 20, {150, 0, 0});
        Spawning::Spawner::SpawnOne(Vector2(200, 100), mPlayerWater, this);

        mNestMeat = new Texture("Nest Meat: 0", "ARCADE_N.ttf", 20, {150, 0, 0});
        Spawning::Spawner::SpawnOne(Vector2(200, 150), mNestMeat, this);

        mNestWater = new Texture("Nest Water: 0", "ARCADE_N.ttf", 20, {150, 0, 0});
        Spawning::Spawner::SpawnOne(Vector2(200, 200), mNestWater, this);

        mKittenHunger = new Texture("Kitten Hunger: 100", "ARCADE_N.ttf", 20, {150, 0, 0});
        Spawning::Spawner::SpawnOne(Vector2(1400, 50), mKittenHunger, this);

        mKittenThirst = new Texture("Kitten Thirst: 100", "ARCADE_N.ttf", 20, {150, 0, 0});
        Spawning::Spawner::SpawnOne(Vector2(1400, 100), mKittenThirst, this);

        mKittenLove = new Texture("Kitten Love: 25", "ARCADE_N.ttf", 20, {150, 0, 0});
        Spawning::Spawner::SpawnOne(Vector2(1400, 150), mKittenLove, this);
    }

    void PlayScreen::SetUpGrid() {

        mGrid = new PathfindingGrid(mBackground->Scale(world).x, mBackground->Scale(world).y);
        Spawning::Spawner::SpawnOne(Vector2(), mGrid, this);
    }

    void PlayScreen::SetUpGameObjects() {

        mMotherCat = new MotherCat();
        Spawning::Spawner::SpawnOne(Vector2(300, 300), mMotherCat, this);

        mKitten = new Kitten();
        Spawning::Spawner::SpawnOne(Vector2(200, 200), mKitten, this);

        mNest = new Nest();
        Spawning::Spawner::SpawnOne(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f), mNest, this);

        mPlayerResources = new PlayerResources();
        mKittenNeeds = new KittenNeeds();

        meatAmount = maxResources;
        waterAmount = maxResources;

        for(int i = 0; i < meatAmount; i++){

            mMeat.push_back(new Meat());
            mWater.push_back(new Water());
        }

        Spawning::Spawner::SpawnMeat(mGrid, mMeat, this);
        Spawning::Spawner::SpawnWater(mGrid, mWater, this);
    }

    void PlayScreen::RefillResources() {

        if(meatAmount <= 0){

            for(int i = 0; i < maxResources; i++){

                mMeat.insert(mMeat.begin(), new Meat());
                meatAmount++;
            }

            Spawning::Spawner::SpawnMeat(mGrid, mMeat, this);
        }

        if(waterAmount <= 0){

            for (int i = 0; i < maxResources; ++i) {

                mWater.insert(mWater.begin(), new Water);
                waterAmount++;
            }

            Spawning::Spawner::SpawnWater(mGrid, mWater, this);
        }
    }
}
