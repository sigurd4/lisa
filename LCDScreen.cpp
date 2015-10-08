#include "Ports.cpp"

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
        ports[i] = PortOutput(i, false);
      }
    }
};
