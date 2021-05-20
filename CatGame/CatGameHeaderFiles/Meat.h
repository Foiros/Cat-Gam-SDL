//
// Created by arttu on 19/05/2021.
//

#ifndef CATGAMESDL_MEAT_H
#define CATGAMESDL_MEAT_H

#include "../CatGameHeaderFiles/PhysicsEntity.h"
#include "../CatGameHeaderFiles/PhysicsManager.h"

class Meat : public PhysicsEntity{

private:
    std::string name;
    int value;

    Texture* sprite;

public:
    Meat();
    ~Meat();

    bool IgnoreCollisions() override;
    void ContactWithOtherCollider(PhysicsEntity* other) override;

    void GatherResource();

    void Render();
};

#endif
