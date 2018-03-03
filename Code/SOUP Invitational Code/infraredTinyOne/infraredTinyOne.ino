/**
    Infrared Action (Transmitter) - Mission Possible MK2
    Ward Melville HS Science Olympiad - Team A - 2017-2018
    infraredTinyOne.ino
    Purpose: Sends a continuous stream of 50 millisecond pulses separated by 50 milliseconds using an infrared LED.

    @author David Cutting
    @version 1.1 1/26/2018
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
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  if(digitalRead(IN_PIN)) {
    digitalWrite(LED_PIN, HIGH);
    delay(20);
    digitalWrite(LED_PIN, LOW);
    delay(20);
  }

}
