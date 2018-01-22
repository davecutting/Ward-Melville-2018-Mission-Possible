/**
    Light Triggered Action - Mission Possible MK2
    Ward Melville HS Science Olympiad - Team A - 2017-2018
    lightTiny.ino
    Purpose: Triggers the next action when the resistance of a photocell changes more than a threshold value.

    @author David Cutting
    @version 1.0 1/22/2018
*/

// Definitions for microcontroller pin numbers
const int PHOTOCELL_PIN = 1;
const int OUT_PIN = 4;

// Variables for states of the pins
int photocellValue;
int photocellBase;
bool statusOut = LOW;

void setup() {
  // Set the microcontroller pins as either inputs or outputs
  pinMode(PHOTOCELL_PIN, INPUT);
  pinMode(OUT_PIN, OUTPUT);

  // Set the output pin to low
  digitalWrite(OUT_PIN, LOW); // Write the output pin to LOW

  // Read the initial value of the photocell (ambient light)
  photocellBase = analogRead(PHOTOCELL_PIN);
}

void loop() {
  photocellValue = analogRead(PHOTOCELL_PIN);
  
  if(photocellValue - photocellBase >= 100 && statusOut == LOW) { 
    // If the difference (NOT ABSOLUTE VALUE) between the current reading and the ambient reading is greater than the threshold...
    delay(1000); // Delay 1000 milliseconds (1 s) to allow observation
    statusOut = HIGH;
    digitalWrite(OUT_PIN, HIGH); // Trigger the next action
  }
}
