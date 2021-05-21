//
// Created by arttu on 19/05/2021.
//

#ifndef CATGAMESDL_MEAT_H
#define CATGAMESDL_MEAT_H

#include "../PhysicsEngineHeaderFiles/PhysicsEntity.h"
#include "../PhysicsEngineHeaderFiles/PhysicsManager.h"

using namespace PhysicsEngine;

class Meat : public PhysicsEntity{

private:
    int value;

    bool gathered;

    Texture* sprite;

public:
    Meat();
    ~Meat();

    bool IgnoreCollisions() override;
    void ContactWithOtherCollider(PhysicsEntity* other) override;

    void GatherResource();
    bool GetGathered();
    int GetValue();

    void Render();
};

#endif
