//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Meat.h"


Meat::Meat() {

    name = "Meat";

    int random = rand() % 50;
    value = random;

    sprite = new Texture("Meat.png");
    sprite->Parent(this);

    AddCollider(new BoxCollider(Vector2(50.0f, 50.0f)));
    mID = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Meat);
}

Meat::~Meat() {

    delete sprite;
    sprite = nullptr;
}

bool Meat::IgnoreCollisions() {

    return false;
}

void Meat::ContactWithOtherCollider(PhysicsEntity *other) {

    GatherResource();
}

void Meat::GatherResource() {

    Parent(nullptr);
}

void Meat::Render() {

    sprite->Render();
}
