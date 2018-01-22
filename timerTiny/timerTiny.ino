/**
    Chemical Timer Action - Mission Possible MK2
    Ward Melville HS Science Olympiad - Team A - 2017-2018
    expTiny.ino
    Purpose: Turns on a motor when the input is recieved. Turns it off when a switch is hit.

    @author David Cutting
    @version 0.1 1/4/2018
*/

// Definitions for microcontroller pin numbers
const int MOT_PIN_A = 0;
const int MOT_PIN_B = 1;
const int PROBE_PIN = 2;

// Variables for states of the pins
bool outState = LOW;

void setup() {
  // Set the microcontroller pins as either inputs or outputs
  pinMode(MOT_PIN_A, OUTPUT);
  pinMode(MOT_PIN_B, OUTPUT);
  pinMode(PROBE_PIN, INPUT);

  // Set the output pin to low
  digitalWrite(MOT_PIN_A, LOW); // Write the output pin to LOW
  digitalWrite(MOT_PIN_B, HIGH); // Write the output pin to LOW
  delay(50);
  digitalWrite(MOT_PIN_A, LOW); // Write the output pin to LOW
  digitalWrite(MOT_PIN_B, LOW); // Write the output pin to LOW
}

void loop() {
  if(digitalRead(PROBE_PIN) && outState == LOW) { 
    // If the absolute value of the difference between the current reading and the initial reading is greater than the threshold...
    digitalWrite(MOT_PIN_A, HIGH); // Trigger the next action
    delay(100);
    digitalWrite(MOT_PIN_A, LOW); // Trigger the next action
    outState = HIGH;
  }
}
