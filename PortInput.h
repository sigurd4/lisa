#include "Port.h"

#ifndef PORT_INPUT_H
#define PORT_INPUT_H

class PortInput : public Port
{
  public:
    PortInput();

    PortInput(int id);

    bool getVal();

    void init();
};
#endif
