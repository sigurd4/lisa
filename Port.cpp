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
      this->id = newid;
    }

    void init()
    {
      
    }

    bool valueCheck(bool value)
    {
      return value;
    }
};
