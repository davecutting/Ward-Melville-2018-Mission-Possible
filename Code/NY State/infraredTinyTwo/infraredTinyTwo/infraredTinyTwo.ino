/**
    Infrared Action (Reciever) - Mission Possible MK2
    Ward Melville HS Science Olympiad - Team A - 2017-2018
    infraredTinyTwo.ino
    Purpose: Sets the output of the action high for one second when three leading edges are detected by an IR reciever.

    @author David Cutting
    @version 2.0 3/3/2018
*/

// Definitions for microcontroller pin numbers
const int IN_PIN = 2;
const int OUT_PIN = 4;

// Variables and constants for the pulse counter code
int increment = 0;
long int timer = 0;
long int current = 0;

void setup() {
  // Set the microcontroller pins as either inputs or outputs
  pinMode(IN_PIN, INPUT);
  pinMode(OUT_PIN, OUTPUT);

  // Write the output pin low (off)
  digitalWrite(OUT_PIN, LOW);

  GIMSK = (1<<PCIE); // Turn on pin change interrupts only
  PCMSK = (1<<PCINT2); // Turn on interrupts on pin 2 only
  sei();              // Enable interrupts

}

void loop() {
  if(increment>3) {  // Ideal delay is about 0.1 second
    digitalWrite(OUT_PIN, HIGH);  
  }
}

ISR(PCINT0_vect)
{
  // Timer has +/-10% accuracy, so 2.5 ms maximum off. Temp and voltage also affect it, at nominal conditions mean freq is <8 mHz.
  current = millis();
  if((current < (timer+7)) && (current > (timer+3))) {
    increment++;
  }
  else {
    increment = 0;
  }
  timer = millis();
}

