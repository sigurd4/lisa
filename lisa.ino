class Port
{
  public:
    int id;

    Port()
    {

    }

    Port(int newid)
    {
      id = newid;
    }

    void init()
    {
      
    }

    boolean valueCheck(boolean value)
    {
      return value;
    }
};

int nextPortToBeInitialized = 0;
Port portsToBeInitialized [];

Port registerPort(Port port)
{
  portsToBeInitialized[nextPortToBeInitialized] = port;
  ++nextPortToBeInitialized;
}

class PortInput : public Port
{
  public:
    PortInput(): Port()
    {

    }
    
    PortInput(int id) : Port(id)
    {

    }

    void getVal()
    {
      valueCheck(digitalRead(id));
    }

    void init()
    {
      pinMode(id, INPUT);
    }
};

class PortOutput : public Port
{
  public:
    boolean defaultValue;

    PortOutput(): Port()
    {

    }

    PortOutput(int id, boolean newDefault) : Port(id)
    {
      defaultValue = newDefault;
      setDefault();
    }

    void setDefault()
    {
      digitalWrite(id, valueCheck(defaultValue));
    }

    void setVal(boolean value)
    {
      digitalWrite(id, valueCheck(value));
    }

    void init()
    {
      pinMode(id, OUTPUT);
    }
};

class LCDScreen
{
  private:
    const static int portsLenght = 14;
    PortOutput ports [portsLenght];
  public:
    boolean enabledLCD;

    LCDScreen()
    {
      enabledLCD = true;
      int i;
      for (i = 0; i < portsLenght; ++i)
      {
        ports[i] = registerPort(PortOutput(i, false));
      }
    }
};

//The hella best way to water plants!

LCDScreen lcd;
int timer;
int timeTotal;
long ticksRunning;
boolean enabled;

void setup()
{
  lcd = LCDScreen();
  initPorts()

  enabled = true;
  timeTotal = 60; //this will change later
  resetTimer();
}

void loop()
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

boolean everyXTicks(int x)
{
  return ticksRunning % x == x % x;
}

void resetTimer()
{
  timer = timeTotal;
}
