//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_PATHFINDINGCLOSEDLIST_H
#define CATGAMESDL_PATHFINDINGCLOSEDLIST_H

#include "PathfindingNode.h"
#include <map>

class PathfindingClosedList {

private:
    typedef std::map<Position, PathfindingNode*> ClosedListType;
    ClosedListType closedList;

public:
    PathfindingClosedList();
    ~PathfindingClosedList();

    void AddToClosedList(PathfindingNode* node);

    bool IsInClosedList(const Position& pos);

    void ClearList();
};

#endif