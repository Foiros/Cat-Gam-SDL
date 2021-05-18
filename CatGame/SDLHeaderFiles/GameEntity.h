//
// Created by arttu on 11/05/2021.
//

#ifndef SDLTUTORIAL_GAMEENTITY_H
#define SDLTUTORIAL_GAMEENTITY_H

#include "MathHelper.h"
#include "Timer.h"
#include "InputManager.h"
#include "AudioManager.h"

namespace SDL{

    class GameEntity {

        //Variables
    public:

        enum SPACE {local = 0, world = 1};

        void Parent(GameEntity* parent);

    private:

        Vector2 mPos;
        float mRotation;
        Vector2 mScale;

        bool mActive;
        GameEntity* mParent;

        // Functions
    public:

        GameEntity(Vector2 pos = VEC2_ZERO);
        ~GameEntity();

        void Pos(Vector2 pos);
        Vector2 Pos(SPACE space = world);

        void Rotation(float rotation);
        float Rotation(SPACE space = world);

        void Scale(Vector2 scale);
        Vector2 Scale(SPACE space = world);

        void Active(bool active);
        bool Active();

        GameEntity* Parent();

        void Translate(Vector2 vector, SPACE space);
        void Rotate(float amount);

        virtual void Update();
        virtual void Render();
    };
}

#endif
