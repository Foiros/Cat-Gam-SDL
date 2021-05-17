//
// Created by arttu on 17/05/2021.
//

#include "../PathfindingHeaderFiles/SearchNode.h"

SearchNode::SearchNode(const Position &currentPosition, float _H, float deltaG, SearchNode *prev) : prevNode(0), pos(currentPosition), G(0), H(_H){

    ResetPrev(prev, deltaG);
}

void SearchNode::ResetPrev(SearchNode *prev, float deltaG) {

    prevNode = prev;
    if (prev == 0)
        G = 0.0f;
    else
        G = deltaG + prev->G;

    F = H + G;
}

float SearchNode::distance() const {
    return F;
}

bool SearchNode::lessThan(SearchNode *n1, SearchNode *n2) {
    return n1->distance() > n2->distance();
}
