//
// Created by arttu on 17/05/2021.
//

#include "../PathfindingHeaderFiles/SearchGrid.h"

SearchGrid::SearchGrid() {
}

SearchGrid::~SearchGrid() {
}


float SearchGrid::GetG(const Position &fromPos, const Position &toPos) {

    float dX = (float)(toPos.first - fromPos.first);
    float dY = (float)(toPos.second - fromPos.second);

    float result = sqrtf(dX * dX + dY * dY);

    return result;
}

float SearchGrid::GetH(const Position &fromPos, const Position &toPos) {

    float dX = (float)(toPos.first - fromPos.first);
    float dY = (float)(toPos.second - fromPos.second);

    return sqrtf(dX * dX + dY * dY);
}

std::vector<Position> SearchGrid::GetAdjancentNodes(int posX, int posY,int width, int height) {

    std::vector<Position> result;

    // if (IsWalkable(posX + 1, posY, width, height)) result.push_back(Position(posX + 1, posY));
    // if (IsWalkable(posX - 1, posY, width, height)) result.push_back(Position(posX - 1, posY));
    //if (IsWalkable(posX, posY + 1, width, height)) result.push_back(Position(posX, posY + 1));
    //if (IsWalkable(posX, posY - 1, width, height)) result.push_back(Position(posX, posY - 1));

    return result;
}
