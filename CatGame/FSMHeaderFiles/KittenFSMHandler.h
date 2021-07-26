//
// Created by arttu on 19/07/2021.
//

#ifndef CATGAMESDL_KITTENFSMHANDLER_H
#define CATGAMESDL_KITTENFSMHANDLER_H

#include "../FSMHeaderFiles/KittenFSM.h"
#include <random>

namespace FSM{

    class KittenFSMHandler{

    public:
        static void CheckState(KittenFSM* fsm);
        static void SetAction(KittenFSM* fsm);
        static void ChooseAction(KittenFSM* fsm);
        static GridLocation SetDestination(KittenFSM* fsm);
        static void DoAction(KittenFSM* fsm);

        static void Hunger(KittenFSM* fsm, int needID1, int needID2);
        static void Nourishment(KittenFSM* fsm, int needID, int reducedAmount1, int reducedAmount2);

        static void DefaultStates(KittenFSM* fsm);
    };
}

#endif //CATGAMESDL_KITTENFSMHANDLER_H
