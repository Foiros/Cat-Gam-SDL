//
// Created by arttu on 26/07/2021.
//

#ifndef CATGAMESDL_WOLFFSM_H
#define CATGAMESDL_WOLFFSM_H

#include "../PathfindingHeaderFiles/PathfindingGrid.h"
#include "../PathfindingHeaderFiles/PathfindingUnit.h"
#include "../CatGameHeaderFiles/KittenNeeds.h"
#include "../CatGameHeaderFiles/Nest.h"
#include "../CatGameHeaderFiles/Meat.h"
#include "../CatGameHeaderFiles/Water.h"

#include <vector>

using namespace CatGame;

namespace FSM{

    class WolfFSM{

    public:
        enum class States{

            Idle,
            SettingDestination,
            Moving,
            DoingAction,
            Dead
        };

        enum class WolfActions{

            NoAction,
            DestroyMeat,
            DestroyWater,
            StealFromNest,
            BullyKitten,
            RunAway
        };


    private:
        States currentState;
        WolfActions wolfAction;

    public:
        PathfindingGrid* grid;
        PathfindingUnit* unit;
        KittenNeeds* needs;
        Nest* nest;

        std::vector<Meat*> meats;
        std::vector<Water*> waters;

        int locationIndexMeat, locationIndexWater;

        std::vector<Vector2*> destinations1, destinations2;
        Vector2* kittenLocation;

        Timer* timer;
        float actionTimer = 0.0f;
        float actionTimeEnd = 1.0f;


    public:
        WolfFSM(PathfindingGrid* _grid, PathfindingUnit* _unit, KittenNeeds* _needs, Nest* _nest, Timer* _timer,
                  std::vector<Vector2*> d1, std::vector<Vector2*> d2,
                  std::vector<Meat*> _meats, std::vector<Water*> _waters);
        ~WolfFSM();

        void SetState(States newState);
        States CurrentState() const;

        void SetWolfAction(WolfActions newAction);
        WolfActions CurrentWolfAction() const;

        void Update(Vector2* _kittenLocation);
    };
}

#endif //CATGAMESDL_WOLFFSM_H
