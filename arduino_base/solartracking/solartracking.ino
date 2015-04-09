#include <Servo.h>
#include "math.h"

#define SENSOR1 0
#define SENSOR2 1
#define SERVO 9

Servo myservo;
int sensor1;
int sensor2;
int diff;
int spd;
int sensitivity;
int tilt;

void setup () {
  myservo.attach(SERVO); // attaches the servo on pin 9 to the servo object
  sensitivity = 5; // this controls the sensitivity of the tracker. lower number = sharper eventual angle the panel will be turned to.  perhaps some scaling according to the 0..1024 range might be more helpful
  Serial.begin(9600); // open serial com
  Serial.print("SolarTracker ready!");

  pinMode(SENSOR1, INPUT); // set the inputs
  pinMode(SENSOR2, INPUT);
}


// this all assumes we are using a continuous rotation servo, (with 0 being full-speed in one direction, 180 being full speed in the other, and a value near 90 being no movement).
void loop () {

//-------------------------------------------------- 
// Read input values
//-------------------------------------------------- 
  tilt = myservo.read();
  sensor1 = analogRead(SENSOR1); // read the photoresistor output
  sensor2 = analogRead(SENSOR2);

//--------------------------------------------------
// Calculations
//--------------------------------------------------
  diff = sensor1 - sensor2; // this judges how far the tracker must turn
  spd = diff / 10; // and adjusts the speed of the reaction accordingly.  again, scaling according to the 0..1024 range might be more helpful here.

  Serial.print("\nFIRST: "); Serial.print(sensor1, DEC); // print the sensor values to the serial com
  Serial.print("\tSECOND:"); Serial.print(sensor2, DEC);

  if (abs(diff) <= sensitivity) { // if the value of the first sensor is smaller (more light) than the the value of the second sensor and the tilt sensor is in the correct range
    myservo.write(tilt + signOf(diff)*spd); // send servo command to turn upward plus add speed
    Serial.print("\tState: ");
    Serial.print("UP!");
  }
  else { // for every other instance
      myservo.write(tilt); // stop the motor
      Serial.print("\tState: ");
      Serial.print("STOP!");
   }
  

  delay(10); // we should find out how often the arduino needs to check/track, how quickly the servo will reach its target
}

// Find the sign of an integer
int signOf(int var) {
    if( !var ) {
        return 0;
    } else {
        return var/abs(var);
    }
}
