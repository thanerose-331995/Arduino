void setup() {
  // INITIALISE PINS AS INPUTS FOR READING
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  // START SERIAL ON SERIAL1
  Serial1.begin(9600);
}

void loop() {
  // COLLECT DATA FROM SENSORS
  int rain = analogRead(A0);
  int light1 = analogRead(A1);
  int light2 = analogRead(A2);
  // FIND AVERAGE LIGHT VAL
  int light = (light1 + light2) / 2;

  // CONCAT TO MESSAGE STRING
  String message = String(rain) + " / " + String(light) + " ~";

  // SEND VIA SERIAL1
  Serial1.println(message);
  // DEBUG
  Serial.println(message);
  Serial.println("--");

  // DELAY TO ALLOW TIME TO RECEIVE
  delay(1000);
  // FLUSH THE BUFFER
  Serial1.flush();
}
