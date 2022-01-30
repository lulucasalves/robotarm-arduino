#include <NewPing.h>
#include <Servo.h>

#define pino_trigger 3
#define pino_echo 2

NewPing sonar(pino_trigger, pino_echo, 200);

Servo base;
Servo servoCima;
Servo servoBaixo; //max 150 min 170
Servo garra; //max 70 min 40

int basePort = 8;
int servoCimaPort = 9;
int servoBaixoPort = 10;
int garraPort = 11;

int eyes = sonar.ping_cm();

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
  int eyes = sonar.ping_cm();

  //sensor
  base.write(10);
  garra.write(80);
  servoCima.write(40);
  servoBaixo.write(165);

  if (eyes < 4) {
    delay(500);
    servoBaixo.write(180);
    servoCima.write(85);
    
    delay(1000);
    garra.write(30);

    delay(3000);
    servoCima.write(180);
    servoBaixo.write(150);

    delay(1000);
    base.write(120);

    delay(2000);
    garra.write(80);

    delay(2000);
    servoBaixo.write(120);
    servoCima.write(100);

    delay(2000);
  }
  else {
    Serial.print(sonar.ping_cm());
    Serial.println("cm");
  }

  delay(100);
}