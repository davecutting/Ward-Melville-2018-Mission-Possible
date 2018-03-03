/**
    IMA 7 Pulley Action - Mission Possible MK2
    Ward Melville HS Science Olympiad - Team A - 2017-2018
    imaSevenTiny.ino
    Purpose: Turns on a motor when the input is recieved. Turns it off when a switch is hit.

    @author David Cutting
    @version 1.0 1/22/2018
*/

// Definitions for microcontroller pin numbers
const int MOT_PIN_A = 0;
const int MOT_PIN_B = 1;
const int SWITCH_PIN = 2;
const int IN_PIN = 3;

void setup() {
  // Set the microcontroller pins as either inputs or outputs
  pinMode(SWITCH_PIN, INPUT);
  pinMode(IN_PIN, INPUT);
  pinMode(MOT_PIN_A, OUTPUT);
  pinMode(MOT_PIN_B, OUTPUT);

  // Lock the motor in place (connect the leads, essentially)
  digitalWrite(MOT_PIN_A, LOW);
  digitalWrite(MOT_PIN_B, LOW);
}

void loop() {
  if(digitalRead(SWITCH_PIN)) { // If the limit switch is pressed...
    // Turn the motor off (coast)
    digitalWrite(MOT_PIN_A, LOW);
    digitalWrite(MOT_PIN_B, LOW);
  }
  else if(digitalRead(IN_PIN)) {
    digitalWrite(MOT_PIN_A, LOW);
    digitalWrite(MOT_PIN_B, HIGH);
  }
}
