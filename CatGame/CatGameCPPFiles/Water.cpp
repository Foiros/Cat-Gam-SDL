//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Water.h"


Water::Water(){

    name = "Water";

    int random = rand() % 50;
    value = random;

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

    Parent(nullptr);
}

void Water::Render() {

    sprite->Render();
}
