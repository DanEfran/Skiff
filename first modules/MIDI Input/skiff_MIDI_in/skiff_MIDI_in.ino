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

#include "display.h"
#include "neopixel.h"

void setup(void) {
  
  Serial.begin(115200);
  while (!Serial && (millis() < 10000));
  Serial.println(millis());
  
  Serial.print(F("Hello! Skiff MIDI In"));

  initNeopixel();

  initDisplay();

  Serial.println(F("Initialized"));
  
  testClearScreen();

  delay(500);

  // tft print function!
  tftPrintTest();
  delay(2000);

  // line draw test
  testlines();
  delay(500);

  // optimized lines
  testfastlines();
  delay(500);

  testroundrects();
  delay(500);

}

void loop() {

  testNeopixel();
}
