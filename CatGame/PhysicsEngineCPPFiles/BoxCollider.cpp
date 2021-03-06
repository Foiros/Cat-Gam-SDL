//
// Created by arttu on 20/05/2021.
//

#include "../PhysicsEngineHeaderFiles/BoxCollider.h"

namespace PhysicsEngine{

    BoxCollider::BoxCollider(Vector2 size) : Collider(ColliderType::Box) {

        AddVert(0, Vector2(-0.5f * size.x, -0.5f * size.y));
        AddVert(1, Vector2(0.5f * size.x, -0.5f * size.y));
        AddVert(2, Vector2(-0.5f * size.x, 0.5f * size.y));
        AddVert(3, Vector2(0.5f * size.x, 0.5f * size.y));

        if(DEBUG_COLLIDERS){

            SetDebugTexture(new Texture("BoxCollider.png"));
            mDebugTexture->Scale(size / 100.0f);
        }
    }

    BoxCollider::~BoxCollider() {

        for (int i = 0; i < MAX_VERTS; ++i) {

            delete mVerts[i];
            mVerts[i] = nullptr;
        }
    }

    Vector2 BoxCollider::GetFurthestPoint() {

        Vector2 localPos = Pos(GameEntity::local);

        int furthestIndex = 0;
        float distance = (localPos + mVerts[0]->Pos(GameEntity::local)).MagnitudeSqr();
        float otherDistance;

        for (int i = 0; i < MAX_VERTS; ++i) {

            otherDistance = (localPos + mVerts[i]->Pos(GameEntity::local)).MagnitudeSqr();

            if(otherDistance > distance){

                furthestIndex = i;
                distance = otherDistance;
            }
        }

        return localPos + mVerts[furthestIndex]->Pos(GameEntity::local);
    }

    void BoxCollider::AddVert(int index, Vector2 pos) {

        mVerts[index] = new GameEntity(pos);
        mVerts[index]->Parent(this);
    }
}