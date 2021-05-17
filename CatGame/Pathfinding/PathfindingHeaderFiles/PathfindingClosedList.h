//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_PATHFINDINGCLOSEDLIST_H
#define CATGAMESDL_PATHFINDINGCLOSEDLIST_H

#include "SearchNode.h"
#include <map>

class PathfindingClosedList {

private:
    typedef std::map<Position, SearchNode*> ClosedListType;
    ClosedListType closedList;

public:
    PathfindingClosedList();
    ~PathfindingClosedList();

    void AddToClosedList(SearchNode* node);

    bool IsInClosedList(const Position& pos);

    void ClearList();
};

#endif