//
// Created by arttu on 19/07/2021.
//

#include "../FSMHeaderFiles/KittenFSM.h"

#include <utility>
#include "../FSMHeaderFiles/KittenFSMHandler.h"

namespace FSM{

    FSM::KittenFSM::KittenFSM(PathfindingGrid *_grid, PathfindingUnit *_unit, KittenNeeds *_needs, Nest *_nest, Timer* _timer,
                        std::vector<Vector2*> d1, std::vector<Vector2*> d2, std::vector<Vector2*> d3) {

        grid = _grid;
        unit = _unit;
        needs = _needs;
        nest = _nest;
        timer = _timer;

        destinations1 = std::move(d1);
        destinations2 = std::move(d2);
        destinations3 = std::move(d3);

        currentState = KittenFSM::States::Idle;
        kittenAction = KittenFSM::KittenActions::NoAction;
    }


    FSM::KittenFSM::~KittenFSM() {

        currentState = States::Idle;

        delete grid;
        delete needs;
        delete nest;

        grid = nullptr;
        unit = nullptr;
        needs = nullptr;
        nest = nullptr;
        timer = nullptr;
    }


    void FSM::KittenFSM::SetState(FSM::KittenFSM::States newState) {

        currentState = newState;
    }

    FSM::KittenFSM::States FSM::KittenFSM::CurrentState() const {

        return currentState;
    }

    void FSM::KittenFSM::SetKittenAction(FSM::KittenFSM::KittenActions newAction) {

        kittenAction = newAction;
    }

    FSM::KittenFSM::KittenActions FSM::KittenFSM::CurrentKittenAction() const {

        return kittenAction;
    }

    void FSM::KittenFSM::Update() {

        FSM::KittenFSMHandler::CheckState(this);
    }
}