//
// Created by arttu on 19/05/2021.
//

#ifndef CATGAMESDL_PATHFINDINGUNIT_H
#define CATGAMESDL_PATHFINDINGUNIT_H

#include "../PhysicsEngineHeaderFiles/PhysicsEntity.h"
#include "../SDLHeaderFiles/Texture.h"
#include "../PathfindingHeaderFiles/Pathfinding.h"

using namespace SDL;
using namespace PhysicsEngine;

class PathfindingUnit : public PhysicsEntity{

protected:
    float mMoveSpeed;

    std::vector<GridLocation> path;
    GridLocation destination;
    bool mFollowingPath;

protected:
    void FindPath(PathfindingGrid* mGrid);
    void FollowPath(std::vector<GridLocation> path);
};

#endif //CATGAMESDL_PATHFINDINGUNIT_H
