//
// Created by arttu on 11/05/2021.
//

#ifndef SDLTUTORIAL_TIMER_H
#define SDLTUTORIAL_TIMER_H

#include <SDL.h>

namespace SDL{

    class Timer {

        // Variables
    private:

        static Timer* sInstance;

        unsigned int mStartTicks;
        unsigned int mElapsedTicks;
        float mDeltaTime;
        float mTimeScale;

        // Functions
    public:

        static Timer* Instance();
        static void Release();

        void Reset();
        float DeltaTime();

        void TimeScale(float t);
        float TimeScale();

        void Update();

    private:

        Timer();
        ~Timer();
    };
}

#endif
