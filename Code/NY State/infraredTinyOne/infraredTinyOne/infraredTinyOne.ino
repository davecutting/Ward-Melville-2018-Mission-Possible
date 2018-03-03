/**
    Infrared Action (Transmitter) - Mission Possible MK2
    Ward Melville HS Science Olympiad - Team A - 2017-2018
    infraredTinyOne.ino
    Purpose: Sends a message comprosed of three 100 millisecond pulses separated by 100 milliseconds using an infrared LED.

    @author David Cutting
    @version 2.0 3/3/2018
*/

#define F_CPU 8000000
#define __AVR_ATtiny25__
#include <avr/interrupt.h>

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
  //wdt_disable();
  sei();
  pinMode(IN_PIN, INPUT);
  
  //PLLCSR = (1<<PCKE) | (1<<PLLE); // Enable 64 MHz PLL and use as source for Timer1
  pinMode(LED_PIN, OUTPUT);
  OCR1C = 199;  // Frequency
  OCR1A = 0;  // Duty cycle
  TCCR1 = (1<<CS12) | (1<<COM1A1) | (1<<COM1A0) | (1<<PWM1A); // Set PWM with a prescaler of 2
  GTCCR = (1<<PWM1B) | (1<<COM1B1) | (1<<COM1B0); // clear on match, enable PWM
}

void loop() {
  if(digitalRead(IN_PIN)) {
    GTCCR &= (0<<PWM1B);
    OCR1A = 128;  // Duty cycle
    GTCCR |= (1<<PWM1B);
    delay(5);
    GTCCR &= (0<<PWM1B);
    OCR1A = 0;  // Duty cycle
    GTCCR |= (1<<PWM1B);
    delay(5);  
  }
  
}
