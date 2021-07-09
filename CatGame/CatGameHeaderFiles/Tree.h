//
// Created by arttu on 19/05/2021.
//

#ifndef CATGAMESDL_TREE_H
#define CATGAMESDL_TREE_H

#include "../PhysicsEngineHeaderFiles/PhysicsEntity.h"

using namespace PhysicsEngine;

namespace CatGame{

    class Tree : public PhysicsEntity{

    private:
        Texture* sprite;

    public:
        Tree();
        ~Tree();

        void Render();

        bool IgnoreCollisions() override;
        void ContactWithOtherCollider(PhysicsEntity* other) override;
    };
}

#endif //CATGAMESDL_TREE_H
