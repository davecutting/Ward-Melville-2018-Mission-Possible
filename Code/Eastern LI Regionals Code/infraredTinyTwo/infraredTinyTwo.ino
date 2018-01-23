/**
    Infrared Action (Reciever) - Mission Possible MK2
    Ward Melville HS Science Olympiad - Team A - 2017-2018
    infraredTinyTwo.ino
    Purpose: Sets the output of the action high for one second when three leading edges are detected by an IR reciever.

    @author David Cutting
    @version 1.0 1/22/2018
*/

// Definitions for microcontroller pin numbers
const int IN_PIN = 2;
const int OUT_PIN = 4;

// Variables for states of the pins
bool inState = HIGH;
bool outState = LOW;

// Variables and constants for the pulse counter code
unsigned int pulseCounter = 0;

void setup() {
  // Set the microcontroller pins as either inputs or outputs
  pinMode(IN_PIN, INPUT);
  pinMode(OUT_PIN, OUTPUT);

  // Write the output pin low (off)
  digitalWrite(OUT_PIN, LOW);
}

void loop() {
  if(!outState && inState && !digitalRead(IN_PIN)) { // If the output hasn't triggered, the last input is high (off), and the current input is low (on)... 
    inState = LOW; // Set the input archive to low (on) 
    pulseCounter++; // Increment the pulse counter
  }
  else if(!outState && !inState && digitalRead(IN_PIN)) { // Otherwise, if the output hasn't triggered, the last input is low, and the current input is high...
    inState = HIGH; // Set the input archive to high (off)
  }
  if(pulseCounter >= 3 && !outState) { // If the pulse counter has been incremented three or more times...
    outState = HIGH; // Set the out state high
    digitalWrite(OUT_PIN, HIGH); // Set the out pin to the value of out state (in this case high), triggering the next action
    delay(1000); // Wait 1 second so electromagnet and reed switch in next action can be observed
    digitalWrite(OUT_PIN, LOW); // Turn off electromagnet to save power
  }
}
