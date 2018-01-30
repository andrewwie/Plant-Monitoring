#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#define DHTPIN 5
#define DHTTYPE DHT22

char auth[] = "82a1d1d9d23d40e9aa4f4650b46eb1a6";
char ssid[] = "RICKY";
char pass[] = "L0nghumen";

int LED1 = 14;
int LED2 = 12;
int LED3 = 13;
int m=0;
float h=0;
float t=0;
float mf=0;
int pinMoist=A0;

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  dht.begin();
}

void loop()
{
  Blynk.run();
  h = dht.readHumidity();
  t = dht.readTemperature();
  Blynk.virtualWrite(V5, t);                                 
  Blynk.virtualWrite(V6, h);  
  m = analogRead(pinMoist);
  mf = m/673*100;
  Serial.println(mf);
  Blynk.virtualWrite(V7, m);
  if (m <= 341)
  {
   digitalWrite(LED3,HIGH);
   digitalWrite(LED1,LOW);
   digitalWrite(LED2,LOW);
  }

  else if (m >= 342 && m <= 500)
  {
   digitalWrite(LED2,HIGH);
   digitalWrite(LED1,LOW);
   digitalWrite(LED3,LOW);
  }

    else if (m >=700)
  {
   digitalWrite(LED1,HIGH);
   digitalWrite(LED2,LOW);
   digitalWrite(LED3,LOW);
  }
}

