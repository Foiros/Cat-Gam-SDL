//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_MOTHERCAT_H
#define CATGAMESDL_MOTHERCAT_H

#include "../SDLFramework/SDLHeaderFiles/GameEntity.h"
#include "../SDLFramework/SDLHeaderFiles/AnimatedTexture.h"
#include "../SDLFramework/SDLHeaderFiles/Texture.h"

using namespace SDL;

class MotherCat : public GameEntity {

private:
    Timer* mTimer;
    InputManager* mInputManager;
    AudioManager* mAudioManager;

    bool mVisible;
    bool mAnimating;

    Texture* mMotherSprite;

    AnimatedTexture* mRunAnimation;

    float mMoveSpeed;
    Vector2 mMoveBounds;

private:
    void Move();

public:
    MotherCat();
    ~MotherCat();

    void Visible(bool visible);

    bool IsAnimating();

    void Update();

    void Render();
};

#endif //CATGAMESDL_MOTHERCAT_H
