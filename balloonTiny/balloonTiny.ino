/**
    Balloon Inflation Action - Mission Possible MK2
    Ward Melville HS Science Olympiad - Team A - 2017-2018
    balloonTiny.ino
    Purpose: Turns on a motor when the input is recieved. Turns it off when a switch is hit.

    @author David Cutting
    @version 0.1 1/4/2018
*/

// Definitions for microcontroller pin numbers
const int MOT_PIN_A = 0;
const int MOT_PIN_B = 1;
const int SWITCH_PIN = 2;
const int IN_PIN = 3;

// Variables for states of the pins
bool inState = LOW;
bool outState = LOW;

// Variables and constants for the debounce code
unsigned int inCounter = 0;
const int DEBOUNCE_COUNT = 50;
long time = 0;

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
  if(millis() != time && !outState) { // If more than one millisecond has elapsed since the last loop and the output has not been triggered...
    inState = digitalRead(IN_PIN); // Read the current state of the input and store it

    if(inState) { // If the state of the input is high
      inCounter++; // Increment the inCounter
    }
    else { // Otherwise...  
       inCounter = 0; // Reset the inCounter
    }
    if(inCounter >= DEBOUNCE_COUNT) { //  If the counter is greater than the debounce threshold...
      inCounter = 0; // Reset the inCounter
      outState = HIGH; // Set the trigger state to high
      // Turn on the motor
      digitalWrite(MOT_PIN_A, LOW);
      digitalWrite(MOT_PIN_B, HIGH);
    }
    time = millis(); // Record the current time in milliseconds  
  }

  if(digitalRead(SWITCH_PIN)) { // If the limit switch is pressed...
    // Turn the motor off (coast)
    digitalWrite(MOT_PIN_A, LOW);
    digitalWrite(MOT_PIN_B, LOW);
  }
}
