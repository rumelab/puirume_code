#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <items.hpp>

void setup()
{
  output_device.begin();
  input_device.begin();
  output_device.setFont(u8g2_font_6x10_tf);
  state_machine.to(state_machine.store.main_state);
}

void loop()
{
  static uint32_t previous_timestamp = 0;
  const uint32_t current_timestamp = millis();
  const uint32_t delta = current_timestamp - previous_timestamp;
  previous_timestamp = current_timestamp;

  input_device.process();
  state_machine.process(delta);
}