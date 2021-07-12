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

        for(auto & i : entity){

            i->Parent(parent);

            float x = rand() % grid->width;
            float y = rand() % grid->height;
            i->Pos(Vector2(x, y));
        }
    }

    void Spawner::SpawnOne(Vector2 position, GameEntity *entity, GameEntity* parent) {

        entity->Parent(parent);
        entity->Pos(Vector2(position));
    }

    void Spawner::SpawnMeat(PathfindingGrid* grid, std::vector<Meat*> meats, GameEntity* parent) {

        for(auto & meat : meats){

            meat->Parent(parent);

            float x = rand() % grid->width;
            float y = rand() % grid->height;
            meat->Pos(Vector2(x, y));
        }
    }

    void Spawner::SpawnWater(PathfindingGrid *grid, std::vector<Water *> waters, GameEntity *parent) {

        for(auto & water : waters){

            water->Parent(parent);

            float x = rand() % grid->width;
            float y = rand() % grid->height;
            water->Pos(Vector2(x, y));
        }
    }

    void Spawner::SpawnTrees(PathfindingGrid *grid, std::vector<Tree *> trees, GameEntity *parent) {

        for(auto & tree : trees){

            tree->Parent(parent);

            float x = rand() % grid->width;
            float y = rand() % grid->height;
            tree->Pos(Vector2(x, y));
        }
    }

    void Spawner::SpawnFlowers(PathfindingGrid *grid, std::vector<Flower *> flowers, GameEntity *parent) {

        for(auto & flower : flowers){

            flower->Parent(parent);

            float x = rand() % grid->width;
            float y = rand() % grid->height;
            flower->Pos(Vector2(x, y));
        }
    }

    void Spawner::SpawnMice(PathfindingGrid *grid, std::vector<Mouse *> mice, GameEntity *parent) {

        for(auto & mouse : mice){

            mouse->Parent(parent);

            float x = rand() % grid->width;
            float y = rand() % grid->height;
            mouse->Pos(Vector2(x, y));
        }
    }
}