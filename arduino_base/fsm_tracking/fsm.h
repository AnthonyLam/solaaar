/*
 *  Provides available states, does not provide next state behavior.
 */
#ifndef StateMachine.h
#define StateMachine.h

    #include "Arduino.h"


    class StateMachine {
        struct State {
                char stateValue;
                char stateOutput;
        }

        public:
            StateMachine();

            void nextState();
            State getCurrentState();

        private:
            State currentState;
            
            State rotateEast();
            State rotateWest();
            State sleep();
            State pan();
    }

#endif
