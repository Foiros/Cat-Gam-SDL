//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Water.h"

namespace CatGame{

    Water::Water(){

        std::random_device generator;
        std::uniform_int_distribution<int> distribution(10, 30);
        int random = distribution(generator);
        value = random;
        gathered = false;
        destroyed = false;

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

        if(!gathered)
            gathered = true;
        else
            gathered = false;
    }

    void Water::DestroyResource() {

        if(!destroyed)
            destroyed = true;
        else
            destroyed = false;
    }

    bool Water::GetGathered() const { return gathered; }

    bool Water::GetDestroyed() const { return destroyed; }

    int Water::GetValue() const { return value ; }

    void Water::Render() {

        sprite->Render();
    }
}