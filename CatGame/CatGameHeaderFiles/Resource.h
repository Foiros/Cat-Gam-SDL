//
// Created by arttu on 19/05/2021.
//

#ifndef CATGAMESDL_RESOURCE_H
#define CATGAMESDL_RESOURCE_H

#include "../SDLHeaderFiles/GameEntity.h"
#include "../SDLHeaderFiles/Texture.h"
#include <string>

using namespace SDL;

class Resource : GameEntity{

protected:
    std::string name;
    int value;

    Texture* sprite;

public:
    Resource();
    ~Resource();

    // Collision functions

    int GatherResource();

    void Update();
    void Render();
};

#endif
