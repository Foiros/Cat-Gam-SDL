//
// Created by arttu on 19/05/2021.
//

#ifndef CATGAMESDL_WATER_H
#define CATGAMESDL_WATER_H

#include "../CatGameHeaderFiles/PhysicsEntity.h"
#include "../CatGameHeaderFiles/PhysicsManager.h"

class Water : public PhysicsEntity{

private:
    std::string name;
    int value;

    Texture* sprite;

public:
    Water();
    ~Water();

    bool IgnoreCollisions() override;
    void ContactWithOtherCollider(PhysicsEntity* other) override;

    void GatherResource();

    void Render();
};

#endif //CATGAMESDL_WATER_H
