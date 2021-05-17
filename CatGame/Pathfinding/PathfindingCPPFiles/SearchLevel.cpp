//
// Created by arttu on 17/05/2021.
//

#include "../PathfindingHeaderFiles/SearchLevel.h"

SearchLevel::SearchLevel() {
}

SearchLevel::~SearchLevel() {
}


float SearchLevel::GetG(const Position &fromPos, const Position &toPos) {

    float dX = (float)(toPos.first - fromPos.first);
    float dY = (float)(toPos.second - fromPos.second);

    float result = sqrtf(dX * dX + dY * dY);

    return result;
}

float SearchLevel::GetH(const Position &fromPos, const Position &toPos) {

    float dX = (float)(toPos.first - fromPos.first);
    float dY = (float)(toPos.second - fromPos.second);

    return sqrtf(dX * dX + dY * dY);
}