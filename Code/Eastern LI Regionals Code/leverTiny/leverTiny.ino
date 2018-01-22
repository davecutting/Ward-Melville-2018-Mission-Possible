/**
    Lever Action - Mission Possible MK2
    Ward Melville HS Science Olympiad - Team A - 2017-2018
    leverTiny.ino
    Purpose: Turns on a MOSFET when the input is triggered. Turn it off after one second to prevent overheating.

    @author David Cutting
    @version 1.0 1/22/2018
*/

// Definitions for microcontroller pin numbers
const int IN_PIN = 3;
const int OUT_PIN = 2;

// Variables for states of the pins
bool inState = LOW;
bool outState = LOW;

// Variables and constants for the debounce code
unsigned int counter = 0;
const int DEBOUNCE_COUNT = 50;
long time = 0;

void setup() {
  // Set the microcontroller pins as either inputs or outputs
  pinMode(IN_PIN, INPUT);
  pinMode(OUT_PIN, OUTPUT);

  // Write the output pin low (off)
  digitalWrite(OUT_PIN, LOW);
}

void loop() {
  if(millis() != time && outState == LOW) { // If more than one millisecond has elapsed since the last loop...
    inState = digitalRead(IN_PIN); // Read the current state of the input and store it

    if(inState == HIGH) { // If the state of the input is high
      counter++; // Increment the counter
    }
    else { // Otherwise...  
       counter = 0; // Reset the counter
    }
    if(counter >= DEBOUNCE_COUNT) { //  If the counter is greater than the debounce threshold...
      counter = 0; // Reset the counter
      outState = HIGH; // Set the trigger state to high
      digitalWrite(OUT_PIN, outState); // Set the output pin to the trigger state
      delay(1000); // Wait 1 second to ensure that the solenoid moves and the next transfer gets the signal
      digitalWrite(OUT_PIN, LOW); // Set the output pin to low to disengage the solenoid and prevent overheating
    }
    time = millis(); // Record the current time in milliseconds  
  }
}
