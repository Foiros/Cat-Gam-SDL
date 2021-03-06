//
// Created by arttu on 19/05/2021.
//

#ifndef CATGAMESDL_WATER_H
#define CATGAMESDL_WATER_H

#include "../PhysicsEngineHeaderFiles/PhysicsEntity.h"
#include "../PhysicsEngineHeaderFiles/PhysicsManager.h"
#include <random>

using namespace PhysicsEngine;

namespace CatGame{

    class Water : public PhysicsEntity{

    private:
        int value;

        bool gathered;

        Texture* sprite;

    public:
        Water();
        ~Water();

        bool IgnoreCollisions() override;
        void ContactWithOtherCollider(PhysicsEntity* other) override;

        void GatherResource();
        bool GetGathered();
        int GetValue();

        void Render();
    };
}

#endif //CATGAMESDL_WATER_H
