//
// Created by arttu on 20/05/2021.
//

#ifndef CATGAMESDL_PLAYERRESOURCES_H
#define CATGAMESDL_PLAYERRESOURCES_H

#include <string>

class PlayerResources{

private:
    int collectedMeat, collectedWater;

    const int playerMinResource = 0;
    const int playerMaxResource = 100;

public:
    PlayerResources();
    ~PlayerResources();

    int GetResource(std::string resourceName);
    void AddResources(int addedMeat, int addedWater);
    void ReduceResources(int reducedMeat, int reducedWater);
};

#endif
