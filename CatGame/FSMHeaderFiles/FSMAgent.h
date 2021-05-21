//
// Created by arttu on 21/05/2021.
//

#ifndef CATGAMESDL_FSMAGENT_H
#define CATGAMESDL_FSMAGENT_H

#include "../PathfindingHeaderFiles/PathfindingUnit.h"
#include "FSM.h"
#include "../CatGameHeaderFiles/KittenNeeds.h"
#include "../CatGameHeaderFiles/Nest.h"

using namespace CatGame;

namespace FSM{

    class FSMAgent : public PathfindingUnit{

    private:
        FSM* mFSM;

        Timer* mTimer;

        float actionTimer;
        float actionEndTime;

    public:
        FSMAgent();
        ~FSMAgent();

        FSM* GetFSM();

        void CheckState(KittenNeeds* needs, Nest* nest, PathfindingGrid* grid);
        void SetAction();
        GridLocation SetDestination();
        void ChooseAction(KittenNeeds* needs, Nest* nest, PathfindingGrid* grid);
        void DoAction(KittenNeeds* needs, Nest* nest, PathfindingGrid* grid);

        void ActionScratchTree(KittenNeeds* needs, PathfindingGrid* grid);
        void ActionStudy(KittenNeeds* needs, PathfindingGrid* grid);
        void ActionPlay(KittenNeeds* needs, PathfindingGrid* grid);
        void ActionEat(KittenNeeds* needs, PathfindingGrid* grid);
        void ActionDrink(KittenNeeds* needs, PathfindingGrid* grid);
        void ActionHateMom(KittenNeeds* needs, PathfindingGrid* grid);
    };
}

#endif //CATGAMESDL_FSMAGENT_H
