//
// Created by arttu on 19/05/2021.
//

#ifndef CATGAMESDL_NEST_H
#define CATGAMESDL_NEST_H

#include "../SDLHeaderFiles/Texture.h"
#include "../SDLHeaderFiles/GameEntity.h"

using namespace SDL;

class Nest : public GameEntity{

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

    void AddResourcesToNest(int _meat, int _water);
    void UseResources(int reducedMeat, int reducedWater);
};

#endif
