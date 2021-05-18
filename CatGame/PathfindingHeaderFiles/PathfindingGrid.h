//
// Created by arttu on 17/05/2021.
//

#ifndef CATGAMESDL_PATHFINDINGGRID_H
#define CATGAMESDL_PATHFINDINGGRID_H

#include "../SDLHeaderFiles/MathHelper.h"
#include "../SDLHeaderFiles/GameEntity.h"
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iterator>
#include <algorithm>

using namespace SDL;

struct GridLocation{

    int locationX, locationY;
};

namespace std{

    template <> struct ::std::hash<GridLocation>{

        typedef GridLocation argument_type;

        typedef std::size_t _type;

        std::size_t operator()(const GridLocation& id) const noexcept{

            return std::hash<int>()(id.locationX ^ (id.locationY << 4));
        }
    };
}

class PathfindingGrid{

private:

    int width, height;

    // East, west, north, south
    const ::std::set<GridLocation> directions = {GridLocation{1, 0}, GridLocation{-1, 0},
                                                           GridLocation{0, -1},GridLocation{0, 1}};

    std::unordered_set<GridLocation> harshLand;

private:
    bool InBounds(GridLocation id);
    bool Passable(GridLocation id);

public:
    PathfindingGrid(int _width, int height);
    ~PathfindingGrid();

    std::vector<GridLocation> GetNeighbors(GridLocation id);

    double GetCost(GridLocation fromNode, GridLocation toNode);

    void Render(GridLocation motherCatLocation, std::vector<GridLocation> path);
};

inline bool operator == (GridLocation a, GridLocation b) {

    return a.locationX == b.locationX && a.locationY == b.locationY;
}

inline bool operator != (GridLocation a, GridLocation b) {

    return !(a == b);
}

inline bool operator < (GridLocation a, GridLocation b) {

    return ::std::tie(a.locationX, a.locationY) < ::std::tie(b.locationX, b.locationY);
}


#endif //CATGAMESDL_PATHFINDINGGRID_H
