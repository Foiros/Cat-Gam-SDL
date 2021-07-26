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

        if (fsm->needs->GetNeed(0) <= 75 && fsm->nest->GetResource("Meat") > 0) {

            fsm->SetWolfAction(FSM::WolfFSM::WolfActions::DestroyMeat);
        }
        else if(fsm->needs->GetNeed(1) <= 75 && fsm->nest->GetResource("Water") > 0){

            fsm->SetWolfAction(FSM::WolfFSM::WolfActions::DestroyWater);
        }
        else{

            std::random_device generator;
            std::uniform_int_distribution<int> distribution(1, 3);
            int randomNumber = distribution(generator);

            switch (randomNumber) {

                case 1:
                    fsm->SetWolfAction(FSM::WolfFSM::WolfActions::StealFromNest);
                    break;

                case 2:
                    fsm->SetWolfAction(FSM::WolfFSM::WolfActions::BullyKitten);
                    break;

                case 3:
                    fsm->SetWolfAction(FSM::WolfFSM::WolfActions::RunAway);
                    break;
            }
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
        std::uniform_int_distribution<int> distribution(0, 2);

        int locationIndexTrees = distribution(generator);
        int locationIndexFlowers = distribution(generator);
        int locationIndexMice = distribution(generator);

        switch (fsm->CurrentWolfAction()) {

            case FSM::WolfFSM::WolfActions::DestroyMeat:
                fsm->unit->destination = { (int) fsm->destinations1[locationIndexTrees]->x, (int) fsm->destinations1[locationIndexTrees]->y };
                break;

            case FSM::WolfFSM::WolfActions::DestroyWater:
                fsm->unit->destination = { (int) fsm->destinations2[locationIndexFlowers]->x, (int) fsm->destinations2[locationIndexFlowers]->y };
                break;

            case FSM::WolfFSM::WolfActions::StealFromNest:
                fsm->unit->destination = { (int) fsm->destinations3[locationIndexMice]->x, (int) fsm->destinations3[locationIndexMice]->y };
                break;

            case FSM::WolfFSM::WolfActions::BullyKitten:
                fsm->unit->destination = { 810, 510};
                break;

            case FSM::WolfFSM::WolfActions::RunAway:
                fsm->unit->destination = {810, 540};
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
                    break;

                case FSM::WolfFSM::WolfActions::DestroyWater:
                    break;

                case FSM::WolfFSM::WolfActions::StealFromNest:
                    break;

                case FSM::WolfFSM::WolfActions::BullyKitten:
                    break;

                case FSM::WolfFSM::WolfActions::RunAway:
                    break;

                case FSM::WolfFSM::WolfActions::NoAction:
                    CheckState(fsm);
                    break;
            }
        }
    }

    void WolfFSMHandler::DefaultStates(WolfFSM *fsm) {

        fsm->SetState(WolfFSM::States::Idle);
        fsm->SetWolfAction(WolfFSM::WolfActions::NoAction);
        fsm->unit->hasMoved = false;
    }
}

