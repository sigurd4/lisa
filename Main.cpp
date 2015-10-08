#include "Ports.cpp"
#include "LCDScreen.cpp"

class Main
{
  public:
    LCDScreen lcd;
    int timer;
    int timeTotal;
    long ticksRunning;
    bool enabled;

    int nextPortToBeInitialized;

    Port portsToBeInitialized [255];

    Main()
    {
      nextPortToBeInitialized = 0;
    }

    void init()
    {
      lcd = initLCD();
      initPorts();

      enabled = true;
      timeTotal = 60; //this will change later
      resetTimer();
    }

    void upd()
    {
      if (everyXTicks(1000)) //1000 milliseconds = 1 second
      {
        if (enabled)
        {
          updateTimer();
        }
      }
      ++ticksRunning;
      delay(1);
    }

    void registerPort(Port port)
    {
      portsToBeInitialized[nextPortToBeInitialized] = port;
      ++nextPortToBeInitialized;
    }

    void initPorts()
    {
      int i;
      for (i = 0; i < nextPortToBeInitialized; ++i)
      {
        portsToBeInitialized[i].init();
      }
    }

    void updateTimer()
    {
      if (timer > 0)
      {
        --timer;
      }
      else
      {
        timer = 0;
      }
    }

    bool everyXTicks(int x)
    {
      return ticksRunning % x == x % x;
    }

    void resetTimer()
    {
      timer = timeTotal;
    }

    LCDScreen initLCD()
    {
      lcd = LCDScreen();
      int i;
      for (i = 0; i < lcd.portsLenght; ++i)
      {
        registerPort(lcd.ports[i]);
      }
      return lcd;
    }
}
