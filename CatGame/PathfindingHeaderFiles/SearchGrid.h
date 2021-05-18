//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_SEARCHGRID_H
#define CATGAMESDL_SEARCHGRID_H

#include "PathfindingNode.h"
#include <vector>

class SearchGrid{

public:
    SearchGrid();
    ~SearchGrid();

    float GetG(const Position& fromPos, const Position& toPos);

    float GetH(const Position& fromPos, const Position& toPos);

    std::vector<Position> GetAdjancentNodes(int posX, int posY, int width, int height);
};

#endif
