#include "arduino.h"
#include "Port.cpp"
#include "PortInput.h"

#ifndef PORT_INPUT_CPP
#define PORT_INPUT_CPP

PortInput :: PortInput() : Port()
{

};

PortInput :: PortInput(int id) : Port(id)
{

};

bool PortInput :: getVal()
{
  return valueCheck(digitalRead(this->id));
};

void PortInput :: init()
{
  pinMode(this->id, INPUT);
};
#endif
