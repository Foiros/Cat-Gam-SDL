//
// Created by arttu on 19/05/2021.
//

#ifndef CATGAMESDL_MEAT_H
#define CATGAMESDL_MEAT_H

#include "Resource.h"

class Meat : public Resource{

public:
    Meat();
    ~Meat();

    bool IgnoreCollisions() override;
    void ContactWithOtherCollider(PhysicsEntity* other) override;

    void GatherResource();
};

#endif
