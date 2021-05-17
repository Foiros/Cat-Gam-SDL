//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_PATHFINDING_H
#define CATGAMESDL_PATHFINDING_H

#include "SearchLevel.h"
#include "PathfindingOpenList.h"
#include "PathfindingClosedList.h"

#include <stdint.h>
#include <stdio.h>
#include <cstdlib>
#include <assert.h>
#include <memory.h>
#include <algorithm>
#include <map>
#include <vector>

class Pathfinding{

public:
    Pathfinding();
    ~Pathfinding();

    uint8_t* GetPixel(int x, int y, uint8_t* data, int width);

    void SetPixel(int x, int y, uint8_t* data, int width, uint8_t r, uint8_t g, uint8_t b);

    bool isGreen(int x, int y, uint8_t* data, int width);

    bool IsWalkable(int posX, int posY, uint8_t* inputData, int widht, int height);

    std::vector<Position> GetAdjancentNodes(int posX, int posY, uint8_t* inputData, int widht, int height);

    void DoPathFinding(int width, int height, int startX, int startY, int endX, int endY);
};

#endif
