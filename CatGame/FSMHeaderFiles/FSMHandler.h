//
// Created by arttu on 19/07/2021.
//

#ifndef CATGAMESDL_FSMHANDLER_H
#define CATGAMESDL_FSMHANDLER_H

#include "../FSMHeaderFiles/NewFSM.h"
#include <random>

namespace FSM{

    class FSMHandler{

    public:
        static void CheckState(NewFSM* fsm);
        static void SetAction(NewFSM* fsm);
        static void ChooseAction(NewFSM* fsm);
        static GridLocation SetDestination(NewFSM* fsm);
        static void DoAction(NewFSM* fsm);

        static void Hunger(NewFSM* fsm);
        static void Thirst(NewFSM* fsm);
        static void Eat(NewFSM* fsm);
        static void Drink(NewFSM* fsm);

        static void DefaultStates(NewFSM* fsm);
    };
}

#endif //CATGAMESDL_FSMHANDLER_H
