#include <EEPROM.h>

int currentAngle = 0;

const unsigned int ANGLE_ADDR = 0;
const unsigned int WEST_PIN = ;
const unsigned int EAST_PIN = ;
const unsigned int LIGHT_PIN = ;
const unsigned int INTERRUPT_PIN = ;

const unsigned int STEPPER_PIN = ;

void setup(){
}

void loop(){
}

void lightSleep(){
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();
    sleep_mode();

    sleep_disable();
}

void deepSleep(){
    EEPROM.Write(ANGLE_ADDR,currentAngle);

    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    attachInterrupt(INTERRUPT_PIN,light_isr, LOW);

    sleep_mode();

    currentAngle = EEPROM.read(ANGLE_ADDR);
    sleep_disable();
}

void light_isr(){
    sleep_disable();
    detachInterrupt(INTERRUPT_PIN);
}

// Note: West designation is for convention purposes only
char sunIsWest(){
    int lightWest = analogRead(WEST_PIN);
    int lightEast = analogRead(EAST_PIN);
    return (lightWest > lightEast)? 8 : 0;
}

char lightBright(int threshhold){
    int lightWest = analogRead(WEST_PIN);
    int lightEast = analogRead(EAST_PIN);
    return 
}




