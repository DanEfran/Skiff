// rotary.cpp
// skiff_MIDI_in

#include "rotary.h"

#include <Arduino.h>

const int PIN_ROTARY_A = 24;
const int PIN_ROTARY_B = 25;
const int PIN_ROTARY_PUSH = 28;

void handleRotaryA() {

  bool clockwise = digitalRead(PIN_ROTARY_B);
  Serial.printf("Rotary %s\r\n", clockwise ? "clockwise" : "counterclockwise" );

}

void handleRotaryPush() {

  Serial.println("Rotary Push");

}

void initRotary() {
  
  pinMode(PIN_ROTARY_A, INPUT_PULLUP);
  pinMode(PIN_ROTARY_B, INPUT_PULLUP);
  pinMode(PIN_ROTARY_PUSH, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(PIN_ROTARY_A), handleRotaryA, FALLING);
  attachInterrupt(digitalPinToInterrupt(PIN_ROTARY_PUSH), handleRotaryPush, FALLING);

}
