//
// Created by arttu on 17/05/2021.
//

#include "../PathfindingHeaderFiles/Pathfinding.h"

Pathfinding::Pathfinding() {

}

Pathfinding::~Pathfinding() {

}

void Pathfinding::DoPathFinding(int width, int height, int startX, int startY, int endX, int endY) {

    printf("Do pathfinding from <%d, %d> to <%d, %d\n", startX, startY, endX, endY);
    
    SearchLevel* searchLevel = new SearchLevel;
    PathfindingOpenList* openList = new PathfindingOpenList;
    PathfindingClosedList* closedList = new PathfindingClosedList;

    Position startPos(startX, startY);
    Position endPos(endX, endY);

    SearchNode* start = new SearchNode(startPos, searchLevel->GetG(startPos, endPos), searchLevel->GetH(startPos, endPos), 0);

    openList->InsertToOpenList(start);// Add start node to open list

    SearchNode* result = 0; // Save possible A* result here

    while (sizeof(openList) > 0)
    {
        SearchNode* N = openList->RemoveSmallestFromOpenList(); // Pop lowest f-cost from open list
        closedList->AddToClosedList(N); // Add it to the closed list

        // Has reached destination?
        if (N->pos.first == endPos.first && N->pos.second == endPos.second)
        {
            result = N;
            break;
        }

        std::vector<Position> adjacentPositions = GetAdjancentNodes(N->pos.first, N->pos.second, width, height); // Get neighbour nodes, where we can walk

        for (Position pos : adjacentPositions)
        {
            // If already at the closed list, ignore it
            if (closedList->IsInClosedList(pos)){

                continue;
            }

            if (openList->FindFromOpenList(pos))
            {

                openList->FindFromOpenList(pos)->pos = pos;
                SearchNode* N_ = new SearchNode(pos, searchLevel->GetG(N->pos, pos), searchLevel->GetH(N->pos, pos), N); // We came to N_-node from N-node.

                // Found from open list, if new F is smaller than prev route to this position, reset prev node from this route
                if (searchLevel->GetG(pos, N_->pos) > searchLevel->GetG(N_->pos, pos))
                {
                    N->prevNode = N_;
                }

                delete N_;
            }
            else
            {
                SearchNode* N_ = new SearchNode(pos, searchLevel->GetG(N->pos, pos), searchLevel->GetH(N->pos, pos), N); // We came to N_-node from N-node.
                N = N_;
                openList->InsertToOpenList(N);
            }
        }

        // Sort open list by ascending order by F-cost.
        openList->SortOpenList();
    }

    if (result != 0)
    {
        printf("\nPath found:\n");

        while (result != 0)
        {
            SetPixel(result->pos.first, result->pos.second, width, 0, 0, 255); // Mark path to the level
            result = result->prevNode;
        }
    }
    else { printf("\nPath not found!\n"); }


    // Remember to cleanup. i.e. call delete to each node in open and closed lists.
    openList->ClearList();
    closedList->ClearList();

    searchLevel = nullptr;
    openList = nullptr;
    closedList = nullptr;
}


