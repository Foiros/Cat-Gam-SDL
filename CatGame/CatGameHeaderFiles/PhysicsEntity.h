//
// Created by arttu on 20/05/2021.
//

#ifndef CATGAMESDL_PHYSICSENTITY_H
#define CATGAMESDL_PHYSICSENTITY_H

#include "../SDLHeaderFiles/GameEntity.h"
#include "../CatGameHeaderFiles/PhysicsHelper.h"
#include <vector>


class PhysicsEntity : public GameEntity{

protected:
    unsigned long mID;

    std::vector<Collider*> mColliders;

    Collider* mBroadPhaseCollider;

public:
    PhysicsEntity();
    ~PhysicsEntity();

    unsigned long GetID();

    bool CheckCollision(PhysicsEntity* other);

    virtual void ContactWithOtherCollider(PhysicsEntity* other);

    virtual void Render();

protected:
    virtual bool IgnoreCollisions() = 0;

    void AddCollider(Collider* collider, Vector2 localPos = VEC2_ZERO);
};

#endif //CATGAMESDL_PHYSICSENTITY_H
