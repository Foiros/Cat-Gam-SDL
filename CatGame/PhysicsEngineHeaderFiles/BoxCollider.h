//
// Created by arttu on 20/05/2021.
//

#ifndef CATGAMESDL_BOXCOLLIDER_H
#define CATGAMESDL_BOXCOLLIDER_H

#include "Collider.h"

namespace PhysicsEngine{

    class BoxCollider : public Collider{

    private:
        static const int MAX_VERTS = 4;

        GameEntity* mVerts[MAX_VERTS];

    public:
        BoxCollider(Vector2 size);
        ~BoxCollider();

        Vector2 GetFurthestPoint() override;

    private:
        void AddVert(int index, Vector2 pos);
    };
}

#endif //CATGAMESDL_BOXCOLLIDER_H
