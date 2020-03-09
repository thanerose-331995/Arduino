#include <Servo.h>

Servo servo;  // create servo object to control a servo
int input = A0;
  int pos = 0;
  int posMove = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(input, INPUT);
  servo.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(input);
  Serial.print(val);
  if(val < 170){
    pos = pos + posMove;
    if (pos <= 0 || pos >= 180) {
      posMove = -posMove;
    }
  }
  delay(25);
  Serial.print(" / ");
  Serial.println(pos);
  servo.write(pos); 
}
