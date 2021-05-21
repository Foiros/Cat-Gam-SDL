//
// Created by arttu on 20/05/2021.
//

#include "../CatGameHeaderFiles/PlayerResources.h"


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
}

void PlayerResources::ReduceResources(int reducedMeat, int reducedWater) {

    if(reducedMeat != 0 && collectedMeat > playerMinResource)
        collectedMeat -= reducedMeat;

    if(reducedWater != 0 && collectedWater > playerMinResource)
        collectedWater -= reducedWater;
}
