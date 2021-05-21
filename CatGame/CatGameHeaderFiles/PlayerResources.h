//
// Created by arttu on 20/05/2021.
//

#ifndef CATGAMESDL_PLAYERRESOURCES_H
#define CATGAMESDL_PLAYERRESOURCES_H

#include <string>

namespace CatGame{

    class PlayerResources{

    private:
        int collectedMeat, collectedWater;

        const int playerMinResource = 0;
        const int playerMaxResource = 100;

    private:
        void CorrectResources();

    public:
        PlayerResources();
        ~PlayerResources();

        int GetResource(std::string resourceName);
        void AddResources(int addedMeat, int addedWater);
        void ReduceResources(int reducedMeat, int reducedWater);
    };
}

#endif
