//
// Created by arttu on 20/05/2021.
//

#ifndef CATGAMESDL_KITTENNEEDS_H
#define CATGAMESDL_KITTENNEEDS_H

#include <string>

class KittenNeeds{

private:
    int hunger, thirst, love;

public:
    KittenNeeds();
    ~KittenNeeds();

    int GetNeed(std::string resource);

    void UpdateNeed();
    int ReduceNeed();
    int IncreaseNeed();

    void HasGrownUp();
};

#endif
