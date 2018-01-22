/**
    Coin Action - Mission Possible MK2
    Ward Melville HS Science Olympiad - Team A - 2017-2018
    coinTiny.ino
    Purpose: Triggers the next action based on the input from an NPN inductive probe.

    @author David Cutting
    @version 0.1 1/4/2018
*/

// Definitions for microcontroller pin numbers
const int PROBE_PIN = 2;
const int OUT_PIN = 4;

// Variables for states of the pins
bool probeState = HIGH;
bool outState = LOW;

// Variables and constants for the debounce code
unsigned int counter = 0;
const int DEBOUNCE_COUNT = 50;
long time = 0;

void setup() {
  // Set the microcontroller pins as either inputs or outputs
  pinMode(PROBE_PIN, INPUT);
  pinMode(OUT_PIN, OUTPUT);

  // Set the output pin to low
  digitalWrite(OUT_PIN, LOW); // Write the output pin to LOW
}

void loop() {
  if(millis() != time && outState == LOW) { // If more than one millisecond has elapsed since the last loop...
    probeState = digitalRead(PROBE_PIN); // Read the current state of the probe and store it

    if(probeState == LOW) { // If the state of the probe is low (quarter is present)...
      counter++; // Increment the counter
    }
    else { // Otherwise...  
       counter = 0; // Reset the counter
    }
    if(counter >= DEBOUNCE_COUNT) { //  If the counter is greater than the debounce threshold...
      counter = 0; // Reset the counter
      outState = HIGH; // Set the trigger state to high
      delay(800); // Delay 800 milliseconds (0.8 s) in addition to the 50 millisecond debounce and time for coin to flip to allow observation.
      digitalWrite(OUT_PIN, outState); // Set the output pin to the trigger state
    }
    time = millis(); // Record the current time in milliseconds  
  }
}
