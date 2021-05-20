//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Water.h"


Water::Water() : Resource() {

    name = "Water";
    sprite = new Texture("Water.png");
    sprite->Parent(this);

    AddCollider(new BoxCollider(Vector2(50.0f, 50.0f)));
    mID = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Resource);
}

Water::~Water() {

    Resource::~Resource();
}
