//
// Created by arttu on 20/05/2021.
//

#ifndef CATGAMESDL_PHYSICSHELPER_H
#define CATGAMESDL_PHYSICSHELPER_H

#include "../CatGameHeaderFiles/BoxCollider.h"
#include "../SDLHeaderFiles/MathHelper.h"

//inline bool CircleCircleCollision(CircleCollider* c1, CircleCollider* c2){
//
//    return (c1->Pos() - c2->Pos()).Magnitude() < (c1->GetRadius() + c2->GetRadius());
//}

//inline bool ColliderColliderCheck(Collider* c1, Collider* c2){
//
//    if(c1->GetType() == Collider::ColliderType::Circle && c2->GetType() == Collider::ColliderType::Circle)
//        return CircleCircleCollision(static_cast<CircleCollider*>(c1), static_cast<CircleCollider*>(c2));
//}

#endif //CATGAMESDL_PHYSICSHELPER_H
