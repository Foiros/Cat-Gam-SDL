//
// Created by arttu on 19/07/2021.
//

#include "../FSMHeaderFiles/KittenFSMHandler.h"

namespace FSM{

    void FSM::KittenFSMHandler::CheckState(FSM::KittenFSM *fsm) {

        if(fsm->CurrentState() == KittenFSM::States::Idle){

            SetAction(fsm);
            ChooseAction(fsm);
        }
        else
            ChooseAction(fsm);
    }

    void FSM::KittenFSMHandler::SetAction(KittenFSM* fsm) {

        if (fsm->needs->GetNeed(0) <= 75 && fsm->nest->GetResource("Meat") > 0) {

            fsm->SetKittenAction(KittenFSM::KittenActions::Eat);
        }
        else if(fsm->needs->GetNeed(1) <= 75 && fsm->nest->GetResource("Water") > 0){

            fsm->SetKittenAction(KittenFSM::KittenActions::Drink);
        }
        else{

            std::random_device generator;
            std::uniform_int_distribution<int> distribution(1, 3);
            int randomNumber = distribution(generator);

            switch (randomNumber) {

                case 1:
                    fsm->SetKittenAction(KittenFSM::KittenActions::Scratch);
                    break;

                case 2:
                    fsm->SetKittenAction(KittenFSM::KittenActions::Study);
                    break;

                case 3:
                    fsm->SetKittenAction(KittenFSM::KittenActions::Play);
                    break;
            }
        }

        fsm->SetState(KittenFSM::States::SettingDestination);
    }

    void FSM::KittenFSMHandler::ChooseAction(KittenFSM* fsm) {

        if(fsm->CurrentState() == KittenFSM::States::DoingAction){

            DoAction(fsm);
        }
        else if(fsm->CurrentState() == KittenFSM::States::Moving){

            fsm->unit->FollowPath(fsm->unit->path);

            if(fsm->unit->hasMoved){

                fsm->SetState(KittenFSM::States::DoingAction);
            }
        }
        else if(fsm->CurrentState() == KittenFSM::States::SettingDestination){

            fsm->unit->destination = SetDestination(fsm);

            fsm->unit->FindPath(fsm->grid, fsm->unit->destination);
        }
    }

    GridLocation FSM::KittenFSMHandler::SetDestination(KittenFSM* fsm) {

        std::random_device generator;
        std::uniform_int_distribution<int> distribution(0, 2);

        int locationIndexTrees = distribution(generator);
        int locationIndexFlowers = distribution(generator);
        int locationIndexMice = distribution(generator);

        switch (fsm->CurrentKittenAction()) {

            case KittenFSM::KittenActions::Scratch:
                fsm->unit->destination = { (int) fsm->destinations1[locationIndexTrees]->x, (int) fsm->destinations1[locationIndexTrees]->y };
                break;

            case KittenFSM::KittenActions::Study:
                fsm->unit->destination = { (int) fsm->destinations2[locationIndexFlowers]->x, (int) fsm->destinations2[locationIndexFlowers]->y };
                break;

            case KittenFSM::KittenActions::Play:
                fsm->unit->destination = { (int) fsm->destinations3[locationIndexMice]->x, (int) fsm->destinations3[locationIndexMice]->y };
                break;

            case KittenFSM::KittenActions::Eat:
                fsm->unit->destination = { 810, 510};
                break;

            case KittenFSM::KittenActions::Drink:
                fsm->unit->destination = {810, 540};
                break;

            case KittenFSM::KittenActions::NoAction:
                DefaultStates(fsm);
                CheckState(fsm);
                break;
        }

        fsm->SetState(KittenFSM::States::Moving);
        return fsm->unit->destination;
    }

    void FSM::KittenFSMHandler::DoAction(KittenFSM* fsm) {

        fsm->actionTimer += fsm->timer->DeltaTime();
        if(fsm->actionTimer >= fsm->actionTimeEnd){

            switch (fsm->CurrentKittenAction()) {

                case KittenFSM::KittenActions::Scratch:
                    Hunger(fsm, 1, 2);
                    break;

                case KittenFSM::KittenActions::Study:
                    Hunger(fsm, 0, 2);
                    break;

                case KittenFSM::KittenActions::Play:
                    Hunger(fsm, 1, 2);
                    break;

                case KittenFSM::KittenActions::Eat:
                    Nourishment(fsm, 0, 10, 0);
                    break;

                case KittenFSM::KittenActions::Drink:
                    Nourishment(fsm, 1, 0, 10);
                    break;

                case KittenFSM::KittenActions::NoAction:
                    DefaultStates(fsm);
                    CheckState(fsm);
                    break;
            }

            DefaultStates(fsm);
        }
    }

    void KittenFSMHandler::Hunger(KittenFSM *fsm, int needID1, int needID2) {

        fsm->needs->ReduceNeed(needID1, 0);
        fsm->needs->IncreaseNeed(needID2, 0);
    }


    void KittenFSMHandler::Nourishment(KittenFSM *fsm, int needID, int reducedAmount1, int reducedAmount2){

        fsm->nest->UseResources(reducedAmount1, reducedAmount2);
        fsm->needs->IncreaseNeed(needID, 10);
    }


    void KittenFSMHandler::DefaultStates(KittenFSM *fsm) {

        fsm->SetState(KittenFSM::States::Idle);
        fsm->SetKittenAction(KittenFSM::KittenActions::NoAction);
        fsm->unit->hasMoved = false;
    }
}