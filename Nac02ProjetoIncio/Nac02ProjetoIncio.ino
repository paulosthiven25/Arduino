#include "DHT.h"
#define DHTPIN A2 // pino que estamos conectado
#define DHTTYPE DHT11
#include <ArduinoJson.h>
DHT dht(DHTPIN, DHTTYPE); 


const int luz=A3;
const int TAMANHO = 200;
const int rele=2;
const int led =6;

void setup() {
   Serial.begin(9600);
   dht.begin();
   pinMode(rele,OUTPUT);
   pinMode(led,OUTPUT);
}

void loop() {



  if (Serial.available() > 0) {
    //Lê o texto disponível na porta serial:
   char texto[TAMANHO];
     Serial.readBytesUntil('\n', texto, TAMANHO);
     //Grava o texto recebido como JSON
     StaticJsonBuffer<TAMANHO> jsonBuffer;
     JsonObject& json = jsonBuffer.parseObject(texto);
     if(json.success()) {
       if( json.containsKey("led")){
           analogWrite(led, json["led"]);
            delay(4000);
       }
      
       
       if( json.containsKey("rele")){
          if(json["rele"]=true){
             digitalWrite(rele,LOW);
              delay(4000);
           }
           
        if(json["rele"]=false){
          digitalWrite(rele,HIGH);
           delay(4000);
           }
       }

       }

 }

 
 StaticJsonBuffer<TAMANHO> jsonBuffer;
 JsonObject& json = jsonBuffer.createObject();
 json["luz"] = analogRead(luz);
 json["umidade"] =  dht.readHumidity();
 json["temperatura"] = dht.readTemperature(); 
 json.printTo(Serial); Serial.println();


  if(json["luz"]<550 && json["umidade"]>65){
     digitalWrite(rele,LOW);
     digitalWrite(led,HIGH); 
    
    }else{
    digitalWrite(rele,HIGH);
    digitalWrite(led,LOW); 
   }
    delay(1000);
}
