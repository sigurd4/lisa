#include "Main.cpp"

//The hella' best way to water plants!//
//         \                          //
//         \\\             //         //
//          \  \         ///          //
//           \\ \\     /  /           //
//      ////////\  \  /   /           //
//   ////______ \ \|   / ///////\     //
// ////        \ \\  / / _____   \    //
// //            \\\\ //       \  \   //
//         _______|_|_|_______   \\\  //
//        (______ ____ _______)    \\ //
//        (_____ |LISA| _____ )       //
//         (___  |____|_ ____)        //
//         (____ __   _______)        //
//          (___  _  _______)         //
//           (_____________)          //
////////////////////////////////////////
//(credz: http://www.retrojunkie.com/asciiart/plants/misc.htm)

Main main;

void setup()
{
  main = Main();
  main.init();
}

void loop()
{
  main.upd();
}
