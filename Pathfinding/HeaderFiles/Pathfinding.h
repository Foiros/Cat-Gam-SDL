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

class Pathfinding
{
public:
    Pathfinding(){}

    uint8_t* GetPixel(int x, int y, uint8_t* data, int width)
    {
        return &data[3 * (y * width + x)];
    }

    void SetPixel(int x, int y, uint8_t* data, int width, uint8_t r, uint8_t g, uint8_t b)
    {
        uint8_t* pixel = GetPixel(x, y, data, width);
        pixel[0] = b;
        pixel[1] = g;
        pixel[2] = r;
    }

    bool isGreen(int x, int y, uint8_t* data, int width)
    {
        uint8_t* pixel = GetPixel(x, y, data, width);
        return pixel[1] > 200 && pixel[0] < 50 && pixel[2] < 50;
    }

    bool IsWalkable(int posX, int posY, uint8_t* inputData, int widht, int height)
    {
        if (posX < 0 || posY < 0 || posX >= widht || posY >= height) return false;

        unsigned char* pixel = GetPixel(posX, posY, inputData, widht);
        bool isNotWalkable = isGreen(posX, posY, inputData, widht);
        return !isNotWalkable;
    }

    std::vector<Position> GetAdjancentNodes(int posX, int posY, uint8_t* inputData, int widht, int height)
    {
        std::vector<Position> result;

        if (IsWalkable(posX + 1, posY, inputData, widht, height)) result.push_back(Position(posX + 1, posY));
        if (IsWalkable(posX - 1, posY, inputData, widht, height)) result.push_back(Position(posX - 1, posY));
        if (IsWalkable(posX, posY + 1, inputData, widht, height)) result.push_back(Position(posX, posY + 1));
        if (IsWalkable(posX, posY - 1, inputData, widht, height)) result.push_back(Position(posX, posY - 1));

        return result;
    }

    void DoPathFinding(uint8_t* inputData, int width, int height, uint8_t* outputData, int startX, int startY, int endX, int endY)
    {
        printf("Do pathfinding from <%d, %d> to <%d, %d\n", startX, startY, endX, endY);

        memcpy(outputData, inputData, 3 * width * height);

        // mustaa koko bittikartta
        memset(outputData, 0, 3 * width * height);

        // sininen pikseli kohtaan 0,0
        SetPixel(0, 0, outputData, width, 0, 0, 255);

        // magenta pikseli kohtaan 0,0
        SetPixel(width - 1, height - 1, outputData, width, 255, 0, 255);

        SearchLevel searchLevel;
        PathfindingOpenList openList;
        PathfindingClosedList closedList;

        Position startPos(startX, startY);
        Position endPos(endX, endY);

        SearchNode* start = new SearchNode(startPos, searchLevel.GetG(startPos, endPos), searchLevel.GetH(startPos, endPos), 0);

        openList.InsertToOpenList(start);// Add start node to open list

        SearchNode* result = 0; // Save possible A* result here

        while (sizeof(openList) > 0)
        {
            SearchNode* N = openList.RemoveSmallestFromOpenList(); // Pop lowest f-cost from open list
            closedList.AddToClosedList(N); // Add it to the closed list

            // Has reached destination?
            if (N->pos.first == endPos.first && N->pos.second == endPos.second)
            {
                result = N;
                break;
            }

            std::vector<Position> adjacentPositions = GetAdjancentNodes(N->pos.first, N->pos.second, inputData, width, height); // Get neighbour nodes, where we can walk

            for (Position pos : adjacentPositions)
            {
                // If already at the closed list, ignore it
                if (closedList.IsInClosedList(pos)) { continue; }

                if (openList.FindFromOpenList(pos))
                {
                    openList.FindFromOpenList(pos)->pos = pos;
                    SearchNode* N_ = new SearchNode(pos, searchLevel.GetG(N->pos, pos), searchLevel.GetH(N->pos, pos), N); // We came to N_-node from N-node.

                    // Found from open list, if new F is smaller than prev route to this position, reset prev node from this route
                    if (searchLevel.GetG(pos, N_->pos) > searchLevel.GetG(N_->pos, pos))
                    {
                        N->prevNode = N_;
                    }

                    delete N_;
                }
                else
                {
                    SearchNode* N_ = new SearchNode(pos, searchLevel.GetG(N->pos, pos), searchLevel.GetH(N->pos, pos), N); // We came to N_-node from N-node.
                    N = N_;
                    openList.InsertToOpenList(N);
                }
            }

            // Sort open list by ascending order by F-cost.
            openList.SortOpenList();
        }

        if (result != 0)
        {
            printf("\nPath found:\n");

            while (result != 0)
            {
                SetPixel(result->pos.first, result->pos.second, outputData, width, 0, 0, 255); // Mark path to the level
                result = result->prevNode;
            }
        }
        else { printf("\nPath not found!\n"); }


        // Remember to cleanup. i.e. call delete to each node in open and closed lists.
        openList.ClearList();
        closedList.ClearList();
    }
};

#endif
