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

        mGameEndTimer = 0.0f;
        mGameEndDelay = 4.0f;
        mGameOver = false;

        mResourcesAddedToNest = false;

        wolfActive = false;
        mWolfTimer = 0.0f;
        mWolfTimer = 4.0f;

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

        for(auto & meat : mMeat){

            delete meat;
            meat = nullptr;
        }

        for(auto & water : mWater){

            delete water;
            water = nullptr;
        }

        for(auto & tree : trees){

            delete tree;
            tree = nullptr;
        }

        for(auto & flower : flowers){

            delete flower;
            flower = nullptr;
        }

        for(auto & mouse : mice){

            delete mouse;
            mouse = nullptr;
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

    void PlayScreen::GameOver() {

        if(mKittenNeeds->GetGrownUp()){

            victoryText = new Texture("Kitten grew up, you won!", "ARCADE_N.ttf", 20, {150, 0, 0});
            Spawning::Spawner::SpawnOne(Vector2(1000, 500), victoryText, this);

            mGameEndTimer += mTimer->DeltaTime();
            if(mGameEndTimer >= mGameEndDelay){

                mGameOver = true;
            }
        }
        else if(mKittenNeeds->GetHatesMom()){

            gameOverText = new Texture("Kitten doesn't love you anymore and goes to search for a new mom",
                                           "ARCADE_N.ttf", 20, {150, 0, 0});
            Spawning::Spawner::SpawnOne(Vector2(1000, 500), gameOverText, this);


            mGameEndTimer += mTimer->DeltaTime();
            if(mGameEndTimer >= mGameEndDelay){

                mGameOver = true;
            }
        }
    }

    void PlayScreen::HandleResources() {

        mResourcesAddedToNest = mNest->GetMotherVisited();

        for (int i = 0; i < mMeat.size(); i++) {

            if(mMeat[i] != nullptr){

                if(mMeat[i]->GetGathered()) {

                    if (mPlayerResources->GetResource("Meat") < 100){

                        mPlayerResources->AddResources(mMeat[i]->GetValue(), 0);
                        mMeat[i] = nullptr;
                        mMeat.erase(mMeat.begin() + i);
                        meatAmount--;
                    }
                    else
                        mMeat[i]->GatherResource();
                }
                else if(mMeat[i]->GetDestroyed()){

                    mMeat[i] = nullptr;
                    mMeat.erase(mMeat.begin() + i);
                    meatAmount--;
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
                else if(mWater[i]->GetDestroyed()){

                    mWater[i] = nullptr;
                    mWater.erase(mWater.begin() + i);
                    waterAmount--;
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

    void PlayScreen::WolfSpawning() {

        if(!wolfActive){

            mWolfTimer += mTimer->DeltaTime();
            if(mWolfTimer >= mWolfDelay){

                wolfActive = true;
                Spawning::Spawner::SpawnOne(Vector2(850, 540), mWolf, this);
                mWolf->Visible(true);
                mWolfTimer = 0.0f;
            }
        }
        else{

            float kittenX = mKitten->Pos().x;
            float kittenY = mKitten->Pos().y;
            auto* kittenLocation = new Vector2(kittenX, kittenY);
            mWolf->Update(kittenLocation);
        }
    }

    void PlayScreen::Update() {

        if(mGameStarted){

            HandleResources();
            UpdateTexts();
            mMotherCat->Update();
            mNest->Update();
            mKitten->Update();
            WolfSpawning();
            GameOver();
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

            if(wolfActive)
                mWolf->Render();


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

            for(auto & tree : trees){

                if(tree != nullptr){

                    tree->Render();
                }
            }

            for(auto & flower : flowers){

                if(flower != nullptr){

                    flower->Render();
                }
            }

            for(auto & mouse : mice){

                if(mouse != nullptr){

                    mouse->Render();
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

        for (int i = 0; i < 3; i++){

            trees.push_back(new Tree());
            flowers.push_back(new Flower());
            mice.push_back((new Mouse()));
        }

        Spawning::Spawner::SpawnTrees(mGrid, trees, this);
        Spawning::Spawner::SpawnFlowers(mGrid, flowers, this);
        Spawning::Spawner::SpawnMice(mGrid, mice, this);

        for(auto & tree : trees){

            treeLocations.push_back(new Vector2(tree->Pos().x, tree->Pos().y));
        }

        for(auto & flower : flowers){

            flowerLocations.push_back(new Vector2(flower->Pos().x, flower->Pos().y));
        }

        for(auto & mouse : mice){

            miceLocations.push_back(new Vector2(mouse->Pos().x, mouse->Pos().y));
        }

        for(auto & meat : mMeat){

            meatLocations.push_back(new Vector2(meat->Pos().x, meat->Pos().y));
        }

        for(auto & water : mWater){

            waterLocations.push_back(new Vector2(water->Pos().x, water->Pos().y));
        }

        mKitten = new Kitten(mGrid, mKittenNeeds, mNest, mTimer, treeLocations, flowerLocations, miceLocations);
        Spawning::Spawner::SpawnOne(Vector2(200, 200), mKitten, this);

        mWolf = new Wolf(mGrid, mKittenNeeds, mNest, mTimer, meatLocations, waterLocations, mMeat, mWater);
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

    bool PlayScreen::ReturnGameOver() const { return mGameOver; }
}
