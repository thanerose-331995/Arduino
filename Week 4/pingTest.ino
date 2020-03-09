int pingPin = 7;
int b_pin = 11;
int g_pin = 10;
int r_pin = 9;


void setup() {
  // initialize serial communication:
  pinMode(r_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // establish variables for duration of the ping, and the distance result
  // in inches and centimeters:
  pinMode(pingPin, OUTPUT);
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  int blue = map(cm, 50, 0, 0, 255);
  int red = 255 - blue;
  Serial.print("blue: ");
  Serial.print(blue);
  Serial.print(" red: ");
  Serial.print(red);
  Serial.println();
  set_rgb(red, 255, blue);
  delay(100);
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

void set_rgb(int r_val, int g_val, int b_val){
  analogWrite(r_pin, r_val);
  analogWrite(g_pin, g_val);
  analogWrite(b_pin, b_val);
}
