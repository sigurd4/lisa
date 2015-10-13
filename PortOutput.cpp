#include "arduino.h"
#include "Port.cpp"
#include "PortOutput.h"

#ifndef PORT_OUTPUT_CPP
#define PORT_OUTPUT_CPP

PortOutput::PortOutput() : Port()
{

};

PortOutput::PortOutput(int id, bool newDefault) : Port(id)
{
  this->defaultValue = newDefault;
};

void PortOutput::setDefault()
{
  digitalWrite(this->id, valueCheck(this->defaultValue));
};

void PortOutput::setVal(bool value)
{
  digitalWrite(this->id, valueCheck(value));
};

void PortOutput::init()
{
  pinMode(this->id, OUTPUT);
  setDefault();
};
#endif
