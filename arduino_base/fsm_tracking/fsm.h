#ifndef StateMachine.h
#define StateMachine.h

    #include "Arduino.h"


    class StateMachine {
        public:
            StateMachine();
            
            void nextState();

        private:
            struct State {
                char stateValue;
                char stateOutput;
            }
            State rotateEast();
            State rotateWest();
            State sleep();
            State pan();
    }

#endif
