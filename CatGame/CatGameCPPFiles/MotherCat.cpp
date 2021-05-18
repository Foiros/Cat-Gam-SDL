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
    mMoveBounds = Vector2(Graphics::Instance()->SCREEN_WIDTH, Graphics::Instance()->SCREEN_HEIGHT);

    mMotherSprite = new Texture("MotherCat.png");
    mMotherSprite->Parent();
    mMotherSprite->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));

    mRunAnimation = new AnimatedTexture("MotherCatWalkAnimation.png", 0, 0, 100, 100, 4, 1.0f, AnimatedTexture::horizontal);
    mRunAnimation->Parent(this);
    mRunAnimation->Pos(VEC2_ZERO);
    mRunAnimation->WrapMode(AnimatedTexture::once);
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

void MotherCat::Move(Vector2 newPos) {

    mMotherSprite->Translate(newPos, world);
}

void MotherCat::Visible(bool visible) {

    mVisible = visible;
}

bool MotherCat::IsAnimating() {

    return mAnimating;
}

void MotherCat::Update() {

}

void MotherCat::Render() {

    if(mVisible)
        mMotherSprite->Render();
}


