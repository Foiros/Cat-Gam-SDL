//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_SEARCHLEVEL_H
#define CATGAMESDL_SEARCHLEVEL_H

#include "SearchNode.h"

class SearchLevel
{
public:
    SearchLevel(){}

    float GetG(const Position& fromPos, const Position& toPos)
    {
        float dX = (float)(toPos.first - fromPos.first);
        float dY = (float)(toPos.second - fromPos.second);
        float result = sqrtf(dX * dX + dY * dY);
        return result;
    }

    float GetH(const Position& fromPos, const Position& toPos)
    {
        float dX = (float)(toPos.first - fromPos.first);
        float dY = (float)(toPos.second - fromPos.second);
        return sqrtf(dX * dX + dY * dY);
    }
};

#endif
