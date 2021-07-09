//
// Created by arttu on 19/05/2021.
//

#ifndef CATGAMESDL_MOUSE_H
#define CATGAMESDL_MOUSE_H

#include "../PhysicsEngineHeaderFiles/PhysicsEntity.h"

using namespace PhysicsEngine;

namespace CatGame{

    class Mouse : public PhysicsEntity{

    private:
        Texture* sprite;

    public:
        Mouse();
        ~Mouse();

        void Render();

        bool IgnoreCollisions() override;
        void ContactWithOtherCollider(PhysicsEntity* other) override;
    };
}

#endif //CATGAMESDL_MOUSE_H
