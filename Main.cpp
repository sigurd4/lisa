#include "arduino.h"

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
      this->nextPortToBeInitialized = 0;
    }

    void init()
    {
      this->lcd = initLCD();
      initPorts();

      this->enabled = true;
      this->timeTotal = 60; //this will change later
      resetTimer();
    }

    void upd()
    {
      if (everyXTicks(1000)) //1000 milliseconds = 1 second
      {
        if (this->enabled)
        {
          updateTimer();
        }
      }
      ++this->ticksRunning;
      delay(1);
    }

    void registerPort(Port port)
    {
      this->portsToBeInitialized[this->nextPortToBeInitialized] = this->port;
      ++this->nextPortToBeInitialized;
    }

    void initPorts()
    {
      int i;
      for (i = 0; i < this->nextPortToBeInitialized; ++i)
      {
        this->portsToBeInitialized[i].init();
      }
    }

    void updateTimer()
    {
      if (this->timer > 0)
      {
        --this->timer;
      }
      else
      {
        this->timer = 0;
      }
    }

    bool everyXTicks(int x)
    {
      return this->ticksRunning % x == x % x;
    }

    void resetTimer()
    {
      this->timer = this->timeTotal;
    }

    LCDScreen initLCD()
    {
      this->lcd = LCDScreen();
      int i;
      for (i = 0; i < this->lcd.portsLenght; ++i)
      {
        this->registerPort(lcd.ports[i]);
      }
      return lcd;
    }
};
