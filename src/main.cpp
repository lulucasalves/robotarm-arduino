#include <Servo.h>

Servo base;
Servo servoCima;
Servo servoBaixo;
Servo garra;

int basePort = 8;
int servoCimaPort = 9;
int servoBaixoPort = 10;
int garraPort = 11;

int potenciometroPort1 = A0;
int potenciometroPort2 = A1;
int potenciometroPort3 = A2;
int potenciometroPort4 = A3;

int potenciometroVal1;
int potenciometroVal2;
int potenciometroVal3;
int potenciometroVal4;

void setup()
{
  base.attach(basePort);
  servoCima.attach(servoCimaPort);
  servoBaixo.attach(servoBaixoPort);
  garra.attach(garraPort);

  Serial.begin(9600);
}

void loop()
{
  potenciometroVal1 = map(analogRead(potenciometroPort1), 0, 1023, 0, 180);
  potenciometroVal2 = map(analogRead(potenciometroPort2), 0, 1023, 0, 180);
  potenciometroVal3 = map(analogRead(potenciometroPort3), 0, 1023, 0, 180);
  potenciometroVal4 = map(analogRead(potenciometroPort4), 0, 1023, 0, 180);

  base.write(potenciometroVal1);
  servoCima.write(potenciometroVal2);
  servoBaixo.write(potenciometroVal3);
  garra.write(potenciometroVal4);

  Serial.print("Motor Base: ");
  Serial.println(potenciometroVal1);

  Serial.print("Motor Cima: ");
  Serial.println(potenciometroVal2);

  Serial.print("Motor Baixo: ");
  Serial.println(potenciometroVal3);

  Serial.print("Motor Garra: ");
  Serial.println(potenciometroVal4);

  delay(100);
}