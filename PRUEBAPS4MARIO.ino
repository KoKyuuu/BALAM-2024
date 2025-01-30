#include <ps4.h>
#include <PS4Controller.h>
#include <ps4_int.h>







//MOTOR1
#define AIN1 18
#define AIN2 23

//MOTOR2
#define BIN1 16
#define BIN2 17

//motor3 lanzadores 
//#define CIN1 18
//#define CIN2 4
//#define CIN3 13

int rX;
int rY;
int lX;
int lY;


//gatillos joj
int l2;
int r2;

int cuadro;
int circulo;
int Square;
int triangulo;
unsigned long lastTimeStamp = 0;

void notify(){
char messageString[200];
 sprintf(messageString, "%4d,%4d,%4d,%4d, %4d, %4d,",
lX = PS4.LStickX(),
lY= PS4.LStickY(),
rX = PS4.RStickX(),
rY = PS4.RStickY(),
cuadro = PS4.Cross(),
circulo = PS4.Circle(),
Square = PS4.Square(),
triangulo = PS4.Triangle(),
l2 = PS4.L2(),
r2 = PS4.R2());

if (millis() - lastTimeStamp > 50){
    Serial.println(messageString);
    lastTimeStamp = millis();
  }


//motor 1
if(lY>125){
 digitalWrite (AIN1, HIGH); 
 digitalWrite (AIN2, LOW);
 }

if (lY<=20){
  digitalWrite(AIN1,LOW); 
  digitalWrite(AIN2,LOW );
 }

if (lY<-125){
  digitalWrite(AIN1,LOW); 
  digitalWrite(AIN2,HIGH);
 }

//motor 2
if(rY>125){
 digitalWrite (BIN1, HIGH);
 digitalWrite (BIN2, LOW);
  }

if (rY<=20){
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,LOW);
 }

if (rY<-125){
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,HIGH);
 }

}

void onConnect()
{
  Serial.println("Connected!.");
}

void onDisConnect()
{
  Serial.println("Disconnected!.");
}

void setup() 
{
  Serial.begin(115200);
  PS4.attach(notify);
  PS4.attachOnConnect(onConnect);
  PS4.attachOnDisconnect(onDisConnect);
  PS4.begin();
  Serial.println("Ready.");
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);

}

void loop()
{  }
 
