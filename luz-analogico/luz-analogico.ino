int sensor=1;
int led=3;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int valorSensor = analogRead(sensor);
Serial.println(valorSensor);
analogWrite(led,map(valorSensor,0,1023,255,0));
delay(50);
}
