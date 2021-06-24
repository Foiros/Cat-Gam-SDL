//
// Created by arttu on 24/06/2021.
//

#ifndef CATGAMESDL_SPAWNER_H
#define CATGAMESDL_SPAWNER_H

#include "../PathfindingHeaderFiles/PathfindingGrid.h"
#include "../CatGameHeaderFiles/Meat.h"
#include "../CatGameHeaderFiles/Water.h"
#include <vector>

using namespace CatGame;

namespace Spawning{

    class Spawner{

    private:

        static Spawner* sInstance;

    private:
        Spawner();
        ~Spawner();

    public:

        static Spawner* Instance();
        static void Release();

        static void SpawnMultiple(PathfindingGrid* grid, std::vector<GameEntity*> entity, GameEntity* parent);
        static void SpawnOne(Vector2 position, GameEntity* entity, GameEntity* parent);
        static void SpawnMeat(PathfindingGrid* grid, std::vector<Meat*> meats, GameEntity* parent);
        static void SpawnWater(PathfindingGrid* grid, std::vector<Water*> waters, GameEntity* parent);
    };
}

#endif //CATGAMESDL_SPAWNER_H
