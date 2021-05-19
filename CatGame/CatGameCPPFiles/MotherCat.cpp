//
// Created by arttu on 17/05/2021.
//

#include "../CatGameHeaderFiles/MotherCat.h"

MotherCat::MotherCat() {

    mTimer = Timer::Instance();
    mInputManager = InputManager::Instance();
    mAudioManager = AudioManager::Instance();

    mVisible = false;
    mAnimating = false;

    mMoveSpeed = 300.0f;

    mMotherSprite = new Texture("MotherCat.png");
    mMotherSprite->Parent(this);

    mRunAnimation = new AnimatedTexture("MotherCatWalkAnimation.png", 0, 0, 100, 100, 4, 1.0f, AnimatedTexture::horizontal);
    mRunAnimation->Parent(this);
    mRunAnimation->WrapMode(AnimatedTexture::once);

    mFollowingPath = false;
}

MotherCat::~MotherCat() {

    mTimer = nullptr;
    mInputManager = nullptr;
    mAudioManager = nullptr;

    delete mMotherSprite;
    mMotherSprite = nullptr;

    delete mRunAnimation;
    mRunAnimation = nullptr;
}

void MotherCat::Move(PathfindingGrid* mGrid) {

//    Vector2 mousePos = Vector2(InputManager::Instance()->MousePos());
//    GridLocation destination = {(int) mousePos.x, (int) mousePos.y};
    printf("Finding a path...");
    int random1 = rand() % (mGrid->width - 1);
    int random2 = rand() % (mGrid->height -1);
    std::cout << random1 << ", " << random2;
    destination = { random1, random2};

    GridLocation mMotherCatLocation = { (int) mMotherSprite->Pos(local).x, (int) mMotherSprite->Pos(local).y};

    std::unordered_map<GridLocation, GridLocation> came_from;
    std::unordered_map<GridLocation, double> cost_so_far;

    Pathfinding::Instance()->FindPath(mGrid, mMotherCatLocation, destination, came_from, cost_so_far);
    path = Pathfinding::Instance()->ReconstructPath(mMotherCatLocation, destination, came_from);

    mFollowingPath = true;

    came_from.clear();
    cost_so_far.clear();
}

void MotherCat::FollowPath(std::vector<GridLocation> path) {

    GridLocation node = {path.begin()->locationX, path.begin()->locationY};
    path.erase(path.begin());
    this->path = path;
    Vector2 newPos = Vector2(node.locationX, node.locationY);
    mMotherSprite->Translate(newPos, world);

    if(node == destination){

        mFollowingPath = false;
        path.clear();
        printf("Path traversed!");
    }
}

void MotherCat::Visible(bool visible) {

    mVisible = visible;
}

bool MotherCat::IsAnimating() {

    return mAnimating;
}

void MotherCat::Update(PathfindingGrid* mGrid) {

    if(!mFollowingPath){

        Move(mGrid);
    }
    else if(mFollowingPath){

        FollowPath(path);
    }
}

void MotherCat::Render() {

    if(mVisible)
        mMotherSprite->Render();
}




