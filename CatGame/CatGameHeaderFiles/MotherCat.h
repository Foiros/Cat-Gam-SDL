//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_MOTHERCAT_H
#define CATGAMESDL_MOTHERCAT_H

#include "../SDLHeaderFiles/AnimatedTexture.h"
#include "../SDLHeaderFiles/Texture.h"
#include "../CatGameHeaderFiles/PhysicsEntity.h"
#include "../CatGameHeaderFiles/PhysicsManager.h"

using namespace SDL;

class MotherCat : public PhysicsEntity{

private:
    Timer* mTimer;
    InputManager* mInputManager;
    AudioManager* mAudioManager;

    bool mVisible;
    bool mAnimating;

    Texture* mMotherSprite;

    AnimatedTexture* mRunAnimation;

    float mMoveSpeed;

private:
    bool IgnoreCollisions() override;
    void Move();

public:
    MotherCat();
    ~MotherCat();

    void ContactWithOtherCollider(PhysicsEntity* other) override;

    void Visible(bool visible);
    bool IsAnimating();

    void Update();
    void Render();
};

#endif //CATGAMESDL_MOTHERCAT_H
