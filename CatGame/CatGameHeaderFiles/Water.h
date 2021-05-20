//
// Created by arttu on 19/05/2021.
//

#ifndef CATGAMESDL_WATER_H
#define CATGAMESDL_WATER_H

#include "Resource.h"

class Water : public Resource{

public:
    Water();
    ~Water();

    bool IgnoreCollisions() override;
    void ContactWithOtherCollider(PhysicsEntity* other) override;

    void GatherResource();
};

#endif //CATGAMESDL_WATER_H
