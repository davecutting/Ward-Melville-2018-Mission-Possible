/**
    Water Action - Mission Possible MK2
    Ward Melville HS Science Olympiad - Team A - 2017-2018
    waterTiny.ino
    Purpose: Triggers the next action when the resistance of a probe changes more than a threshold value.

    @author David Cutting
    @version 0.2 1/16/2018
*/

// Definitions for microcontroller pin numbers
const int PROBE_PIN = 1;
const int OUT_PIN = 4;

// Variables for states of the pins
int probeValue;
int probeBase;
const int probeThreshold = 100;
bool outState = LOW;

void setup() {
  // Set the microcontroller pins as either inputs or outputs
  pinMode(PROBE_PIN, INPUT);
  pinMode(OUT_PIN, OUTPUT);

  // Set the output pin to low
  digitalWrite(OUT_PIN, LOW); // Write the output pin to LOW

  // Read the initial value of the probe
  probeBase = analogRead(PROBE_PIN);
}

void loop() {
  probeValue = analogRead(PROBE_PIN);
  if(abs(probeBase - probeValue) >= probeThreshold) { 
    // If the absolute value of the difference between the current reading and the initial reading is greater than the threshold...
    digitalWrite(OUT_PIN, HIGH); // Trigger the next action
  }
}
