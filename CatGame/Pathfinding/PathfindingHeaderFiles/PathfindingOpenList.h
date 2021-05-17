//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_PATHFINDINGOPENLIST_H
#define CATGAMESDL_PATHFINDINGOPENLIST_H

#include <algorithm>
#include "SearchNode.h"

class PathfindingOpenList{

private:
    typedef std::vector<SearchNode*> OpenListType;
    OpenListType openList;

public:
    SearchNode* FindFromOpenList(const Position& pos);

    void InsertToOpenList(SearchNode* n);

    void SortOpenList();

    SearchNode* RemoveSmallestFromOpenList();

    bool isEmpty();
    void ClearList();
};


#endif
