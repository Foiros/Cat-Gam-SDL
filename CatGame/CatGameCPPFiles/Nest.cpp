//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Nest.h"

namespace CatGame{

    Nest::Nest() {

        meat = nestMinResource;
        water = nestMinResource;

        motherVisited = false;

        sprite = new Texture("Nest.png");
        sprite->Parent(this);

        AddCollider(new BoxCollider(Vector2(50.0f, 50.0f)));
        mID = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Nest);
    }

    Nest::~Nest() {

        delete sprite;
        sprite = nullptr;
    }

    bool Nest::IgnoreCollisions() {

        return false;
    }

    void Nest::ContactWithOtherCollider(PhysicsEntity* other) {

        if(other->GetID() == 1)
            motherVisited = true;
    }

    int Nest::GetResource(std::string resourceName) {

        if(resourceName == "Meat")
            return meat;
        else
            return water;
    }

    bool Nest::GetMotherVisited() {

        return motherVisited;
    }

    void Nest::AddResourcesToNest(int _meat, int _water) {

        if(_meat != 0 && meat != nestMaxResource)
            meat += _meat;

        if(_water != 0 && water != nestMaxResource)
            water += _water;

        CorrectResources();

        motherVisited = false;
    }

    void Nest::UseResources(int reducedMeat, int reducedWater) {

        if(reducedMeat != 0 && meat > nestMinResource)
            meat -= reducedMeat;

        if(reducedWater != 0 && water > nestMinResource)
            water -= reducedWater;

        CorrectResources();
    }

    void Nest::Render() {

        sprite->Render();
    }

    void Nest::CorrectResources() {

        if(meat > nestMaxResource)
            meat = nestMaxResource;
        else if(meat < nestMinResource)
            meat = nestMinResource;

        if(water > nestMaxResource)
            water = nestMaxResource;
        else if(water < nestMinResource)
            water = nestMinResource;
    }
}