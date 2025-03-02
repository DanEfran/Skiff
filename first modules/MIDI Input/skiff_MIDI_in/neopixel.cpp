// neopixel.cpp
// skiff_MIDI_in

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels(1, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

void initNeopixel() {

  pinMode(NEOPIXEL_POWER, OUTPUT);
  digitalWrite(NEOPIXEL_POWER, HIGH);

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(20); // not so bright
}

void testNeopixel() {

  pixels.fill(0xFF0088);
  pixels.show();
  delay(1500);

  pixels.fill(0x00FF88);
  pixels.show();
  delay(1500);

  pixels.fill(0x660088);
  pixels.show();
  delay(1500);

}
