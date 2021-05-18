//
// Created by arttu on 17/05/2021.
//

#include "../PathfindingHeaderFiles/PathfindingOpenList.h"

PathfindingNode *PathfindingOpenList::FindFromOpenList(const Position &pos) {

    for (size_t i = 0; i < openList.size(); ++i)
    {
        if (openList[i]->pos == pos) return openList[i];
    }

    return 0;
}

void PathfindingOpenList::InsertToOpenList(PathfindingNode *n) {

    openList.push_back(n);
    SortOpenList();
}

void PathfindingOpenList::SortOpenList() {

    sort(openList.begin(), openList.end(), &PathfindingNode::lessThan);
}

PathfindingNode *PathfindingOpenList::RemoveSmallestFromOpenList() {

    PathfindingNode* result = *(openList.end() - 1);
    openList.pop_back();
    return result;
}

bool PathfindingOpenList::isEmpty(){

    return openList.empty();
}

void PathfindingOpenList::ClearList(){

    openList.clear();
}
