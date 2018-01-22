/**
    Chemical Timer Action - Mission Possible MK2
    Ward Melville HS Science Olympiad - Team A - 2017-2018
    expUno.inoTurns on a motor when the input is recieved. Turns it off when a switch is hit.

    @author David Cutting
    @version 0.1 1/16/2018
*/

// Definitions for microcontroller pin numbers
const int PROBE_PIN = A0;

void setup() {
  // Set the microcontroller pins as either inputs or outputs
  pinMode(PROBE_PIN, INPUT);
}

void loop() {
  if(analogRead(PROBE_PIN) >= 500) { 
    // If the absolute value of the difference between the current reading and the initial reading is greater than the threshold...
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(13, LOW);
  }
}
