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

    boolean valueCheck(boolean value)
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
    boolean defaultValue;

    PortOutput(): Port()
    {

    }

    PortOutput(int id, boolean newDefault) : Port(id)
    {
      defaultValue = newDefault;
      setDefault();
    }

    void setDefault()
    {
      digitalWrite(id, valueCheck(defaultValue));
    }

    void setVal(boolean value)
    {
      digitalWrite(id, valueCheck(value));
    }

    void init()
    {
      pinMode(id, OUTPUT);
    }
};
