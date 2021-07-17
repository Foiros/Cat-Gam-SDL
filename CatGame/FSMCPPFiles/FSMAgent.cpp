//
// Created by arttu on 21/05/2021.
//

#include "../FSMHeaderFiles/FSMAgent.h"


FSM::FSMAgent::FSMAgent() {

    mFSM = new FSM(FSM::States::Idle);

    mTimer = Timer::Instance();

    actionTimer = 0.0f;
    actionEndTime = 1.0f;
}

FSM::FSMAgent::~FSMAgent() {

    delete mFSM;
    mFSM = nullptr;
}

void FSM::FSMAgent::CheckState(KittenNeeds* needs, Nest* nest, PathfindingGrid* grid, std::vector<Vector2*> trees, std::vector<Vector2*> flowers, std::vector<Vector2*> mice) {

    if (needs->GetNeed(0) <= 75 && nest->GetResource("Meat") > 0)
        mFSM->SetState(FSM::States::Hungry);

    if(needs->GetNeed(1) <= 75 && nest->GetResource("Water") > 0)
        mFSM->SetState(FSM::States::Thirsty);


    if(mFSM->CurrentState() == FSM::States::Idle){

        SetAction();
        ChooseAction(needs, nest, grid, trees, flowers, mice);
    }
    else
        ChooseAction(needs, nest, grid, trees, flowers, mice);
}

void FSM::FSMAgent::SetAction() {

    int randomNumber = rand() % 4;

    switch (randomNumber) {

        case 1:
            mFSM->SetState(FSM::States::NeedToScratch);
            break;

        case 2:
            mFSM->SetState(FSM::States::Curious);
            break;

        case 3:
            mFSM->SetState(FSM::States::Playful);
            break;
    }
}

void FSM::FSMAgent::ChooseAction(KittenNeeds* needs, Nest* nest, PathfindingGrid* grid, std::vector<Vector2*> trees, std::vector<Vector2*> flowers, std::vector<Vector2*> mice) {

    if(mDoingAction && !mFollowingPath){

        DoAction(needs, nest, grid, trees, flowers, mice);
    }
    else if(mFollowingPath && !mDoingAction){

        PathfindingUnit::FollowPath(path);
    }
    else if(!mFollowingPath && !mDoingAction){

        destination = SetDestination(trees, flowers, mice);

        PathfindingUnit::FindPath(grid, destination);
    }
}

GridLocation FSM::FSMAgent::SetDestination(std::vector<Vector2*> trees, std::vector<Vector2*> flowers, std::vector<Vector2*> mice) {

    int locationIndexTrees = rand() % trees.size();
    int locationIndexFlowers = rand() % flowers.size();
    int locationIndexMice = rand() % mice.size();

    switch (mFSM->CurrentState()) {

        case FSM::States::NeedToScratch:
            destination = { (int) trees[locationIndexTrees]->x, (int) trees[locationIndexTrees]->y };
            break;

        case FSM::States::Curious:
            destination = { (int) flowers[locationIndexFlowers]->x, (int) flowers[locationIndexFlowers]->y };
            break;

        case FSM::States::Playful:
            destination = { (int) mice[locationIndexMice]->x, (int) mice[locationIndexMice]->y };
            break;

        case FSM::States::Hungry:
            destination = { 810, 510};
            break;

        case FSM::States::Thirsty:
            destination = {810, 540};
            break;
    }

    return destination;
}

void FSM::FSMAgent::DoAction(KittenNeeds* needs, Nest* nest, PathfindingGrid* grid, std::vector<Vector2*> trees, std::vector<Vector2*> flowers, std::vector<Vector2*> mice) {

    switch (mFSM->CurrentState()) {

        case FSM::States::Idle:
            mDoingAction = false;
            CheckState(needs, nest, grid, trees, flowers, mice);
            break;

        case FSM::States::NeedToScratch:
            ActionScratchTree(needs, grid);
            break;

        case FSM::States::Curious:
            ActionStudy(needs, grid);
            break;

        case FSM::States::Playful:
            ActionPlay(needs, grid);
            break;

        case FSM::States::Hungry:
            ActionEat(needs, nest, grid);
            break;

        case FSM::States::Thirsty:
            ActionDrink(needs, nest, grid);
            break;
    }
}

void FSM::FSMAgent::ActionScratchTree(KittenNeeds* needs, PathfindingGrid* grid) {

    actionTimer += mTimer->DeltaTime();
    if(actionTimer >= actionEndTime){

        needs->ReduceNeed(0, 0);
        needs->ReduceNeed(1, 0);
        needs->IncreaseNeed(2, 0);

        mFSM->SetState(FSM::States::Idle);
        mDoingAction = false;
    }
}

void FSM::FSMAgent::ActionStudy(KittenNeeds* needs, PathfindingGrid* grid) {

    actionTimer += mTimer->DeltaTime();
    if(actionTimer >= actionEndTime){

        needs->ReduceNeed(0, 0);
        needs->ReduceNeed(1, 0);
        needs->IncreaseNeed(2, 0);

        mFSM->SetState(FSM::States::Idle);
        mDoingAction = false;
    }
}

void FSM::FSMAgent::ActionPlay(KittenNeeds* needs, PathfindingGrid* grid) {

    actionTimer += mTimer->DeltaTime();
    if(actionTimer >= actionEndTime){

        needs->ReduceNeed(0, 0);
        needs->ReduceNeed(1, 0);
        needs->IncreaseNeed(2, 0);

        mFSM->SetState(FSM::States::Idle);
        mDoingAction = false;
    }
}

void FSM::FSMAgent::ActionEat(KittenNeeds* needs, Nest* nest,PathfindingGrid* grid) {

    actionTimer += mTimer->DeltaTime();
    if(actionTimer >= actionEndTime){

        nest->UseResources(10, 0);
        needs->IncreaseNeed(0, 10);
        mFSM->SetState(FSM::States::Idle);
        mDoingAction = false;
    }
}

void FSM::FSMAgent::ActionDrink(KittenNeeds* needs, Nest* nest, PathfindingGrid* grid) {

    actionTimer += mTimer->DeltaTime();
    if(actionTimer >= actionEndTime){

        nest->UseResources(0, 10);
        needs->IncreaseNeed(1, 10);
        mFSM->SetState(FSM::States::Idle);
        mDoingAction = false;
    }
}

void FSM::FSMAgent::ActionHateMom(KittenNeeds* needs, PathfindingGrid* grid) {

}

FSM::FSM* FSM::FSMAgent::GetFSM() {

    return mFSM;
}
