//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Tree.h"

namespace CatGame{


    Tree::Tree() {

        sprite = new Texture("TreeProp.png");
        sprite->Parent(this);
    }

    Tree::~Tree() {

        delete sprite;
        sprite = nullptr;
    }

    void Tree::Render() {

        sprite->Render();
    }

    bool Tree::IgnoreCollisions() {

        return false;
    }

    void Tree::ContactWithOtherCollider(PhysicsEntity *other) {

        PhysicsEntity::ContactWithOtherCollider(other);
    }

}