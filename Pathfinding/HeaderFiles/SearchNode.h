//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_SEARCHNODE_H
#define CATGAMESDL_SEARCHNODE_H

#include <vector>

typedef std::pair<int, int> Position;

class SearchNode
{
public:
    SearchNode* prevNode;
    Position pos;

    float G, H, F;

    SearchNode(const Position& currentPosition, float _H, float deltaG, SearchNode* prev) : prevNode(0), pos(currentPosition), G(0), H(_H)
    {
        ResetPrev(prev, deltaG);
    }

    void ResetPrev(SearchNode* prev, float deltaG)
    {
        prevNode = prev;
        if (prev == 0)
            G = 0.0f;
        else
            G = deltaG + prev->G;

        F = H + G;
    }

    float distance() const { return F; }

    static bool lessThan(SearchNode* n1, SearchNode* n2) { return n1->distance() > n2->distance(); }
};


#endif
