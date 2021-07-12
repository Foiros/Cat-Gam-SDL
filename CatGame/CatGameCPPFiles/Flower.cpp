//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Flower.h"

namespace CatGame{


    Flower::Flower() {

        sprite = new Texture("FlowerProp.png");
        sprite->Parent(this);
    }

    Flower::~Flower() {

        delete sprite;
        sprite = nullptr;
    }

    void Flower::Render() {

        sprite->Render();
    }

    bool Flower::IgnoreCollisions() {

        return false;
    }

    void Flower::ContactWithOtherCollider(PhysicsEntity *other) {

        PhysicsEntity::ContactWithOtherCollider(other);
    }
}

