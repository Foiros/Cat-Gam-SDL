//
// Created by arttu on 26/07/2021.
//

#ifndef CATGAMESDL_WOLFFSMHANDLER_H
#define CATGAMESDL_WOLFFSMHANDLER_H

#include "../FSMHeaderFiles/WolfFSM.h"
#include <random>

namespace FSM{

    class WolfFSMHandler{

    public:
        static void CheckState(WolfFSM* fsm);
        static void SetAction(WolfFSM* fsm);
        static void ChooseAction(WolfFSM* fsm);
        static GridLocation SetDestination(WolfFSM* fsm);
        static void DoAction(WolfFSM* fsm);
        static void DefaultStates(WolfFSM* fsm);
    };
}

#endif //CATGAMESDL_WOLFFSMHANDLER_H
