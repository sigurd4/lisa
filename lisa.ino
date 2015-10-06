class Port
{
  public:
    int id;

    Port(int newid)
    {
      id = newid;
    }

    virtual void init() = 0;

    virtual boolean valueCheck(boolean value) = 0;
};

class PortInput : public Port
{
  public:
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

    boolean valueCheck(boolean value)
    {
      return value;
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

    boolean valueCheck(boolean value)
    {
      return value;
    }
};

class LCDScreen
{
  private:
    PortOutput ports [14];
  public:
    boolean enabledLCD;

    LCDScreen()
    {
      enabledLCD = true;
      for (int i = 0; i < ports::lenght; ++i)
      {
        ports[i] = new PortOutput(i, false);
      }
    }
};

//The hella best way to water plants!

LCDScreen lcd;
int timer;
long ticksRunning;
boolean enabled;

void setup()
{
  lcd = new LCDScreen();
  enabled = true;
  timer = 60; //this will change later
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

