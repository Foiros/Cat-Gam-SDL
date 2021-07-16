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

        std::random_device generator;
        std::uniform_int_distribution<int> distributionHeight(1,grid->height);
        std::uniform_int_distribution<int> distributionWidth(1, grid->width);

        for(auto & i : entity){

            i->Parent(parent);

            auto x = (float) distributionWidth(generator);
            auto y = (float) distributionHeight(generator);
            i->Pos(Vector2(x, y));
        }
    }

    void Spawner::SpawnOne(Vector2 position, GameEntity *entity, GameEntity* parent) {

        entity->Parent(parent);
        entity->Pos(Vector2(position));
    }

    void Spawner::SpawnMeat(PathfindingGrid* grid, std::vector<Meat*> meats, GameEntity* parent) {

        std::random_device generator;
        std::uniform_int_distribution<int> distributionHeight(1,grid->height);
        std::uniform_int_distribution<int> distributionWidth(1, grid->width);

        for(auto & meat : meats){

            meat->Parent(parent);

            auto x = (float) distributionWidth(generator);
            auto y = (float) distributionHeight(generator);
            meat->Pos(Vector2(x, y));
        }
    }

    void Spawner::SpawnWater(PathfindingGrid *grid, std::vector<Water *> waters, GameEntity *parent) {

        std::random_device generator;
        std::uniform_int_distribution<int> distributionHeight(1,grid->height);
        std::uniform_int_distribution<int> distributionWidth(1, grid->width);

        for(auto & water : waters){

            water->Parent(parent);

            auto x = (float) distributionWidth(generator);
            auto y = (float) distributionHeight(generator);
            water->Pos(Vector2(x, y));
        }
    }

    void Spawner::SpawnTrees(PathfindingGrid *grid, std::vector<Tree *> trees, GameEntity *parent) {

        std::random_device generator;
        std::uniform_int_distribution<int> distributionHeight(1,grid->height);
        std::uniform_int_distribution<int> distributionWidth(1, grid->width);

        for(auto & tree : trees){

            tree->Parent(parent);

            auto x = (float) distributionWidth(generator);
            auto y = (float) distributionHeight(generator);
            tree->Pos(Vector2(x, y));
        }
    }

    void Spawner::SpawnFlowers(PathfindingGrid *grid, std::vector<Flower *> flowers, GameEntity *parent) {

        std::random_device generator;
        std::uniform_int_distribution<int> distributionHeight(1,grid->height);
        std::uniform_int_distribution<int> distributionWidth(1, grid->width);

        for(auto & flower : flowers){

            flower->Parent(parent);

            auto x = (float) distributionWidth(generator);
            auto y = (float) distributionHeight(generator);
            flower->Pos(Vector2(x, y));
        }
    }

    void Spawner::SpawnMice(PathfindingGrid *grid, std::vector<Mouse *> mice, GameEntity *parent) {

        std::random_device generator;
        std::uniform_int_distribution<int> distributionHeight(1,grid->height);
        std::uniform_int_distribution<int> distributionWidth(1, grid->width);

        for(auto & mouse : mice){

            mouse->Parent(parent);

            auto x = (float) distributionWidth(generator);
            auto y = (float) distributionHeight(generator);
            mouse->Pos(Vector2(x, y));
        }
    }
}