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

    boolean valueCheck(bool value)
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

    void getVal()
    {
      valueCheck(digitalRead(id));
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
      setDefault();
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
    }
};
