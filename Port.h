#ifndef PORT_H
#define PORT_H

class Port
{
  public:
    int id;

    Port();

    Port(int newid);

    void init();

    bool valueCheck(bool value);
};
#endif
