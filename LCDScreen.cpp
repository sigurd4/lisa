#include "arduino.h"
#include "PortOutput.cpp"
#include "LCDScreen.h"

#ifndef LCD_SCREEN_CPP
#define LCD_SCREEN_CPP

LCDScreen::LCDScreen()
{
  this->enabled = true;
  int i;
  for (i = 0; i < portsLenght; ++i)
  {
    this->ports[i] = PortOutput(i, false);
  }
};
#endif
