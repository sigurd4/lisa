#include "Main.cpp"

//The hella best way to water plants!

Main main;

void setup()
{
  main = Main::Main();
  main.init();
}

void loop()
{
  main.upd();
}
