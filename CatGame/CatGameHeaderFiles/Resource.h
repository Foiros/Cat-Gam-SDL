//
// Created by arttu on 19/05/2021.
//

#ifndef CATGAMESDL_RESOURCE_H
#define CATGAMESDL_RESOURCE_H

#include "../CatGameHeaderFiles/PhysicsEntity.h"
#include "../CatGameHeaderFiles/PhysicsManager.h"
#include <string>

using namespace SDL;

class Resource : public PhysicsEntity{

protected:
    std::string name;
    int value;

    Texture* sprite;

public:
    Resource();
    ~Resource();

    // Collision functions
    bool IgnoreCollisions() override;

    int GatherResource();

    void Update();
    void Render();
};

#endif
