//
// Created by arttu on 20/05/2021.
//

#ifndef CATGAMESDL_FSM_H
#define CATGAMESDL_FSM_H

namespace FSM{

    class FSM{

    public:

        enum class States{

            Idle,
            NeedToScratch,
            Curious,
            Playful,
            Hungry,
            Thirsty,
            Dead
        };

    private:
        States mCurrentState;

    public:
        FSM(States startingState);
        ~FSM();

        void GiveState(int stateID);
        void SetState(States newState);

        States CurrentState();
    };
}

#endif //CATGAMESDL_FSM_H
