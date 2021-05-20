//
// Created by arttu on 19/05/2021.
//

#include "../PathfindingHeaderFiles/PathfindingUnit.h"

void PathfindingUnit::FindPath(PathfindingGrid *mGrid) {

//    int random1 = rand() % (500);
//    int random2 = rand() % (500);
//    destination = { random1, random2};

    destination = { 810, 540};

    GridLocation mKittenLocation = { (int) Pos(world).x, (int) Pos(world).y};

    std::unordered_map<GridLocation, GridLocation> came_from;
    std::unordered_map<GridLocation, double> cost_so_far;

    Pathfinding::Instance()->FindPath(mGrid, mKittenLocation, destination, came_from, cost_so_far);
    path = Pathfinding::Instance()->ReconstructPath(mKittenLocation, destination, came_from);

    mFollowingPath = true;

    came_from.clear();
    cost_so_far.clear();
}

void PathfindingUnit::FollowPath(std::vector<GridLocation> path) {

    GridLocation node = { path.begin()->locationX, path.begin()->locationY };
    path.erase(path.begin());
    this->path = path;

    Vector2 newPos = Vector2(node.locationX, node.locationY);
    Translate(newPos, world);

    if(node == destination){

        mFollowingPath = false;
        path.clear();
    }
}


