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
    mMotherCat->Parent(this);
    mMotherCat->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
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

        if(InputManager::Instance()->MouseButtonDown(SDL::InputManager::left)){

            Vector2 mousePos = Vector2(InputManager::Instance()->MousePos());
            std::cout << "Mother cat new pos: " << mousePos.x << ", " << mousePos.y << "\n";
            GridLocation destination = {(int) mousePos.x, (int) mousePos.y};

            GridLocation mMotherCatLocation = { (int) mMotherCat->Pos(world).x, (int) mMotherCat->Pos(world).y};

            std::unordered_map<GridLocation, GridLocation> came_from;
            std::unordered_map<GridLocation, double> cost_so_far;

            Pathfinding::Instance()->FindPath(mGrid, mMotherCatLocation, destination, came_from, cost_so_far);
            path = Pathfinding::Instance()->ReconstructPath(mMotherCatLocation, destination, came_from);

            for(GridLocation node : path){

                Vector2 newPos = Vector2(node.locationX, node.locationY);
                std::cout << "Mother current pos: " << node.locationX << ", " << node.locationY << "\n";

                mMotherCat->Translate(newPos, world);
                mMotherCat->Move(newPos);

                Render();
            }

            path.clear();
            came_from.clear();
            cost_so_far.clear();
        }
    }
    else{

        mGameStartTimer += mTimer->DeltaTime();
        if(mGameStartTimer >= mGameStartDelay){

            StartGame();
        }
    }
}

void PlayScreen::Render() {

    // mBackground->Render();

    if(mGameStarted){

        mMotherCat->Render();

        GridLocation mMotherCatLocation = { (int) mMotherCat->Pos(world).x, (int) mMotherCat->Pos(world).y};
        mGrid->Render(mMotherCatLocation, path);
    }
}

