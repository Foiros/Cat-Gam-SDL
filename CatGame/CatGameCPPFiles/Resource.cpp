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

void Resource::GatherResource() {

}

void Resource::Render() {

    sprite->Render();
    mBroadPhaseCollider->Render();
}


