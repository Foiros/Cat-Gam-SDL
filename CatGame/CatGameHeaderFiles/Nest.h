//
// Created by arttu on 19/05/2021.
//

#ifndef CATGAMESDL_NEST_H
#define CATGAMESDL_NEST_H

#include "../PhysicsEngineHeaderFiles/PhysicsEntity.h"
#include "../PhysicsEngineHeaderFiles/PhysicsManager.h"

using namespace SDL;

class Nest : public PhysicsEntity{

private:
    int meat, water;

    const int nestMinResource = 0;
    const int nestMaxResource = 200;

    bool motherVisited;
    bool kittenVisited;

    Texture* sprite;

public:
    Nest();
    ~Nest();

    bool IgnoreCollisions() override;
    void ContactWithOtherCollider(PhysicsEntity* other) override;

    int GetResource(std::string resourceName);
    bool GetMotherVisited();
    bool GetKittenVisited();
    void AddResourcesToNest(int _meat, int _water);
    void UseResources(int reducedMeat, int reducedWater);

    void Render();
};

#endif
