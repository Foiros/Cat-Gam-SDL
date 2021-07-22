//
// Created by arttu on 19/07/2021.
//

#include "../FSMHeaderFiles/FSMHandler.h"

namespace FSM{

    void FSM::FSMHandler::CheckState(FSM::NewFSM *fsm) {

        if(fsm->currentState == NewFSM::States::Idle){

            SetAction(fsm);
            ChooseAction(fsm);
        }
        else
            ChooseAction(fsm);
    }

    void FSM::FSMHandler::SetAction(NewFSM* fsm) {

        if (fsm->needs->GetNeed(0) <= 75 && fsm->nest->GetResource("Meat") > 0) {

            fsm->SetAction(NewFSM::KittenActions::Eat);
        }
        else if(fsm->needs->GetNeed(1) <= 75 && fsm->nest->GetResource("Water") > 0){

            fsm->SetAction(NewFSM::KittenActions::Drink);
        }
        else{

            std::random_device generator;
            std::uniform_int_distribution<int> distribution(1, 3);
            int randomNumber = distribution(generator);

            switch (randomNumber) {

                case 1:
                    fsm->SetAction(NewFSM::KittenActions::Scratch);
                    break;

                case 2:
                    fsm->SetAction(NewFSM::KittenActions::Study);
                    break;

                case 3:
                    fsm->SetAction(NewFSM::KittenActions::Play);
                    break;
            }
        }

        fsm->SetState(NewFSM::States::SettingDestination);
    }

    void FSM::FSMHandler::ChooseAction(NewFSM* fsm) {

        if(fsm->currentState == NewFSM::States::DoingAction){

            DoAction(fsm);
        }
        else if(fsm->currentState == NewFSM::States::Moving){

            fsm->unit->FollowPath(fsm->unit->path);

            if(fsm->unit->hasMoved){

                fsm->SetState(NewFSM::States::DoingAction);
            }
        }
        else if(fsm->currentState == NewFSM::States::SettingDestination){

            fsm->unit->destination = SetDestination(fsm);

            fsm->unit->FindPath(fsm->grid, fsm->unit->destination);
        }
    }

    GridLocation FSM::FSMHandler::SetDestination(NewFSM* fsm) {

        std::random_device generator;
        std::uniform_int_distribution<int> distribution(0, 2);

        int locationIndexTrees = distribution(generator);
        int locationIndexFlowers = distribution(generator);
        int locationIndexMice = distribution(generator);

        switch (fsm->kittenAction) {

            case NewFSM::KittenActions::Scratch:
                fsm->unit->destination = { (int) fsm->destinations1[locationIndexTrees]->x, (int) fsm->destinations1[locationIndexTrees]->y };
                break;

            case NewFSM::KittenActions::Study:
                fsm->unit->destination = { (int) fsm->destinations2[locationIndexFlowers]->x, (int) fsm->destinations2[locationIndexFlowers]->y };
                break;

            case NewFSM::KittenActions::Play:
                fsm->unit->destination = { (int) fsm->destinations3[locationIndexMice]->x, (int) fsm->destinations3[locationIndexMice]->y };
                break;

            case NewFSM::KittenActions::Eat:
                fsm->unit->destination = { 810, 510};
                break;

            case NewFSM::KittenActions::Drink:
                fsm->unit->destination = {810, 540};
                break;

            case NewFSM::KittenActions::NoAction:
                DefaultStates(fsm);
                CheckState(fsm);
                break;
        }

        fsm->SetState(NewFSM::States::Moving);
        return fsm->unit->destination;
    }

    void FSM::FSMHandler::DoAction(NewFSM* fsm) {

        fsm->actionTimer += fsm->timer->DeltaTime();
        if(fsm->actionTimer >= fsm->actionTimeEnd){

            switch (fsm->CurrentAction()) {

                case NewFSM::KittenActions::Scratch:
                    Thirst(fsm);
                    break;

                case NewFSM::KittenActions::Study:
                    Hunger(fsm);
                    break;

                case NewFSM::KittenActions::Play:
                    Thirst(fsm);
                    break;

                case NewFSM::KittenActions::Eat:
                    Eat(fsm);
                    break;

                case NewFSM::KittenActions::Drink:
                    Drink(fsm);
                    break;

                case NewFSM::KittenActions::NoAction:
                    DefaultStates(fsm);
                    CheckState(fsm);
                    break;
            }

            DefaultStates(fsm);
        }
    }

    void FSMHandler::Hunger(NewFSM *fsm) {

        fsm->needs->ReduceNeed(0, 0);
        fsm->needs->IncreaseNeed(2, 0);
    }

    void FSMHandler::Thirst(NewFSM* fsm){

        fsm->needs->ReduceNeed(1, 0);
        fsm->needs->IncreaseNeed(2, 0);
    }

    void FSMHandler::Eat(NewFSM *fsm) {

        fsm->nest->UseResources(10, 0);
        fsm->needs->IncreaseNeed(0, 10);
    }

    void FSMHandler::Drink(NewFSM *fsm) {

        fsm->nest->UseResources(0, 10);
        fsm->needs->IncreaseNeed(1, 10);
    }

    void FSMHandler::DefaultStates(NewFSM *fsm) {

        fsm->SetState(NewFSM::States::Idle);
        fsm->SetAction(NewFSM::KittenActions::NoAction);
        fsm->unit->hasMoved = false;
    }
}