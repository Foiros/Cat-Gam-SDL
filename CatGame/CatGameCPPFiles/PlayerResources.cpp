//
// Created by arttu on 20/05/2021.
//

#include "../CatGameHeaderFiles/PlayerResources.h"

namespace CatGame{

    PlayerResources::PlayerResources() {

        collectedMeat = playerMinResource;
        collectedWater = playerMinResource;
    }

    PlayerResources::~PlayerResources() {

    }

    int PlayerResources::GetResource(std::string resourceName) {

        if(resourceName == "Meat")
            return collectedMeat;
        else
            return collectedWater;
    }

    void PlayerResources::AddResources(int addedMeat, int addedWater) {

        if(addedMeat != 0 && collectedMeat != playerMaxResource)
            collectedMeat += addedMeat;

        if(addedWater != 0 && collectedWater != playerMaxResource)
            collectedWater += addedWater;

        CorrectResources();
    }

    void PlayerResources::ReduceResources(int reducedMeat, int reducedWater) {

        if(reducedMeat != 0 && collectedMeat > playerMinResource)
            collectedMeat -= reducedMeat;

        if(reducedWater != 0 && collectedWater > playerMinResource)
            collectedWater -= reducedWater;

        CorrectResources();
    }

    void PlayerResources::CorrectResources() {

        if(collectedMeat > playerMaxResource)
            collectedMeat = playerMaxResource;
        else if(collectedMeat < playerMinResource)
            collectedMeat = playerMinResource;

        if(collectedWater > playerMaxResource)
            collectedWater = playerMaxResource;
        else if(collectedWater < playerMinResource)
            collectedWater = playerMinResource;
    }

}