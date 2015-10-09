#include "arduino.h"

#include "Port.cpp"

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
      return valueCheck(digitalRead(this->id));
    }

    void init()
    {
      pinMode(this->id, INPUT);
    }
};
