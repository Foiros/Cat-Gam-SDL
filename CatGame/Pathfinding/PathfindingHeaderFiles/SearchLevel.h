//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_SEARCHLEVEL_H
#define CATGAMESDL_SEARCHLEVEL_H

#include "SearchNode.h"

class SearchLevel{

public:
    SearchLevel();
    ~SearchLevel();

    float GetG(const Position& fromPos, const Position& toPos);

    float GetH(const Position& fromPos, const Position& toPos);
};

#endif
