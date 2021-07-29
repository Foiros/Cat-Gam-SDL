//
// Created by arttu on 28/07/2021.
//

#include "../CatGameHeaderFiles/Wolf.h"

namespace CatGame{

    Wolf::Wolf(PathfindingGrid *_grid, KittenNeeds *_needs, Nest *_nest, Timer* _timer,
               std::vector<Vector2*> d1, std::vector<Vector2*> d2, std::vector<Meat*> meats, std::vector<Water*> waters) {

        wolfFSM = new WolfFSM(_grid, this, _needs, _nest, _timer, d1, d2, meats, waters);
        visible = false;

        wolfSprite = new Texture("Wolf.png");
        wolfSprite->Parent(this);

        AddCollider(new BoxCollider(Vector2(50.0f, 50.0f)));
        mID = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Wolf);
    }

    Wolf::~Wolf() {

        delete wolfSprite;
        wolfSprite = nullptr;
    }

    void Wolf::Visible(bool _visible) {

        visible = _visible;
    }

    bool Wolf::IgnoreCollisions() {

        return !visible;
    }

    void Wolf::ContactWithOtherCollider(PhysicsEntity *other) {

        PhysicsEntity::ContactWithOtherCollider(other);
    }

    void Wolf::Render() {

        if(visible)
            wolfSprite->Render();
    }

    void Wolf::Update(Vector2* kittenLocation) {

        wolfFSM->Update(kittenLocation);
    }
}

