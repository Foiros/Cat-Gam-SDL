//
// Created by arttu on 19/07/2021.
//

#ifndef CATGAMESDL_NEWFSM_H
#define CATGAMESDL_NEWFSM_H

#include "../PathfindingHeaderFiles/PathfindingGrid.h"
#include "../PathfindingHeaderFiles/PathfindingUnit.h"
#include "../CatGameHeaderFiles/KittenNeeds.h"
#include "../CatGameHeaderFiles/Nest.h"

#include <vector>

using namespace CatGame;

namespace FSM{

    class NewFSM{

    public:
        enum class States{

            Idle,
            SettingDestination,
            Moving,
            DoingAction,
            Dead
        };

        enum class KittenActions{

            NoAction,
            Scratch,
            Study,
            Play,
            Eat,
            Drink
        };

        enum class WolfActions{


        };

    public:
        States currentState;
        KittenActions kittenAction;

        PathfindingGrid* grid;
        PathfindingUnit* unit;
        KittenNeeds* needs;
        Nest* nest;

        std::vector<Vector2*> destinations1, destinations2, destinations3;

        Timer* timer;
        float actionTimer = 0.0f;
        float actionTimeEnd = 1.0f;


    public:
        NewFSM(PathfindingGrid* _grid, PathfindingUnit* _unit, KittenNeeds* _needs, Nest* _nest, Timer* _timer,
               std::vector<Vector2*> d1, std::vector<Vector2*> d2, std::vector<Vector2*> d3);
        ~NewFSM();

        void SetState(States newState);
        States CurrentState() const;

        void SetAction(KittenActions newAction);
        KittenActions CurrentAction() const;

        void Update();
    };
}

#endif //CATGAMESDL_NEWFSM_H
