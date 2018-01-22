/**
    Endothermic Action - Mission Possible MK2
    Ward Melville HS Science Olympiad - Team A - 2017-2018
    endoTiny.ino
    Purpose: Triggers the next action when the resistance of a thermistor changes more than a threshold value.

    @author David Cutting
    @version 1.0 1/22/2018
*/

// Definitions for microcontroller pin numbers
const int THERMISTOR_PIN = 1;
const int OUT_PIN = 4;

// Variables for states of the pins
int thermistorValue;
int thermistorBase;
const int thermistorThreshold = 100;
bool outState = LOW;

void setup() {
  // Set the microcontroller pins as either inputs or outputs
  pinMode(THERMISTOR_PIN, INPUT);
  pinMode(OUT_PIN, OUTPUT);

  // Set the output pin to low
  digitalWrite(OUT_PIN, LOW); // Write the output pin to LOW

  // Read the initial value of the thermistor
  thermistorBase = analogRead(THERMISTOR_PIN);
}

void loop() {
  thermistorValue = analogRead(THERMISTOR_PIN);
  if(abs(thermistorValue - thermistorBase) >= thermistorThreshold) { 
    // If the difference between the current reading and the initial reading is greater than the threshold...
    digitalWrite(OUT_PIN, HIGH); // Trigger the next action
  }
}
