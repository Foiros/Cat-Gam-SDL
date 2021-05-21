//
// Created by arttu on 20/05/2021.
//

#ifndef CATGAMESDL_PLAYERRESOURCES_H
#define CATGAMESDL_PLAYERRESOURCES_H

#include <string>

class PlayerResources{

private:
    int collectedMeat, collectedWater;

public:
    PlayerResources();
    ~PlayerResources();

    int GetResource(std::string resourceName);

    void UpdateResources();
    int AddResources();
};

#endif
