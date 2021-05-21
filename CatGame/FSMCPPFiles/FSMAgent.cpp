//
// Created by arttu on 21/05/2021.
//

#include "../FSMHeaderFiles/FSMAgent.h"

namespace FSM{

    FSMAgent::FSMAgent() {

        mFSM = new FSM(FSM::States::Idle);

        mTimer = Timer::Instance();

        actionTimer = 0.0f;
        actionEndTime = 1.0f;
    }

    FSMAgent::~FSMAgent() {

        delete mFSM;
        mFSM = nullptr;
    }

    void FSMAgent::CheckState(KittenNeeds* needs, Nest* nest, PathfindingGrid* grid) {

        if (needs->GetNeed(0) <= 75 && nest->GetResource("Meat") > 0)
            mFSM->SetState(FSM::States::Hungry);

        if(needs->GetNeed(1) <= 75 && nest->GetResource("Water") > 0)
            mFSM->SetState(FSM::States::Thirsty);


        if(mFSM->CurrentState() == FSM::States::Idle){

            SetAction();
            ChooseAction(needs, nest, grid);
        }
        else
            ChooseAction(needs, nest, grid);
    }

    void FSMAgent::SetAction() {

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

    void FSMAgent::ChooseAction(KittenNeeds* needs, Nest* nest, PathfindingGrid* grid) {

        if(mDoingAction && !mFollowingPath){

            DoAction(needs, nest, grid);
        }
        else if(mFollowingPath && !mDoingAction){

            PathfindingUnit::FollowPath(path);
        }
        else if(!mFollowingPath && !mDoingAction){

            destination = SetDestination();

            PathfindingUnit::FindPath(grid);
        }
    }

    GridLocation FSMAgent::SetDestination() {

        switch (mFSM->CurrentState()) {

            case FSM::States::NeedToScratch:
                destination = {300, 200};
                break;

            case FSM::States::Curious:
                destination = {-300, 220};
                break;

            case FSM::States::Playful:
                destination = {500, 40};
                break;

            case FSM::States::Hungry:
                destination = {810, 510};
                break;

            case FSM::States::Thirsty:
                destination = {810, 540};
                break;
        }

        return destination;
    }

    void FSMAgent::DoAction(KittenNeeds* needs, Nest* nest, PathfindingGrid* grid) {

        switch (mFSM->CurrentState()) {

            case FSM::States::Idle:
                mDoingAction = false;
                CheckState(needs, nest, grid);
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
                ActionEat(needs, grid);
                break;

            case FSM::States::Thirsty:
                ActionDrink(needs, grid);
                break;
        }
    }

    void FSMAgent::ActionScratchTree(KittenNeeds* needs, PathfindingGrid* grid) {

        actionTimer += mTimer->DeltaTime();
        if(actionTimer >= actionEndTime){

            needs->ReduceNeed(0);
            needs->ReduceNeed(1);

            mFSM->SetState(FSM::States::Idle);
            mDoingAction = false;
        }
    }

    void FSMAgent::ActionStudy(KittenNeeds* needs, PathfindingGrid* grid) {

        actionTimer += mTimer->DeltaTime();
        if(actionTimer >= actionEndTime){

            needs->ReduceNeed(0);
            needs->ReduceNeed(1);

            mFSM->SetState(FSM::States::Idle);
            mDoingAction = false;
        }
    }

    void FSMAgent::ActionPlay(KittenNeeds* needs, PathfindingGrid* grid) {

        actionTimer += mTimer->DeltaTime();
        if(actionTimer >= actionEndTime){

            needs->ReduceNeed(0);
            needs->ReduceNeed(1);

            mFSM->SetState(FSM::States::Idle);
            mDoingAction = false;
        }
    }

    void FSMAgent::ActionEat(KittenNeeds* needs, PathfindingGrid* grid) {

        actionTimer += mTimer->DeltaTime();
        if(actionTimer >= actionEndTime){

            mFSM->SetState(FSM::States::Idle);
            mDoingAction = false;
        }
    }

    void FSMAgent::ActionDrink(KittenNeeds* needs, PathfindingGrid* grid) {

        actionTimer += mTimer->DeltaTime();
        if(actionTimer >= actionEndTime){

            mFSM->SetState(FSM::States::Idle);
            mDoingAction = false;
        }
    }

    void FSMAgent::ActionHateMom(KittenNeeds* needs, PathfindingGrid* grid) {

    }

    FSM* FSMAgent::GetFSM() {

        return mFSM;
    }
}
