//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Nest.h"

Nest::Nest() {

    meat = 0;
    water = 0;

    sprite = new Texture("Nest.png");
    sprite->Parent(this);

    AddCollider(new BoxCollider(Vector2(50.0f, 50.0f)));
    mID = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Nest);
}

Nest::~Nest() {

    delete sprite;
    sprite = nullptr;
}

int Nest::NestMeat() {

    return meat;
}

int Nest::NestWater() {

    return water;
}

bool Nest::IgnoreCollisions() {

    return false;
}

void Nest::ContactWithOtherCollider(PhysicsEntity* other) {

    if(other->GetID() == 1){

        printf("Adding resources to base...");
        AddResourcesToNest(100, 100);
    }
    else if(other->GetID() == 2){

        printf("Kitten is feeding...");
        UseResources(20, 20);
    }
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

    if(reducedMeat != 0 && meat > 0){

        meat -= reducedMeat;
    }

    if(reducedWater != 0 && water > 0){

        water -= reducedWater;
    }
}

void Nest::Update() {

}

void Nest::Render() {

    sprite->Render();
}