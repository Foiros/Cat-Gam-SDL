//
// Created by arttu on 20/05/2021.
//

#include <iostream>
#include "../CatGameHeaderFiles/KittenNeeds.h"

namespace CatGame{

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

    void KittenNeeds::ReduceNeed(int need, int amount) {

        switch (need) {

            case 0:
                hunger -= reduceAmountHarsh;
                LoseLove();
                break;

            case 1:
                thirst -= reduceAmountEasy;
                LoseLove();
                break;

            case 2:
                love -= amount;
                break;
        }

        CorrectNeeds();
        HasGrownUp();
        HatesMom();
    }

    void KittenNeeds::IncreaseNeed(int need, int amount) {

        switch (need) {

            case 0:
                if(amount != 0 && hunger <= kittenNeedMax)
                    hunger += amount;
                break;

            case 1:
                if(amount != 0 && thirst <= kittenNeedMax)
                    thirst += amount;
                break;

            case 2:
                if(love >= kittenNeedMin && love <= kittenNeedMax)
                    love += loveIncrease;
                break;
        }

        CorrectNeeds();
        HasGrownUp();
        HatesMom();
    }

    void KittenNeeds::LoseLove() {

        int loveLoss = 0;

        if(hunger <= 25){

            loveLoss += 4;
        }
        else if(hunger <= 50 && hunger > 25){

            loveLoss += 3;
        }
        else if(hunger <= 75 && hunger > 50){

            loveLoss += 2;
        }
        else if(hunger <= 90 && hunger > 75){

            loveLoss += 1;
        }

        if(thirst <= 25){

            loveLoss += 4;
        }
        else if(thirst <= 50 && thirst > 25){

            loveLoss += 3;
        }
        else if(thirst <= 75 && thirst > 50){

            loveLoss += 2;
        }
        else if(thirst <= 90 && thirst > 75){

            loveLoss += 1;
        }

        ReduceNeed(2, loveLoss);
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


    void KittenNeeds::HasGrownUp() {

        if(love >= kittenNeedMax)
            hasGrownUp = true;
        else
            hasGrownUp = false;
    }

    void KittenNeeds::HatesMom() {

        if(love <= kittenNeedMin)
            hatesMom = true;
        else
            hatesMom = false;
    }

    bool KittenNeeds::GetGrownUp() const { return hasGrownUp; }

    bool KittenNeeds::GetHatesMom() const { return hatesMom; }
}