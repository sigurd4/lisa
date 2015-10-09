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
      this->defaultValue = newDefault;
    }

    void setDefault()
    {
      digitalWrite(this->id, valueCheck(this->defaultValue));
    }

    void setVal(bool value)
    {
      digitalWrite(this->id, valueCheck(value));
    }

    void init()
    {
      pinMode(this->id, OUTPUT);
      setDefault();
    }
};
