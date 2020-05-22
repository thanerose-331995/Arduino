
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum

//OUTPUT PINS
int b_pin = 11;
int g_pin = 10;
int r_pin = 9;



void setup() {
  pinMode(r_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);

  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorReading = analogRead(A0);
  Serial.println(sensorReading);

  int val = map(sensorReading, sensorMin, sensorMax, 0, 255);
  Serial.println(val);

  set_rgb(255, 255, val);
  
}

void set_rgb(int r_val, int g_val, int b_val){
  //SETTING EACH
  analogWrite(r_pin, r_val);
  analogWrite(g_pin, g_val);
  analogWrite(b_pin, b_val);
}
