//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Meat.h"


Meat::Meat() : Resource() {

    name = "Meat";
    sprite = new Texture("Meat.png");
    sprite->Parent(this);

    AddCollider(new BoxCollider(Vector2(50.0f, 50.0f)));
    mID = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Resource);
}

Meat::~Meat() {

    Resource::~Resource();
}
