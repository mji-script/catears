//cat ears
//by leo.mandolini


#include <ESP32Servo.h>

//pins

const int leftear = 1;
const int rightear = 0;

//servos

Servo sleft;
Servo sright;

//variables

void setup() {

  sleft.attach(leftear);
  sright.attach(rightear);

  //just do something

  sleft.write(0);
  sright.write(0);

  delay(10000);
  
  sleft.write(180);
  sright.write(180);

  delay(1000);

  sleft.write(0);
  sright.write(0);

  delay(1000);
}

void loop() {


}
