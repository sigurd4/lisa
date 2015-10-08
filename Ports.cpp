#include "arduino.h"

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

    bool valueCheck(bool value)
    {
      return value;
    }
};

class PortInput : public Port
{
  public:
    PortInput(): Port()
    {

    }

    PortInput(int id) : Port(id)
    {

    }

    bool getVal()
    {
      return valueCheck(digitalRead(id));
    }

    void init()
    {
      pinMode(id, INPUT);
    }
};

class PortOutput : public Port
{
  public:
    bool defaultValue;

    PortOutput(): Port()
    {

    }

    PortOutput(int id, bool newDefault) : Port(id)
    {
      defaultValue = newDefault;
    }

    void setDefault()
    {
      digitalWrite(id, valueCheck(defaultValue));
    }

    void setVal(bool value)
    {
      digitalWrite(id, valueCheck(value));
    }

    void init()
    {
      pinMode(id, OUTPUT);
      setDefault();
    }
};
