//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Meat.h"


Meat::Meat() : Resource() {

    name = "Meat";
    sprite = new Texture("Meat.png");
}

Meat::~Meat() {

    Resource::~Resource();
}
