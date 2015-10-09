#include "arduino.h"

#include "Port.cpp"

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
