//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Water.h"


Water::Water() : Resource() {

    name = "Water";
    sprite = new Texture("Water.png");
}

Water::~Water() {

    Resource::~Resource();
}
