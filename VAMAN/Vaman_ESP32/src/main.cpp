//----------------------Skeleton Code--------------------//
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "Salient" // Add your network credentials
#define STAPSK  "12345678"
#endif
#define LED_PIN 5
const char* ssid = STASSID;
const char* password = STAPSK;


void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//

void setup(){
  OTAsetup();
  pinMode(LED_PIN,OUTPUT);

  //-------------------//
  // Custom setup code //
  //-------------------//
}


int xorr(int e,int f)
{
	int g;
	f = !f;
	g=(!e && f)||(e&& !f);
	return g;
}

void loop() {
  OTAloop();
  //Manually declaring here
  int a=1;
  int b=1;
  int c=0;
  int d=1;
  int A=1101;
  int B=1010;


B=A;
int i=4;
int h;
while(i>0){
h = xorr(d,b);
d=c;
c=b;
b=a;
a=h;
i--;
}
  if(a==0 and b==1 and c==1 and d==1 and B ==1101){
	  digitalWrite(LED_PIN,HIGH);
  } else {
	  digitalWrite(LED_PIN,LOW);
  }
  //-------------------//
  // Custom loop code  //
  //-------------------//
}
