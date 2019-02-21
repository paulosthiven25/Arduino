int sensor = A1;
void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int valorSensor =analogRead(sensor);
  Serial.println(valorSensor);
  delay(500);  

}
