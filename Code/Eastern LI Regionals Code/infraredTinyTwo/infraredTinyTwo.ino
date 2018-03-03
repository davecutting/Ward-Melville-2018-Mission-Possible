/**
    Infrared Action (Reciever) - Mission Possible MK2
    Ward Melville HS Science Olympiad - Team A - 2017-2018
    infraredTinyTwo.ino
    Purpose: Sets the output of the action high for one second when three leading edges are detected by an IR reciever.

    @author David Cutting
    @version 1.1 1/26/2018
*/

// Definitions for microcontroller pin numbers
const int IN_PIN = 2;
const int OUT_PIN = 4;

// Variables for states of the pins
bool inState = HIGH;
bool switchState = LOW;

// Variables and constants for the pulse counter code
unsigned int pulseCounter = 0;
long time;

void setup() {
  // Set the microcontroller pins as either inputs or outputs
  pinMode(IN_PIN, INPUT);
  pinMode(OUT_PIN, OUTPUT);

  // Write the output pin low (off)
  digitalWrite(OUT_PIN, LOW);
  time = millis();
}

void loop() {
  inState = digitalRead(IN_PIN);
  if(inState == switchState && millis() >= time + 8) {
    pulseCounter++;
    switchState = !switchState;
  }
  else if(inState == HIGH) {
    time = millis(); 
  }
  if(pulseCounter > 10) {
    digitalWrite(OUT_PIN, HIGH);
  }
}
