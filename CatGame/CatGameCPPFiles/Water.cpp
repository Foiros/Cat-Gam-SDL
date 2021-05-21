//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Water.h"


Water::Water(){

    int random = rand() % 50;
    value = random;
    gathered = false;

    sprite = new Texture("Water.png");
    sprite->Parent(this);

    AddCollider(new BoxCollider(Vector2(50.0f, 50.0f)));
    mID = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Water);
}

Water::~Water() {

    delete sprite;
    sprite = nullptr;
}

bool Water::IgnoreCollisions() {

    return false;
}

void Water::ContactWithOtherCollider(PhysicsEntity* other) {

    GatherResource();
}

void Water::GatherResource() {

    gathered = true;
}

bool Water::GetGathered() {

    return gathered;
}

int Water::GetValue() {

    return value ;
}

void Water::Render() {

    sprite->Render();
}

