//
// Created by arttu on 24/06/2021.
//

#include "../SpawningHeaderFiles/Spawner.h"

namespace Spawning{

    Spawner* Spawner::sInstance = nullptr;

    Spawner::Spawner() = default;

    Spawner::~Spawner() = default;

    Spawner *Spawner::Instance() {

        if(sInstance == nullptr)
            sInstance = new Spawner();

        return sInstance;
    }

    void Spawner::Release() {

        delete sInstance;
        sInstance = nullptr;
    }

    void Spawner::SpawnMultiple(PathfindingGrid *grid, std::vector<GameEntity*> entity, GameEntity* parent) {

        for(int i = 0; i < entity.size(); i++){

            entity[i]->Parent(parent);

            float x = rand() % grid->width;
            float y = rand() % grid->height;
            entity[i]->Pos(Vector2(x, y));
        }
    }

    void Spawner::SpawnOne(Vector2 position, GameEntity *entity, GameEntity* parent) {

        entity->Parent(parent);
        entity->Pos(Vector2(position));
    }

    void Spawner::SpawnMeat(PathfindingGrid *grid, std::vector<Meat *> meats, GameEntity *parent) {

        for(int i = 0; i < meats.size(); i++){

            meats[i]->Parent(parent);

            float x = rand() % grid->width;
            float y = rand() % grid->height;
            meats[i]->Pos(Vector2(x, y));
        }
    }

    void Spawner::SpawnWater(PathfindingGrid *grid, std::vector<Water *> waters, GameEntity *parent) {

        for(int i = 0; i < waters.size(); i++){

            waters[i]->Parent(parent);

            float x = rand() % grid->width;
            float y = rand() % grid->height;
            waters[i]->Pos(Vector2(x, y));
        }
    }
}