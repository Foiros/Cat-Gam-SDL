//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_PATHFINDING_H
#define CATGAMESDL_PATHFINDING_H

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

private:

    static Pathfinding* sInstance;

public:
    // void DoPathFinding(int width, int height, int startX, int startY, int endX, int endY);

    static Pathfinding* Instance();
    static void Release();

    void FindPath();


private:
    Pathfinding();
    ~Pathfinding();
};

inline double Heuristic();

#endif