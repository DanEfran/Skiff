// rotary.cpp
// skiff_MIDI_in

#include "rotary.h"

#include <Arduino.h>

const int PIN_ROTARY_A = 24;
const int PIN_ROTARY_B = 25;
const int PIN_ROTARY_PUSH = 28;

void initRotary() {
  
  pinMode(PIN_ROTARY_A, INPUT_PULLUP);
  pinMode(PIN_ROTARY_B, INPUT_PULLUP);
  pinMode(PIN_ROTARY_PUSH, INPUT_PULLUP);

}

void loopRotary() {

  int aa = digitalRead(PIN_ROTARY_A);
  int bb = digitalRead(PIN_ROTARY_B);
  int cc = digitalRead(PIN_ROTARY_PUSH);

  Serial.printf("%c  %c  %c\r\n", !aa ? 'A':'.', !bb ? 'B':'.', !cc ? 'C':'.');

}