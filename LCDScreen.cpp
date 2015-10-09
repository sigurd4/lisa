#include "arduino.h"

#include "PortOutput.cpp"

class LCDScreen
{

  public:
    const static int portsLenght = 14;
    PortOutput ports [portsLenght];
  private:


    bool enabled;
  public:
    LCDScreen()
    {
      this->enabled = true;
      int i;
      for (i = 0; i < portsLenght; ++i)
      {

        this->ports[i] =   PortOutput(i, false);
      }
    }
};
