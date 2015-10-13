#include "Port.h"

#ifndef PORT_OUTPUT_H
#define PORT_OUTPUT_H

class PortOutput : public Port
{
  public:
    bool defaultValue;

    PortOutput();

    PortOutput(int id, bool newDefault);

    void setDefault();

    void setVal(bool value);

    void init();
};
#endif
