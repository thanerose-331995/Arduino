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
  
  int newVal = map(val, 0, 1020, 0, 150);
  if(newVal <= 50){
    int led = map(newVal, 0, 50, 0, 255);
    set_rgb(led, 255, 255);
  }
  else if(newVal > 50 && newVal <= 100){
    int led = map(newVal, 50, 100, 0, 255);
    set_rgb(255, led, 255);
  }
  else if(newVal > 100){
    int led = map(newVal, 100, 150, 0, 255);
    set_rgb(255, 255, led);
  }  
}


void set_rgb(int r_val, int g_val, int b_val){
  //SETTING EACH
  analogWrite(r_pin, r_val);
  analogWrite(g_pin, g_val);
  analogWrite(b_pin, b_val);
}
