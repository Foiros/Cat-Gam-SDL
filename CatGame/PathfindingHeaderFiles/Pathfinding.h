//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_PATHFINDING_H
#define CATGAMESDL_PATHFINDING_H

#include "PathfindingGrid.h"

#include <stdint.h>
#include <stdio.h>
#include <cstdlib>
#include <assert.h>
#include <memory.h>
#include <algorithm>
#include <map>
#include <vector>
#include <unordered_map>
#include <queue>

class Pathfinding{

    template<typename T, typename priority_t>
    struct PriorityQueue{

        typedef std::pair<priority_t, T> PQElement;
        std::priority_queue<PQElement, std::vector<PQElement>, std::greater<PQElement>> elements;

        inline bool empty() const{

            return elements.empty();
        }

        inline void put(T item, priority_t priority){

            elements.emplace(priority, item);
        }

        T get(){

            T best_item = elements.top().second;
            elements.pop();
            return best_item;
        }
    };

private:
    static Pathfinding* sInstance;

public:
    static Pathfinding* Instance();
    static void Release();

    void FindPath(PathfindingGrid* graph, GridLocation start, GridLocation goal,
                  std::unordered_map<GridLocation, GridLocation>& cameFrom,
                  std::unordered_map<GridLocation, double>& costSoFar);

    std::vector<GridLocation> ReconstructPath(GridLocation start, GridLocation goal, std::unordered_map<GridLocation, GridLocation> cameFrom);

private:
    Pathfinding();
    ~Pathfinding();
};

inline double Heuristic(GridLocation a, GridLocation b){

    return std::abs(a.locationX - b.locationX) + std::abs(a.locationY - b.locationY);
}

#endif