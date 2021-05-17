//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_PATHFINDINGOPENLIST_H
#define CATGAMESDL_PATHFINDINGOPENLIST_H

#include <algorithm>
#include "SearchNode.h"

class PathfindingOpenList
{
public:
    SearchNode* FindFromOpenList(const Position& pos)
    {
        for (size_t i = 0; i < openList.size(); ++i)
        {
            if (openList[i]->pos == pos) return openList[i];
        }

        return 0;
    }

    void InsertToOpenList(SearchNode* n)
    {
        openList.push_back(n);
        SortOpenList();
    }

    void SortOpenList() { sort(openList.begin(), openList.end(), &SearchNode::lessThan); }

    SearchNode* RemoveSmallestFromOpenList()
    {
        SearchNode* result = *(openList.end() - 1);
        openList.pop_back();
        return result;
    }

    bool isEmpty() { return openList.empty(); }
    void ClearList() { openList.clear(); }

private:
    typedef std::vector<SearchNode*> OpenListType;
    OpenListType openList;
};


#endif
