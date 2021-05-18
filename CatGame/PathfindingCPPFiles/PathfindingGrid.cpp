//
// Created by arttu on 17/05/2021.
//

#include "../PathfindingHeaderFiles/PathfindingGrid.h"

PathfindingGrid::PathfindingGrid(int _width, int _height): width(_width), height(_height) {

}

PathfindingGrid::~PathfindingGrid() {

}

::std::vector<GridLocation> PathfindingGrid::GetNeighbors(GridLocation id){

    ::std::vector<GridLocation> results;

    for(GridLocation dir : directions){

        GridLocation next{id.locationX + dir.locationX, id.locationY + dir.locationY};

        if(InBounds(next) && Passable(next)){

            results.push_back(next);
        }
    }

    if((id.locationX + id.locationY) % 2 == 0){

        ::std::reverse(results.begin(), results.end());
    }

    return ::std::vector<GridLocation>();
}

bool PathfindingGrid::InBounds(GridLocation id) {

    return 0 <= id.locationX && id.locationX < width && 0 <= id.locationY && id.locationY < height;
}

bool PathfindingGrid::Passable(GridLocation id) {

    return false;
}


void PathfindingGrid::Render() {

    for (int y = 0; y != height; ++y) {

        for (int x = 0; x != width; ++x) {

            Graphics::Instance()->DrawDot(x, y);
        }
    }
}