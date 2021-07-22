//
// Created by arttu on 19/07/2021.
//

#include "../FSMHeaderFiles/NewFSM.h"

#include <utility>
#include "../FSMHeaderFiles/FSMHandler.h"

namespace FSM{

    FSM::NewFSM::NewFSM(PathfindingGrid *_grid, PathfindingUnit *_unit, KittenNeeds *_needs, Nest *_nest, Timer* _timer,
                        std::vector<Vector2*> d1, std::vector<Vector2*> d2, std::vector<Vector2*> d3) {

        grid = _grid;
        unit = _unit;
        needs = _needs;
        nest = _nest;
        timer = _timer;

        destinations1 = std::move(d1);
        destinations2 = std::move(d2);
        destinations3 = std::move(d3);

        currentState = NewFSM::States::Idle;
        kittenAction = NewFSM::KittenActions::NoAction;
    }


    FSM::NewFSM::~NewFSM() {

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


    void FSM::NewFSM::SetState(FSM::NewFSM::States newState) {

        currentState = newState;
    }

    FSM::NewFSM::States FSM::NewFSM::CurrentState() const {

        return currentState;
    }

    void FSM::NewFSM::SetAction(FSM::NewFSM::KittenActions newAction) {

        kittenAction = newAction;
    }

    FSM::NewFSM::KittenActions FSM::NewFSM::CurrentAction() const {

        return kittenAction;
    }

    void FSM::NewFSM::Update() {

        FSM::FSMHandler::CheckState(this);
    }
}