//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Meat.h"

namespace CatGame{

    Meat::Meat() {

        std::random_device generator;
        std::uniform_int_distribution<int> distribution(10, 30);
        int random = distribution(generator);
        value = random;
        gathered = false;

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

        if(!gathered)
            gathered = true;
        else
            gathered = false;
    }


    bool Meat::GetGathered() {

        return gathered;
    }

    int Meat::GetValue() {

        return value;
    }

    void Meat::Render() {

        sprite->Render();
    }
}
