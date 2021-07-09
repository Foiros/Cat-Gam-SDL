//
// Created by arttu on 19/05/2021.
//

#ifndef CATGAMESDL_FLOWER_H
#define CATGAMESDL_FLOWER_H

#include "../PhysicsEngineHeaderFiles/PhysicsEntity.h"

using namespace PhysicsEngine;

namespace CatGame{

    class Flower : public PhysicsEntity{

    private:
        Texture* sprite;

    public:
        Flower();
        ~Flower();

        void Render();

        bool IgnoreCollisions() override;
        void ContactWithOtherCollider(PhysicsEntity* other) override;
    };
}

#endif //CATGAMESDL_FLOWER_H
