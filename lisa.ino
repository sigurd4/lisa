class Port
{
  public:
    int id;

    Port(int newid)
    {
      id = newid;
    }

    Port()
    {

    }

    virtual void init() = 0;

    boolean valueCheck(boolean value)
    {
      return value;
    }
};

class PortInput : public Port
{
  public:
    PortInput(int id) : Port(id)
    {

    }

    PortInput(): Port()
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

    PortOutput(int id, boolean newDefault) : Port(id)
    {
      defaultValue = newDefault;
      setDefault();
    }

    PortOutput(): Port()
    {

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
        ports[i] = new PortOutput(i, false);
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
  lcd = new LCDScreen();
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
