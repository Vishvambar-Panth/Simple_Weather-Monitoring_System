#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include
<ThingSpeak.h>;
#include <DHT.h>
#define DHT11PIN D3
#define DHTTYPE DHT11
DHT dht(DHT11PIN, DHTTYPE);
float
h,tc,tf; int
r;
const char* ssid = "Muskmelon"; //Your Network SSID
const char* password = "vishy12345"; //Your Network
Password #define Buzzer D0
WiFiClient client;
unsigned long myChannelNumber = 1370855; //Your Channel Number (Without
Brackets) const char * myWriteAPIKey = "860QH6YFMJQLF9HV"; //Your Write API
Key
#define LEAK_PIN A0
int
leakValue;
void setup()
{
Serial.begin(9600);
delay(10);
pinMode(Buzzer,OUTPU
T); pinMode(LEAK_PIN,
INPUT);
// Connect to WiFi
network WiFi.begin(ssid,
password);
ThingSpeak.begin(clie
nt); dht.begin();
delay(1000);
Serial.println("DHT11 Temperature and Humidity ");
}
void loop()
{ delay(284000);
digitalWrite(Buzzer,LO
W); h =
dht.readHumidity();
tc = dht.readTemperature();
tf =
dht.readTemperature(true); if
(tc>35.00)
{ digitalWrite(Buzzer,HIGH);
delay(500);
digitalWrite(Buzzer,LOW);
}
leakValue =
analogRead(LEAK_PIN); if
(leakValue>150)
r=1;
else
r=0;
Serial.println(leakValue)
; Serial.print('\n');
Serial.print("Humidity =
"); Serial.print(h);
Serial.print("%, ");
Serial.print("Temperature =
"); Serial.print(tc);
Serial.print("°C, ");
Serial.print(tf);
Serial.println("°F");
delay(1000);
ThingSpeak.setField(1,
tc);
ThingSpeak.setField(2,
h);
ThingSpeak.setField(3,
r);
//ThingSpeak.writeField(myChannelNumber, 1,tc, myWriteAPIKey);//Update in ThingSpeak
//ThingSpeak.writeField(myChannelNumber, 2,h,
myWriteAPIKey);
ThingSpeak.writeFields(myChannelNumber,
myWriteAPIKey);
delay(100);
}
