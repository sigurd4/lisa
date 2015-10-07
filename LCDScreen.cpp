#include "Ports.cpp"

class LCDScreen
{
  private:
    const static int portsLenght = 14;
    PortOutput ports [portsLenght];
  public:
    bool enabled;

    LCDScreen()
    {
      enabledLCD = true;
      int i;
      for (i = 0; i < portsLenght; ++i)
      {
        ports[i] = PortOutput(i, false);
      }
    }
};
