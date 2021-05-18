//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_MOTHERCAT_H
#define CATGAMESDL_MOTHERCAT_H

#include "../SDLHeaderFiles/GameEntity.h"
#include "../SDLHeaderFiles/AnimatedTexture.h"
#include "../SDLHeaderFiles/Texture.h"
#include "../PathfindingHeaderFiles/Pathfinding.h"

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


public:
    MotherCat();
    ~MotherCat();

    void Move(Vector2 newPos);

    void Visible(bool visible);

    bool IsAnimating();

    void Update();

    void Render();
};

#endif //CATGAMESDL_MOTHERCAT_H
