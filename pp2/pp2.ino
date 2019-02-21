int inPin = 8;
int val =0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(inPin,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
val=digitalRead(inPin);
Serial.println(val);
delay(10);
}
