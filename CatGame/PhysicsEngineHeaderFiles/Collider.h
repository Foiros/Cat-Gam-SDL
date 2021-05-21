//
// Created by arttu on 20/05/2021.
//

#ifndef CATGAMESDL_COLLIDER_H
#define CATGAMESDL_COLLIDER_H

#include "../SDLHeaderFiles/GameEntity.h"
#include "../SDLHeaderFiles/Texture.h"

using namespace SDL;

class Collider : public GameEntity{

public:
    enum class ColliderType{

        Box,
        Circle
    };

protected:
    ColliderType mType;

    static const bool DEBUG_COLLIDERS = true;
    Texture* mDebugTexture;

public:
    Collider(ColliderType type);
    virtual ~Collider();

    virtual Vector2 GetFurthestPoint() = 0;

    ColliderType GetType();

    virtual void Render();

protected:
    void SetDebugTexture(Texture* texture);
};

#endif //CATGAMESDL_COLLIDER_H
