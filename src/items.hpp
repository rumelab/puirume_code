#ifndef ITEMS_HPP
#define ITEMS_HPP

#include <U8g2lib.h>
#include <ky040.hpp>

#include "store.hpp"

using OutputDeviceType = U8G2_SSD1306_128X64_NONAME_1_HW_I2C;
using InputDeviceType = KY040<PinName::p13, PinName::p12, PinName::p11>;

extern OutputDeviceType output_device;
extern InputDeviceType input_device;
extern StateMachine<Store> state_machine;

#endif // ITEMS_HPP