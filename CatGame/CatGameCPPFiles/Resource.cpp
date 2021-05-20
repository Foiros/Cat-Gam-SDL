//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Resource.h"



Resource::Resource() {

    int random = rand() % 50;
    value = random;
}

Resource::~Resource() {

    delete sprite;
    sprite = nullptr;
}

bool Resource::IgnoreCollisions() {

    return false;
}


int Resource::GatherResource() {

    return value;
}

void Resource::Update() {

}

void Resource::Render() {

    sprite->Render();
    mBroadPhaseCollider->Render();
}