//
// Created by arttu on 20/05/2021.
//

#ifndef CATGAMESDL_KITTENNEEDS_H
#define CATGAMESDL_KITTENNEEDS_H

#include <string>

class KittenNeeds{

private:
    int hunger, thirst, love;

    const int kittenNeedMax = 100;
    const int kittenNeedMin = 0;
    const int kittenLoveStart = 25;

    const int reduceAmount = 3;
    const int loveIncrease = 3;

    bool hasGrownUp;
    bool hatesMom;

private:
    void CorrectNeeds();

public:
    KittenNeeds();
    ~KittenNeeds();

    int GetNeed(int need);
    void ReduceNeed(int need);
    void IncreaseNeed(int need, int amount);

    bool HasGrownUp();
    bool HatesMom();
};

#endif
