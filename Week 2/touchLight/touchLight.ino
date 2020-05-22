
//INPUT PINS
int analog1 = A1;
int analog2 = A3;

//OUTPUT PINS
int b_pin = 11;
int g_pin = 10;
int r_pin = 9;

void setup() {

  //SETUP PINS
  pinMode(analog1, INPUT);
  pinMode(analog2, INPUT);
  
  pinMode(r_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);

  //START SERIAL
  Serial.begin(9600);
}

void loop() {

  //GET AND PRINT READINGS
  int value1 = analogRead(analog1);
  int value2 = analogRead(analog2);
  Serial.print(value1);
  Serial.print(" / ");
  Serial.println(value2);

  //MAP IS USED TO RESCALE VALUES (FOR THE COLOURS)
  int newVal1 = map(value1, 0, 50, 0, 255);
  int newVal2 = map(value2, 0, 50, 0, 255);
  
  //FUNC TO SET THE RGB VALUES
  //because this led is an anode the 0-255 are flipped, so 255 is min
  set_rgb(255, newVal1, newVal2);

  
}

void set_rgb(int r_val, int g_val, int b_val){
  //SETTING EACH
  analogWrite(r_pin, r_val);
  analogWrite(g_pin, g_val);
  analogWrite(b_pin, b_val);
}
