/**
    Water Action - Mission Possible MK2
    Ward Melville HS Science Olympiad - Team A - 2017-2018
    waterTiny.ino
    Purpose: Triggers the next action when the resistance of a probe changes more than a threshold value.

    @author David Cutting
    @version 1.0 1/26/2018
*/

// Definitions for microcontroller pin numbers
const int PROBE_PIN = 2;
const int OUT_PIN = 4;

void setup() {
  // Set the microcontroller pins as either inputs or outputs
  pinMode(PROBE_PIN, INPUT);
  pinMode(OUT_PIN, OUTPUT);

  // Set the output pin to low
  digitalWrite(OUT_PIN, LOW); // Write the output pin to LOW
}

void loop() {
  if(!digitalRead(PROBE_PIN)) { 
    digitalWrite(OUT_PIN, HIGH); // Trigger the next action
  }
}
