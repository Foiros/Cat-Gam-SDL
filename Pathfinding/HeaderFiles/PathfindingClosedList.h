//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_PATHFINDINGCLOSEDLIST_H
#define CATGAMESDL_PATHFINDINGCLOSEDLIST_H

#include "SearchNode.h"
#include <map>

class PathfindingClosedList {

public:
    PathfindingClosedList(){}

    void AddToClosedList(SearchNode* node) { closedList[node->pos] = node; }

    bool IsInClosedList(const Position& pos) { return closedList.find(pos) != closedList.end();}

    void ClearList(){ closedList.clear(); }

private:
    typedef std::map<Position, SearchNode*> ClosedListType;
    ClosedListType closedList;
};

#endif