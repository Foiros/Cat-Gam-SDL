//
// Created by arttu on 17/05/2021.
//

#include "../PathfindingHeaderFiles/Pathfinding.h"

Pathfinding* Pathfinding::sInstance = nullptr;

Pathfinding* Pathfinding::Instance() {

    if(sInstance == nullptr)
        sInstance = new Pathfinding();

    return sInstance;
}

void Pathfinding::Release() {

    delete sInstance;
    sInstance = nullptr;
}

Pathfinding::Pathfinding() {
}

Pathfinding::~Pathfinding() {

}

void Pathfinding::FindPath(PathfindingGrid* graph, GridLocation start, GridLocation goal,
                           std::unordered_map<GridLocation, GridLocation>& cameFrom,
                           std::unordered_map<GridLocation, double>& costSoFar) {

    PriorityQueue<GridLocation, double> frontier;
    frontier.put(start, 0);

    cameFrom[start] = start;
    costSoFar[start] = 0;

    while(!frontier.empty()){

        GridLocation current = frontier.get();

        if(current == goal){

            break;
        }

        for(GridLocation next : graph->GetNeighbors(current)){

            double newCost = costSoFar[current] + graph->GetCost(current, next);

            if(costSoFar.find(next) == costSoFar.end() || newCost < costSoFar[next]){

                costSoFar[next] = newCost;
                double priority = newCost + Heuristic(next, goal);
                frontier.put(next, priority);
                cameFrom[next] = current;
            }
        }
    }
}

std::vector<GridLocation> Pathfinding::ReconstructPath(GridLocation start, GridLocation goal,
                                                       std::unordered_map<GridLocation, GridLocation> cameFrom) {

    std::vector<GridLocation> path;
    GridLocation current = goal;

    while(current != start){

        path.push_back(current);
        current = cameFrom[current];
    }

    path.push_back(start);
    std::reverse(path.begin(), path.end());

    return path;
}