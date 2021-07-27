//
// Created by arttu on 26/07/2021.
//

#include "../FSMHeaderFiles/WolfFSMHandler.h"


namespace FSM{

    void FSM::WolfFSMHandler::CheckState(FSM::WolfFSM *fsm) {

        if(fsm->CurrentState() == FSM::WolfFSM::States::Idle){

            SetAction(fsm);
            ChooseAction(fsm);
        }
        else
            ChooseAction(fsm);
    }

    void FSM::WolfFSMHandler::SetAction(FSM::WolfFSM* fsm) {

        std::random_device generator;
        std::uniform_int_distribution<int> distribution(1, 4);
        int randomNumber = distribution(generator);

        switch (randomNumber)
        {
            case 1:
                fsm->SetWolfAction(FSM::WolfFSM::WolfActions::DestroyMeat);
                break;

                case 2:
                    fsm->SetWolfAction(FSM::WolfFSM::WolfActions::DestroyWater);
                    break;

                case 3:
                    fsm->SetWolfAction(FSM::WolfFSM::WolfActions::StealFromNest);
                    break;

                    case 4:
                    fsm->SetWolfAction(FSM::WolfFSM::WolfActions::BullyKitten);
                    break;
        }

        fsm->SetState(FSM::WolfFSM::States::SettingDestination);
    }

    void FSM::WolfFSMHandler::ChooseAction(FSM::WolfFSM* fsm) {

        if(fsm->CurrentState() == FSM::WolfFSM::States::DoingAction){

            DoAction(fsm);
        }
        else if(fsm->CurrentState() == FSM::WolfFSM::States::Moving){

            fsm->unit->FollowPath(fsm->unit->path);

            if(fsm->unit->hasMoved){

                fsm->SetState(FSM::WolfFSM::States::DoingAction);
            }
        }
        else if(fsm->CurrentState() == FSM::WolfFSM::States::SettingDestination){

            fsm->unit->destination = SetDestination(fsm);

            fsm->unit->FindPath(fsm->grid, fsm->unit->destination);
        }
    }

    GridLocation FSM::WolfFSMHandler::SetDestination(FSM::WolfFSM* fsm) {

        std::random_device generator;
        std::uniform_int_distribution<int> distributionIndex(0, 4);
        std::uniform_int_distribution<int> escapeDistributionX(0, fsm->grid->width);
        std::uniform_int_distribution<int> escapeDistributionY(0, fsm->grid->height);

        fsm->locationIndexMeat = distributionIndex(generator);
        fsm->locationIndexWater = distributionIndex(generator);

        auto escapeX = (float) escapeDistributionX(generator);
        auto escapeY = (float) escapeDistributionY(generator);
        auto* escapeLocation = new Vector2(escapeX, escapeY);

        switch (fsm->CurrentWolfAction()) {

            case FSM::WolfFSM::WolfActions::DestroyMeat:
                fsm->unit->destination = { (int) fsm->destinations1[fsm->locationIndexMeat]->x, (int) fsm->destinations1[fsm->locationIndexMeat]->y };
                break;

            case FSM::WolfFSM::WolfActions::DestroyWater:
                fsm->unit->destination = { (int) fsm->destinations2[fsm->locationIndexWater]->x, (int) fsm->destinations2[fsm->locationIndexWater]->y };
                break;

            case FSM::WolfFSM::WolfActions::StealFromNest:
                fsm->unit->destination = { 810, 510};
                break;

            case FSM::WolfFSM::WolfActions::BullyKitten:
                fsm->unit->destination = { (int) fsm->kittensLocation->x, (int) fsm->kittensLocation->y };
                break;

            case FSM::WolfFSM::WolfActions::RunAway:
                fsm->unit->destination = { (int) escapeLocation->x, (int) escapeLocation->y };
                break;

            case FSM::WolfFSM::WolfActions::NoAction:
                CheckState(fsm);
                break;
        }

        fsm->SetState(FSM::WolfFSM::States::Moving);
        return fsm->unit->destination;
    }

    void FSM::WolfFSMHandler::DoAction(FSM::WolfFSM* fsm) {

        fsm->actionTimer += fsm->timer->DeltaTime();
        if(fsm->actionTimer >= fsm->actionTimeEnd){

            switch (fsm->CurrentWolfAction()) {

                case FSM::WolfFSM::WolfActions::DestroyMeat:
                    fsm->meats[fsm->locationIndexMeat]->DestroyResource();
                    break;

                case FSM::WolfFSM::WolfActions::DestroyWater:
                    fsm->waters[fsm->locationIndexWater]->DestroyResource();
                    break;

                case FSM::WolfFSM::WolfActions::StealFromNest:
                    fsm->nest->UseResources(20, 20);
                    break;

                case FSM::WolfFSM::WolfActions::BullyKitten:
                    fsm->needs->ReduceNeed(2, 5);
                    break;

                case FSM::WolfFSM::WolfActions::RunAway:
                    break;

                case FSM::WolfFSM::WolfActions::NoAction:
                    DefaultStates(fsm);
                    CheckState(fsm);
                    break;
            }
        }

        DefaultStates(fsm);
    }

    void WolfFSMHandler::DefaultStates(WolfFSM *fsm) {

        fsm->SetState(WolfFSM::States::Idle);
        fsm->SetWolfAction(WolfFSM::WolfActions::NoAction);
        fsm->unit->hasMoved = false;
    }
}

