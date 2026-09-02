//cat ears
//by leo.mandolini


#include <ESP32Servo.h>

//pins

const int leftear = 1;
const int rightear = 0;

const int sensor = 3;

//servos

Servo sleft;
Servo sright;

//variables

int value = 0;
int angle = 0;
int preangle = 0;

//const

int const noise = 1;

//servo
void catwrite(int degree) {
  int mirror= map(degree, 0, 180, 180, 0);
  sleft.write(degree);
  sright.write(mirror);
  return;
}

void setup() {
  Serial.begin(115200);

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

  value = analogRead(sensor);
  angle = map(value, 0, 4095, 0, 180);

  Serial.println(value);
  Serial.println(angle);

  //noise
  if (!(abs(angle - preangle) <= noise)){
    catwrite(angle);
    preangle = angle;
  }

  delay(10);

}
