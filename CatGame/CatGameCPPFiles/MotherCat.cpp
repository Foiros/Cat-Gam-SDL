//
// Created by arttu on 17/05/2021.
//

#include "../CatGameHeaderFiles/MotherCat.h"

MotherCat::MotherCat() {

    mTimer = Timer::Instance();
    mInputManager = InputManager::Instance();
    mAudioManager = AudioManager::Instance();

    mVisible = false;
    mAnimating = false;

    mMoveSpeed = 300.0f;

    mMotherSprite = new Texture("MotherCat.png");
    mMotherSprite->Parent(this);

    mRunAnimation = new AnimatedTexture("MotherCatWalkAnimation.png", 0, 0, 100, 100, 4, 1.0f, AnimatedTexture::horizontal);
    mRunAnimation->Parent(this);
    mRunAnimation->WrapMode(AnimatedTexture::once);

    AddCollider(new BoxCollider(Vector2(50.0f, 50.0f)));
    mID = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::MotherCat);
}

MotherCat::~MotherCat() {

    mTimer = nullptr;
    mInputManager = nullptr;
    mAudioManager = nullptr;

    delete mMotherSprite;
    mMotherSprite = nullptr;

    delete mRunAnimation;
    mRunAnimation = nullptr;
}

void MotherCat::Move() {

    if(mInputManager->KeyDown(SDL_SCANCODE_D)){

        Translate(VEC2_RIGHT * mMoveSpeed * mTimer->DeltaTime(), local);
    }
    else if(mInputManager->KeyDown(SDL_SCANCODE_A)){

        Translate(-VEC2_RIGHT * mMoveSpeed * mTimer->DeltaTime(), local);
    }
    else if(mInputManager->KeyDown(SDL_SCANCODE_W)){

        Translate(-VEC2_UP * mMoveSpeed * mTimer->DeltaTime(), local);
    }
    else if(mInputManager->KeyDown(SDL_SCANCODE_S)){

        Translate(VEC2_UP * mMoveSpeed * mTimer->DeltaTime(), local);
    }

//    Vector2 pos = Pos(local);
////    if(pos.x < mMoveBounds.x)
////        pos.x = mMoveBounds.x;
////    else if(pos.x > mMoveBounds.y)
////        pos.x = mMoveBounds.y;
//
//    Pos(pos);
}


void MotherCat::Visible(bool visible) {

    mVisible = visible;
}

bool MotherCat::IsAnimating() {

    return mAnimating;
}

bool MotherCat::IgnoreCollisions() {

    return !mVisible;
}

void MotherCat::ContactWithOtherCollider(PhysicsEntity *other) {

}


void MotherCat::Update() {

    if(Active())
        Move();
}

void MotherCat::Render() {

    if(mVisible)
        mMotherSprite->Render();
        mBroadPhaseCollider->Render();
}




