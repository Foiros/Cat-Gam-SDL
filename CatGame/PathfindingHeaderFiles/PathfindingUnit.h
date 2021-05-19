//
// Created by arttu on 19/05/2021.
//

#ifndef CATGAMESDL_PATHFINDINGUNIT_H
#define CATGAMESDL_PATHFINDINGUNIT_H

#include "../SDLHeaderFiles/GameEntity.h"
#include "../SDLHeaderFiles/Texture.h"
#include "../PathfindingHeaderFiles/Pathfinding.h"

using namespace SDL;

class PathfindingUnit : public GameEntity{

protected:
    float mMoveSpeed;

    std::vector<GridLocation> path;
    GridLocation destination;
    bool mFollowingPath;

protected:
    void FindPath(Texture* sprite, PathfindingGrid* mGrid);
    void FollowPath(Texture* sprite, std::vector<GridLocation> path);
};

#endif //CATGAMESDL_PATHFINDINGUNIT_H
