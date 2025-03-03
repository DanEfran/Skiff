// skiff_MIDI_in.ino
// firmware for a small MIDI IN module for a modular synthesizer
// Dan Efran 2025
//
// Hardware:
// - Adafruit QT Py RP2040 
//    - https://www.adafruit.com/product/4900
//    - 3.3v
// - Adafruit AD5693R Breakout Board 
//    https://www.adafruit.com/product/5811
//    - 16-Bit DAC with I2C Interface - STEMMA QT
// - 0.96" 80x160 RGB IPS display
//    - SPI interface
//    - breakout board carved down by about 5mm to fit in a smaller space
// - Rotary encoder with push switch
// - Toggle switch; DIN-5 MIDI jack; 1/4" stereo TRS jack; 1/8" mono jacks 

/*
    NOTES
    - DAC board is not responding. I may have damaged it when soldering
      and desoldering? It's got a huge heat sinking ground plane,
      apparently, so the '-' output pad is almost unsolderable.
      The Stemma QT port seems to work with other i2c boards, so I'll
      have to try another DAC board. [2025-03-03]
    - Hardware is otherwise in good shape, but each output needs some
      kind of buffering: the audio is probably close to an acceptable
      level (?) but should probably be buffered; the Gate output 
      should probably be raised to 5 or 10 v; the DAC output (when I
      have one that works) will probably need to be doubled or even
      tripled to give a decent octave range; that will count as a
      buffer as well. Then the speaker will need a small amplifier,
      with a volume attenuator knob. 
*/

#include "display.h"
#include "neopixel.h"
#include "SimpleSynth.h"
#include "rotary.h"

time_t initSerial() {

  Serial.begin(115200);
  while (!Serial && (millis() < 10000));
  return millis();

}

void setup(void) {
  
  time_t serial_startup_time = initSerial();

  Serial.print(F("Hello! Serial connect time:"));
  Serial.println(serial_startup_time);


  initNeopixel();
  initDisplay();
  initSimpleSynth();
  initRotary();

  Serial.println(F("Subsystems initialized"));
  
  testClearScreen();
  testroundrects();

  Serial.println("Skiff MIDI In: ready.");

}

void loop() {
  
  loopSimpleSynth();

}
