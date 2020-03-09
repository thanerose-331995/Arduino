/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/

int led = 6;           // the PWM pin the LED is attached to
int led2 = 5;
int led3 = 3;

int brightness = 0;
int fadeAmount = 5;

int bright1 = 0;
int bright2 = 0;
int bright3 = 0;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  Serial.begin(9600); //this starts a console session on that freq
  Serial.println("check"); //this is how you console.log
}

// the loop routine runs over and over again forever:
void loop() {
  int brightness2 = map(brightness, 0, 255, 255, 0);
  
  analogWrite(led, brightness); //has to be done with analog (1-100)
  analogWrite(led2, brightness2);
  analogWrite(led3, brightness);
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
