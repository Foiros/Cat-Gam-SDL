//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Mouse.h"

namespace CatGame{


    Mouse::Mouse() {

        sprite = new Texture("Mouse.png");
        sprite->Parent(this);
    }

    Mouse::~Mouse() {

        delete sprite;
        sprite = nullptr;
    }

    void Mouse::Render() {

        sprite->Render();
    }

    bool Mouse::IgnoreCollisions() {

        return false;
    }

    void Mouse::ContactWithOtherCollider(PhysicsEntity *other) {

        PhysicsEntity::ContactWithOtherCollider(other);
    }
}