#include <ArduinoJson.h>
#include "DHT.h"
#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE); //Instanciação do objeto do sensor
const int TAMANHO = 200; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  // A leitura da temperatura e umidade pode levar 250ms!
 float h = dht.readHumidity();//Valor da umidade
 float t = dht.readTemperature(); //Valor da temperatura

StaticJsonBuffer<TAMANHO> jsonBuffer;
JsonObject& json = jsonBuffer.createObject();
if (isnan(t) || isnan(h)) {
 json["erroH"]="Erro no H ou no t";
 }
 else{
json["Humidade"] = h;
json["Temperatura"]=t;
 }
 json.printTo(Serial); Serial.println();
delay(1000);

}
