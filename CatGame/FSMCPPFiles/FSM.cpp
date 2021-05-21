//
// Created by arttu on 21/05/2021.
//

#include "../FSMHeaderFiles/FSM.h"

namespace FSM{


    FSM::FSM(States startingState) {

        mCurrentState = startingState;
    }

    FSM::~FSM() {
    }

    void FSM::GiveState(int stateID) {

        switch (stateID) {

            case 0:
                SetState(FSM::States::Idle);
                break;

            case 1:
                SetState(FSM::States::NeedToScratch);
                break;

            case 2:
                SetState(FSM::States::Curious);
                break;

            case 3:
                SetState(FSM::States::Playful);
                break;

            case 4:
                SetState(FSM::States::Hungry);
                break;

            case 5:
                SetState(FSM::States::Thirsty);
                break;

            case 6:
                SetState(FSM::States::Dead);
                break;
        }
    }

    void FSM::SetState(FSM::States newState) {

        mCurrentState = newState;
    }

    FSM::States FSM::CurrentState() {

        return mCurrentState;
    }
}