//
// Created by arttu on 20/05/2021.
//

#include "../PhysicsEngineHeaderFiles/Collider.h"

namespace PhysicsEngine{

    Collider::Collider(Collider::ColliderType type) : mType(type) {

        mDebugTexture = nullptr;
    }

    Collider::~Collider() {

        if(mDebugTexture){

            delete mDebugTexture;
            mDebugTexture = nullptr;
        }
    }

    Collider::ColliderType Collider::GetType() {

        return mType;
    }

    void Collider::SetDebugTexture(Texture *texture) {

        delete mDebugTexture;
        mDebugTexture = texture;
        mDebugTexture->Parent(this);
    }

    void Collider::Render() {

        if(DEBUG_COLLIDERS){

            mDebugTexture->Render();
        }
    }
}