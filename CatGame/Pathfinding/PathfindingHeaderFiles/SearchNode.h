//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_SEARCHNODE_H
#define CATGAMESDL_SEARCHNODE_H

#include <vector>

typedef std::pair<int, int> Position;

class SearchNode{

public:
    SearchNode* prevNode;
    Position pos;

    float G, H, F;

public:

    SearchNode(const Position& currentPosition, float _H, float deltaG, SearchNode* prev);

    void ResetPrev(SearchNode* prev, float deltaG);

    float distance() const;

    static bool lessThan(SearchNode* n1, SearchNode* n2);
};

#endif
