//
// Created by arttu on 20/05/2021.
//

#ifndef CATGAMESDL_CIRCLECOLLIDER_H
#define CATGAMESDL_CIRCLECOLLIDER_H

#include "Collider.h"

class CircleCollider : public Collider{

private:
    float mRadius;

public:
    CircleCollider(float radius, bool broadPhase = false);
    ~CircleCollider();

    Vector2 GetFurthestPoint() override;

    float GetRadius();
};

#endif //CATGAMESDL_CIRCLECOLLIDER_H
