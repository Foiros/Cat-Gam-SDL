//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Nest.h"

Nest::Nest() {

    meat = 0;
    water = 0;

    sprite = new Texture("Nest.png");
    sprite->Parent(this);
}

Nest::~Nest() {

    delete sprite;
    sprite = nullptr;
}

void Nest::Update() {


}

void Nest::Render() {

    sprite->Render();
}

int Nest::NestMeat() {

    return meat;
}

int Nest::NestWater() {

    return water;
}

void Nest::AddResourcesToNest(int _meat, int _water) {

    if(_meat != 0){

        meat += _meat;
    }

    if(_water != 0){

        water = _water;
    }
}

void Nest::UseResources(int reducedMeat, int reducedWater) {

    if(reducedMeat != 0){

        meat -= reducedMeat;
    }

    if(reducedWater != 0){

        water -= reducedWater;
    }
}
