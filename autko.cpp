#include "Arduino.h"
 
#define napiecieSterowania 13 // napiecie steroania na mostku H
#define pwmLeft 3 // PWM - sterowanie predkoscia koło lewe
#define pwmRight 4 // PWM - sterowanie predkoscia koło prawe

float velocity; // podane odgórnie w m/s
float turnSpeed; // podane odgórnie w rad/s

float chassisDiam = 0.4; // średnica pojazdu
int wheelDiam = 0.065; // średnica w metrach
float wheelCir = PI * wheelDiam; // obw koła w metrach
int maxRPM = 80; // obroty na minute RPM

void setup() {
  Serial.begin(9600);
  pinMode(napiecieSterowania, OUTPUT);
  digitalWrite(napiecieSterowania, HIGH); // włączone napięcie sterowania, tego nie ruszać
  pinMode(pwmLeft, OUTPUT); // PWM sterowanie prędkością obrotową dla całego pojazdu
  analogWrite(pwmLeft, 255); // 255 to maksymalnie
  pinMode(pwmRight, OUTPUT); // PWM sterowanie prędkością obrotową dla całego pojazdu
  analogWrite(pwmRight, 255); // 255 to maksymalnie
}

int forward(){
  bool backward = false;
  if (velocity < 0){
    backward = true;
    velocity = abs(velocity);
  }
  float rpm = velocity / wheelCir; // wyliczanie rpm
  int pwmStraight = map(rpm, 0, maxRPM, 0, 255); // mapowanie na zakres PWMa 0-255
  return pwmStraight, backward;
}

int turn(){
  bool clockwise = true;
  if (turnSpeed < 0){
    clockwise = false;
    clockwise = abs(clockwise);
  }
  float turnTime = 2 * PI / turnSpeed; // ile sekund ma zająć obrót
  float wheelSpeed = 2 * PI * chassisDiam / turnTime; // prędkość na koło
  float rpm = wheelSpeed / wheelCir; // wyliczanie rpm
  int pwmTurn = map(rpm, 0, maxRPM, 0, 255); // mapowanie na zakres PWMa 0-255
  return pwmTurn, clockwise; // w zależności od clockwise, prędkość dajemy na koło true -> lewe, false -> prawe
}

int sumSpeed(){
  bool backward;
  int pwmStraight;
  pwmStraight, backward = forward();
  int pwmTurn;
  bool clockwise;
  pwmTurn, clockwise = turn();
  // Dodać zmienę przód tył w zależności od zmiennej backward, znajac piny kół zmieni się z HIGH na LOW.
  if (clockwise){
    if (pwmStraight + pwmTurn > 255){
      analogWrite(pwmLeft, 255); // ustawiwnie predkosci koła lewego
      analogWrite(pwmRight, 255 - pwmTurn); // ustawiwnie predkosci koła prawego
    }else{
      analogWrite(pwmLeft, pwmStraight + pwmTurn); // ustawiwnie predkosci koła lewego
      analogWrite(pwmRight, pwmStraight); // ustawiwnie predkosci koła prawego
    }
  }else{
    if (pwmStraight + pwmTurn > 255){
      analogWrite(pwmLeft, 255 - pwmTurn); // ustawiwnie predkosci koła lewego
      analogWrite(pwmRight, 255); // ustawiwnie predkosci koła prawego
    }else{
      analogWrite(pwmLeft, pwmStraight); // ustawiwnie predkosci koła lewego
      analogWrite(pwmRight, pwmStraight + pwmTurn); // ustawiwnie predkosci koła prawego
    }
  }
}