//
// Created by arttu on 17/05/2021.
//

#include "../PathfindingHeaderFiles/PathfindingClosedList.h"

PathfindingClosedList::PathfindingClosedList() {

}

PathfindingClosedList::~PathfindingClosedList() {

}

void PathfindingClosedList::AddToClosedList(SearchNode *node) {

    closedList[node->pos] = node;
}

bool PathfindingClosedList::IsInClosedList(const Position &pos){

    return closedList.find(pos) != closedList.end();
}

void PathfindingClosedList::ClearList() {

    closedList.clear();
}
