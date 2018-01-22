/**
    Infrared Action (Transmitter) - Mission Possible MK2
    Ward Melville HS Science Olympiad - Team A - 2017-2018
    infraredTinyOne.ino
    Purpose: Sends a message comprosed of three 100 millisecond pulses separated by 100 milliseconds using an infrared LED.

    @author David Cutting
    @version 0.1 1/4/2018
*/

// Definitions for microcontroller pin numbers
const int IN_PIN = 3;
const int LED_PIN = 1;

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
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  if(millis() != time && outState == LOW) { // If more than one millisecond has elapsed since the last loop...
    inState = digitalRead(IN_PIN); // Read the current state of the probe and store it

    if(inState == HIGH) { // If the state of the probe is low (quarter is present)...
      counter++; // Increment the counter
    }
    else { // Otherwise...  
       counter = 0; // Reset the counter
    }
    if(counter >= DEBOUNCE_COUNT) { //  If the counter is greater than the debounce threshold...
      counter = 0; // Reset the counter
      outState = HIGH; // Set the trigger state to high
      for(int i; i<=3; i++){
        digitalWrite(LED_PIN, HIGH);
        delay(50);
        digitalWrite(LED_PIN, LOW);
        delay(50);
      }
    }
    time = millis(); // Record the current time in milliseconds  
  }
}
