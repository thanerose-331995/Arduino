int input = A0;

//OUTPUT PINS
int b_pin = 11;
int g_pin = 10;
int r_pin = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(input, INPUT);
  
  pinMode(r_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(input);
  Serial.print(val);
  
  int bVal = map(val, 0, 1020, 0, 255);
  int rVal = 255 - bVal;

  
  Serial.print(" / ");
  Serial.print(bVal);
  Serial.print(" / ");
  Serial.println(rVal);
  set_rgb(rVal, 255, bVal);
}


void set_rgb(int r_val, int g_val, int b_val){
  //SETTING EACH
  analogWrite(r_pin, r_val);
  analogWrite(g_pin, g_val);
  analogWrite(b_pin, b_val);
}
