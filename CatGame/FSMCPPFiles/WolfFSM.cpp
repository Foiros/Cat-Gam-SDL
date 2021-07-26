//
// Created by arttu on 26/07/2021.
//

#include "../FSMHeaderFiles/WolfFSM.h"

#include <utility>
#include "../FSMHeaderFiles/WolfFSMHandler.h"

namespace FSM{

    FSM::WolfFSM::WolfFSM(PathfindingGrid *_grid, PathfindingUnit *_unit, KittenNeeds *_needs, Nest *_nest, Timer *_timer,
                          std::vector<Vector2 *> d1, std::vector<Vector2 *> d2, std::vector<Vector2 *> d3) {

        grid = _grid;
        unit = _unit;
        needs = _needs;
        nest = _nest;
        timer = _timer;

        destinations1 = std::move(d1);
        destinations2 = std::move(d2);
        destinations3 = std::move(d3);

        currentState = WolfFSM::States::Idle;
        wolfAction = WolfFSM::WolfActions::NoAction;
    }

    FSM::WolfFSM::~WolfFSM() {

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

    void FSM::WolfFSM::SetState(FSM::WolfFSM::States newState) {

        currentState = newState;
    }

    FSM::WolfFSM::States FSM::WolfFSM::CurrentState() const {

        return currentState;
    }

    void FSM::WolfFSM::SetWolfAction(FSM::WolfFSM::WolfActions newAction) {

        wolfAction = newAction;
    }

    FSM::WolfFSM::WolfActions FSM::WolfFSM::CurrentWolfAction() const {

        return wolfAction;
    }

    void FSM::WolfFSM::Update() {

        FSM::WolfFSMHandler::CheckState(this);
    }
}