#include "DHT.h"
#define DHTPIN A2 // pino que estamos conectado
#define DHTTYPE DHT11
#include <ArduinoJson.h>
DHT dht(DHTPIN, DHTTYPE); 


int luz=A3;
const int TAMANHO = 200;
int rele=2;

void setup() {
   Serial.begin(9600);
   dht.begin();
   pinMode(rele,OUTPUT);

}

void loop() {



  /*if (Serial.available() > 0) {
    //Lê o texto disponível na porta serial:
   char texto[TAMANHO];
     Serial.readBytesUntil('\n', texto, TAMANHO);
     //Grava o texto recebido como JSON
     StaticJsonBuffer<TAMANHO> jsonBuffer;
     JsonObject& json = jsonBuffer.parseObject(texto);
     if(json.success() && json.containsKey("led")) {
       analogWrite(LED, json["led"]);
       }
 }*/

 
 StaticJsonBuffer<TAMANHO> jsonBuffer;
 JsonObject& json = jsonBuffer.createObject();
 json["luz"] = analogRead(luz);
 json["umidade"] =  dht.readHumidity();
 json["temperatura"] = dht.readTemperature(); 
 json.printTo(Serial); Serial.println();


if(json["luz"]<551){
digitalWrite(rele,LOW);
 
 delay(1000);
}else{
  digitalWrite(rele,HIGH);
}
}
