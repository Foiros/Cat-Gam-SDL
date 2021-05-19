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
    GridLocation destination;

    std::vector<GridLocation> path;
    bool mFollowingPath;

public:
    MotherCat();
    ~MotherCat();

    void Move(PathfindingGrid* mGrid);
    void FollowPath(std::vector<GridLocation> path);

    void Visible(bool visible);

    bool IsAnimating();

    void Update(PathfindingGrid* mGrid);

    void Render();
};

#endif //CATGAMESDL_MOTHERCAT_H
