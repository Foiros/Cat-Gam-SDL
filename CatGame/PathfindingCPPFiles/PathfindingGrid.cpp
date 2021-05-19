//
// Created by arttu on 17/05/2021.
//

#include "../PathfindingHeaderFiles/PathfindingGrid.h"

PathfindingGrid::PathfindingGrid(int _width, int _height): width(_width), height(_height) {

    typedef GridLocation L;
    harshLand = std::unordered_set<GridLocation> {
            L{3, 4}, L{3, 5}, L{4, 1}, L{4, 2},
            L{4, 3}, L{4, 4}, L{4, 5}, L{4, 6},
            L{4, 7}, L{4, 8}, L{5, 1}, L{5, 2},
            L{5, 3}, L{5, 4}, L{5, 5}, L{5, 6},
            L{5, 7}, L{5, 8}, L{6, 2}, L{6, 3},
            L{6, 4}, L{6, 5}, L{6, 6}, L{6, 7},
            L{7, 3}, L{7, 4}, L{7, 5}
    };
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

    return results;
}

bool PathfindingGrid::InBounds(GridLocation id) {

    if(id.locationX <= width && id.locationX >= -width && id.locationY <= height && id.locationY >= -height){

        return true;
    }
    else{

        return false;
    }
    //return 0 <= id.locationX && id.locationX < width && 0 <= id.locationY && id.locationY < height;
}

bool PathfindingGrid::Passable(GridLocation id) {

    return true;
}

double PathfindingGrid::GetCost(GridLocation fromNode, GridLocation toNode) {

    return harshLand.find(toNode) != harshLand.end()? 5 : 1;
}

void PathfindingGrid::Render(GridLocation motherCatLocation, std::vector<GridLocation> path) {

    for (int y = 0; y != height; ++y) {

        for (int x = 0; x != width; ++x) {

            GridLocation id {x, y};

            if(id == motherCatLocation){

                Graphics::Instance()->DrawDot(x, y, 255, 0, 0);
            }
            else if(std::find(path.begin(), path.end(), id) != path.end()){

                Graphics::Instance()->DrawDot(x, y, 255, 255, 255);
            }
//            else{
//                Graphics::Instance()->DrawDot(x, y, 105, 105, 105);
//            }
        }
    }
}
