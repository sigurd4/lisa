#include "PortOutput.h"

#ifndef LCD_SCREEN_H
#define LCD_SCREEN_H

class LCDScreen
{

  public:
    const static int portsLenght = 14;
    PortOutput ports [portsLenght];
  private:
    bool enabled;
  public:
    LCDScreen();
};
#endif
