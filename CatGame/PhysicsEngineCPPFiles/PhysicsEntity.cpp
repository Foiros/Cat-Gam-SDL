//
// Created by arttu on 20/05/2021.
//

#include "../PhysicsEngineHeaderFiles/PhysicsEntity.h"
#include "../PhysicsEngineHeaderFiles/PhysicsManager.h"

PhysicsEntity::PhysicsEntity() {

    mBroadPhaseCollider = nullptr;
    mID = 0;
}

PhysicsEntity::~PhysicsEntity() {

    for (int i = 0; i < mColliders.size(); ++i) {

        delete mColliders[i];
        mColliders[i] = nullptr;
    }

    mColliders.clear();

    if(mBroadPhaseCollider){

        delete mBroadPhaseCollider;
        mBroadPhaseCollider = nullptr;
    }

    if(mID != 0){

        PhysicsManager::Instance()->UnRegisterEntity(mID);
    }
}

unsigned long PhysicsEntity::GetID() {

    return mID;
}

bool PhysicsEntity::CheckCollision(PhysicsEntity *other) {

    if(IgnoreCollisions() || other->IgnoreCollisions())
        return false;

    if(mBroadPhaseCollider != nullptr && other->mBroadPhaseCollider != nullptr)
        return ColliderColliderCheck(mBroadPhaseCollider, other->mBroadPhaseCollider);
}


void PhysicsEntity::ContactWithOtherCollider(PhysicsEntity *other) {

}

bool PhysicsEntity::IgnoreCollisions() {

    return false;
}

void PhysicsEntity::AddCollider(Collider *collider, Vector2 localPos) {

    collider->Parent(this);
    collider->Pos(localPos);
    mColliders.push_back(collider);

    if(mColliders.size() > 1 || mColliders[0]->GetType() != Collider::ColliderType::Circle){

        float furthestDistance = mColliders[0]->GetFurthestPoint().Magnitude();
        float distance;

        for (int i = 0; i < mColliders.size(); ++i) {

            distance = mColliders[i]->GetFurthestPoint().Magnitude();

            if(distance > furthestDistance){

                furthestDistance = distance;
            }
        }

        delete mBroadPhaseCollider;
        mBroadPhaseCollider = new CircleCollider(furthestDistance, true);
        mBroadPhaseCollider->Parent(this);
        mBroadPhaseCollider->Pos(VEC2_ZERO);
    }
}

void PhysicsEntity::Render() {

    for (int i = 0; i < mColliders.size(); ++i) {

        mColliders[i]->Render();
    }

    if(mBroadPhaseCollider)
        mBroadPhaseCollider->Render();
}


