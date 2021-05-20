//
// Created by arttu on 19/05/2021.
//

#ifndef CATGAMESDL_NEST_H
#define CATGAMESDL_NEST_H

#include "../CatGameHeaderFiles/PhysicsEntity.h"
#include "../CatGameHeaderFiles/PhysicsManager.h"
#include "../CatGameHeaderFiles/MotherCat.h"

using namespace SDL;

class Nest : public PhysicsEntity{

private:
    int meat, water;

    Texture* sprite;

public:
    Nest();
    ~Nest();

    void Update();
    void Render();

    int NestMeat();
    int NestWater();

    bool IgnoreCollisions() override;
    void ContactWithOtherCollider(PhysicsEntity* other) override;

    void AddResourcesToNest(int _meat, int _water);
    void UseResources(int reducedMeat, int reducedWater);
};

#endif
