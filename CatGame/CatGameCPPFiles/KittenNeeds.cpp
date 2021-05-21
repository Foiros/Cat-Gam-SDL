//
// Created by arttu on 20/05/2021.
//

#include "../CatGameHeaderFiles/KittenNeeds.h"


KittenNeeds::KittenNeeds() {

    hunger = kittenNeedMax;
    thirst = kittenNeedMax;
    love = kittenLoveStart;

    hasGrownUp = false;
    hatesMom = false;
}

KittenNeeds::~KittenNeeds() {

}

int KittenNeeds::GetNeed(int need) {

    switch (need) {

        case 0:
            return hunger;

        case 1:
            return thirst;

        case 2:
            return love;
    }
}

void KittenNeeds::ReduceNeed(int need) {

    switch (need) {

        case 0:
            hunger -= reduceAmount;
            break;

        case 1:
            thirst -= reduceAmount;
            break;

        case 2:
            love -= reduceAmount;
            break;
    }

    CorrectNeeds();
}

void KittenNeeds::IncreaseNeed(int need, int amount) {

    switch (need) {

        case 0:
            if(amount != 0 && hunger >= kittenNeedMax)
                hunger += amount;
            break;

        case 1:
            if(amount != 0 && thirst >= kittenNeedMax)
                thirst += amount;
            break;

        case 2:
            if(love <= kittenNeedMin || love >= kittenNeedMax)
                love += loveIncrease;
            break;
    }

    CorrectNeeds();
}

void KittenNeeds::CorrectNeeds() {

    if(hunger > kittenNeedMax)
        hunger = kittenNeedMax;
    else if(hunger < kittenNeedMin)
        hunger = kittenNeedMin;

    if(thirst > kittenNeedMax)
        thirst = kittenNeedMax;
    else if(thirst < kittenNeedMin)
        thirst = kittenNeedMin;

    if(love > kittenNeedMax)
        love = kittenNeedMax;
    else if(love < kittenNeedMin)
        love = kittenNeedMin;
}


bool KittenNeeds::HasGrownUp() {

    if(love >= kittenNeedMax)
        hasGrownUp = true;
    else
        hasGrownUp = false;

    return hasGrownUp;
}

bool KittenNeeds::HatesMom() {

    if(love <= kittenNeedMin)
        hatesMom = true;
    else
        hatesMom = false;

    return hatesMom;
}