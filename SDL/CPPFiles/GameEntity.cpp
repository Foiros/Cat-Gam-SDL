//
// Created by Arttu Paldán on 11/05/2021.
//

#include "../HeaderFiles/GameEntity.h"

namespace SDL{

    GameEntity::GameEntity(Vector2 pos) {

        mPos = pos;
        mRotation = 0.0f;
        mActive = true;
        mParent = NULL;
        mScale = VEC2_ONE;
    }

    GameEntity::~GameEntity() {

        mParent = NULL;
    }

    void GameEntity::Pos(Vector2 pos) {

        mPos = pos;
    }

    Vector2 GameEntity::Pos(SPACE space) {

        if(space == local || mParent == NULL)
            return mPos;

        Vector2 parentScale = mParent->Scale(world);
        Vector2 rotPos = RotateVector(Vector2(mPos.x * parentScale.x, mPos.y * parentScale.y), mParent->Rotation(local));

        // If parent is not null, so return parent position
        return mParent->Pos(world) + rotPos;
    }

    void GameEntity::Rotation(float rotation) {

        mRotation = rotation;

        // To keep the rotation between 0 and 360
        if(mRotation > 360.0f)
            mRotation -= 360.0f;

        if(mRotation < 0.0f)
            mRotation += 360.0f;
    }

    float GameEntity::Rotation(SPACE space) {
        if(space == local || mParent == NULL)
            return mRotation;

        return mParent->Rotation(world) + mRotation;
    }

    void GameEntity::Scale(Vector2 scale) {

        mScale = scale;
    }

    Vector2 GameEntity::Scale(SPACE space) {

        if(space == local || mParent == NULL)
            return mScale;

        Vector2 scale = mParent->Scale(world);
        scale.x *= mScale.x;
        scale.y *= mScale.y;

        return scale;
    }

    void GameEntity::Active(bool active) {

        mActive = active;
    }

    bool GameEntity::Active() {

        return mActive;
    }

    void GameEntity::Parent(GameEntity* parent) {

        if(parent == NULL){

            mPos = Pos(world);
            mRotation = Rotation(world);
            mScale = Scale(world);
        }
        else{

            if(mParent != NULL)
                Parent(NULL);

            Vector2 parentScale = parent->Scale(world);
            mPos.x /= parentScale.x;
            mPos.y /= parentScale.y;

            mRotation -= parent->Rotation(world);

            mScale = Vector2(mScale.x / parentScale.x, mScale.y / parentScale.y);
        }

        mParent = parent;
    }

    GameEntity* GameEntity::Parent(){ return mParent;}


    void GameEntity::Translate(Vector2 vector, SPACE space){

        if(space == world){

            mPos += vector;
        }
        else{

            mPos += RotateVector(vector, Rotation());
        }
    }

    void GameEntity::Rotate(float amount){

        Rotation(mRotation + amount);
    }


    void GameEntity::Update() {

    }

    void GameEntity::Render() {

    }
}