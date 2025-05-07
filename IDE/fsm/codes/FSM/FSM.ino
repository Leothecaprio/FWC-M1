#include <Arduino.h>

int Z=0,Y=0,X=0,W=0;
int D,C,B,A;

void disp_7447(int D,int C,int B, int A)
{
  digitalWrite(2, W); //LSB
  digitalWrite(3, X); 
  digitalWrite(4, Y); 
  digitalWrite(5, Z); //MSB
}

void setup() {
 
pinMode(2, OUTPUT);  
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, INPUT);
pinMode(7, INPUT);
pinMode(8, INPUT);
pinMode(9, INPUT);
pinMode(13, OUTPUT);

}

void loop() {

digitalWrite(13, HIGH);
delay(1000);

disp_7447(D,C,B,A);

A = (!W);
B = (!W&&!X&&Y)||(W&&X) || (!W&&Z);
C = (!W&&Z)||(X&&Y)||(W&&Y);
D = (!W&&!X&&!Y&&!Z)||(W&&Z);

W = A;
X = B; 
Y = C;
Z = D;

digitalWrite(13, LOW);
delay(100);
}