// DAC.cpp
// skiff_MIDI_in

#include "DAC.h"

// Demo for configuring the Vref of the MCP4728 4-Channel 12-bit I2C DAC
#include <Adafruit_MCP4728.h>
#include <Wire.h>

Adafruit_MCP4728 mcp;

void initDAC(void) {
  
  Serial.println("Adafruit MCP4728 test!");

  // Try to initialize!
  if (!mcp.begin(MCP4728_I2CADDR_DEFAULT, &Wire1)) {
    Serial.println("Failed to find MCP4728 chip");
    return;
  }
  Serial.println("MCP4728 Found!");
  /*
   * @param channel The channel to update
   * @param new_value The new value to assign
   * @param new_vref Optional vref setting - Defaults to `MCP4728_VREF_VDD`
   * @param new_gain Optional gain setting - Defaults to `MCP4728_GAIN_1X`
   * @param new_pd_mode Optional power down mode setting - Defaults to
   * `MCP4728_PD_MOOE_NORMAL`
   * @param udac Optional UDAC setting - Defaults to `false`, latching (nearly).
   * Set to `true` to latch when the UDAC pin is pulled low
   *
   */

  // we've saved the configuration below to the EEPROM at least once;
  // do we need to do it again? theoretically not?
  bool already_saved = true;

  if (!already_saved) {

    // configure for internal voltage reference within 3v3 supply range
    // nominally 2.048v

    // I'm getting readings that don't look like 2.048v in early tests;
    // needs more testing. (Exact voltage isn't important but stability is.)

    // also, start with outputs at 0

    mcp.setChannelValue(MCP4728_CHANNEL_A, 0, MCP4728_VREF_INTERNAL,
                        MCP4728_GAIN_1X);
    mcp.setChannelValue(MCP4728_CHANNEL_B, 0, MCP4728_VREF_INTERNAL,
                        MCP4728_GAIN_1X);
    mcp.setChannelValue(MCP4728_CHANNEL_C, 0, MCP4728_VREF_INTERNAL,
                        MCP4728_GAIN_1X);
    mcp.setChannelValue(MCP4728_CHANNEL_D, 0, MCP4728_VREF_INTERNAL,
                        MCP4728_GAIN_1X);

    mcp.saveToEEPROM();
  }

  // is initial value among the EEPROM-saved settings? If not:
  // mcp.setChannelValue(MCP4728_CHANNEL_B, 0);
  // mcp.setChannelValue(MCP4728_CHANNEL_C, 0);
  // mcp.setChannelValue(MCP4728_CHANNEL_D, 0);
  // mcp.setChannelValue(MCP4728_CHANNEL_A, 0);

}

void loopDACTest() {
  
  // quick and dirty test

  static int which = 0;
  static int when = 0;

  if (++when % 100000) {
    return;
  }

  which = (which + 1) % 4;

  switch (which) {

    case 0:
      mcp.setChannelValue(MCP4728_CHANNEL_B, 4095);
      mcp.setChannelValue(MCP4728_CHANNEL_C, 2048);
      mcp.setChannelValue(MCP4728_CHANNEL_D, 1024);
      mcp.setChannelValue(MCP4728_CHANNEL_A, 0);
      break;

    case 1:
      mcp.setChannelValue(MCP4728_CHANNEL_C, 4095);
      mcp.setChannelValue(MCP4728_CHANNEL_D, 2048);
      mcp.setChannelValue(MCP4728_CHANNEL_A, 1024);
      mcp.setChannelValue(MCP4728_CHANNEL_B, 0);
      break;

    case 2:
      mcp.setChannelValue(MCP4728_CHANNEL_D, 4095);
      mcp.setChannelValue(MCP4728_CHANNEL_A, 2048);
      mcp.setChannelValue(MCP4728_CHANNEL_B, 1024);
      mcp.setChannelValue(MCP4728_CHANNEL_C, 0);
      break;

    case 3:
      mcp.setChannelValue(MCP4728_CHANNEL_A, 4095);
      mcp.setChannelValue(MCP4728_CHANNEL_B, 2048);
      mcp.setChannelValue(MCP4728_CHANNEL_C, 1024);
      mcp.setChannelValue(MCP4728_CHANNEL_D, 0);
      break;
  }

}