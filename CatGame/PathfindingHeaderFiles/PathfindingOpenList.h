//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_PATHFINDINGOPENLIST_H
#define CATGAMESDL_PATHFINDINGOPENLIST_H

#include <algorithm>
#include "PathfindingNode.h"

class PathfindingOpenList{

private:
    typedef std::vector<PathfindingNode*> OpenListType;
    OpenListType openList;

public:
    PathfindingNode* FindFromOpenList(const Position& pos);

    void InsertToOpenList(PathfindingNode* n);

    void SortOpenList();

    PathfindingNode* RemoveSmallestFromOpenList();

    bool isEmpty();
    void ClearList();
};


#endif
