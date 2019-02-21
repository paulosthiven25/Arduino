int led=3;
int inPin=8;
int val;
void setup() {
  Serial.begin(9600);
  pinMode(inPin,INPUT_PULLUP);
  pinMode(led,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  val=digitalRead(inPin);
  if(val==0){
    digitalWrite(led,HIGH);
    
  }
  else{
     digitalWrite(led,LOW);  
  

  }

}
