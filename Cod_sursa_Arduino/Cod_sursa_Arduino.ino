/*-------------------Librarii PCA9685-------------------*/
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
/*------------------------------------------------------*/
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();  /*atribuire adresa default 0x40 pentru PCA9685 */

/*-------------------Variabile pentru calibrare Servo-------------------*/
#define ServoMotorSenzorFataMINIM  110  
#define ServoMotorSenzorFataMAXIM  480     

#define ServoMotorSenzorCameraJosMINIM 145    
#define ServoMotorSenzorCameraJosMAXIM 510     

#define ServoMotorSenzorCameraSusMINIM 130        
#define ServoMotorSenzorCameraSusMAXIM 470       

/*-------------------Variabile Driver L298N-------------------*/
int Motor_IN1 = 7;
int Motor_IN2 = 4;
int Motor_IN3 = 3;
int Motor_IN4 = 2;
int ENA = 5;
int ENB = 6;

int eroareInainte=12;  
int eroareInapoi=10; 

int vSpeed; //Viteza Motoare
String inputString;
int Led_StangaPin = A0;
int Led_DreaptaPin = A1;
int Led_Viteza_1 = 10;
int Led_Viteza_2 = 11;
int Led_Viteza_3 = 13;
int Led_Viteza_4 = 12;

/*-------------------Variabile Pini Servo Motoare la PCA9685-------------------*/
int ServoMotorSenzorFata = 0;
int ServoMotorCameraJos = 1;
int ServoMotorCameraSus = 2;
/*-----------------------------------------------------------------------------*/

int UnghiMotorCameraSus;
int UnghiMotorCameraJos;
int UnghiMotorSenzorFata;

/*-------------------Variabile Senzor Ultrasonic-------------------*/
int Durata;
int Distanta;
int DistantaMINIMA = 20;

const int trigPin = 9;
const int EchoPin = 8;
/*-----------------------------------------------------------------*/

void setup() {
  Serial.begin(9600);
  /*-------------------Pini Driver L298N-------------------*/

  Serial.println("*******************************************************");
  Serial.println("********************Smart Video Car********************");
  Serial.println("*****************Asavei Adelin-Petrisor****************");
  Serial.println("*******************************************************");
  
  pinMode(Motor_IN1, OUTPUT);
  pinMode(Motor_IN2, OUTPUT);
  pinMode(Motor_IN3, OUTPUT);
  pinMode(Motor_IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(Led_StangaPin, OUTPUT);
  pinMode(Led_DreaptaPin, OUTPUT);
  pinMode(Led_Viteza_1, OUTPUT);
  pinMode(Led_Viteza_2, OUTPUT);
  pinMode(Led_Viteza_3, OUTPUT);
  pinMode(Led_Viteza_4, OUTPUT);
      
  /*-------------------Pini Senzor Ultrasonic-------------------*/
  pinMode(trigPin, OUTPUT);
  pinMode(EchoPin, INPUT);

  pwm.begin();                    /*initializare librarie*/
  pwm.setPWMFreq(50);             /*frecventa PCA9685 */

  Viteza_Masina_0();
  UnghiMotorSenzorFata =85;
  pwm.setPWM(ServoMotorSenzorFata, 0 , CalculUnghi(UnghiMotorSenzorFata, ServoMotorSenzorFataMINIM, ServoMotorSenzorFataMAXIM));

  UnghiMotorCameraSus = 90;
  pwm.setPWM(ServoMotorCameraSus, 0 , CalculUnghi(UnghiMotorCameraSus, ServoMotorSenzorCameraSusMINIM, ServoMotorSenzorCameraSusMAXIM));

  UnghiMotorCameraJos = 90;
  pwm.setPWM(ServoMotorCameraJos, 0 , CalculUnghi(UnghiMotorCameraJos, ServoMotorSenzorCameraJosMINIM, ServoMotorSenzorCameraJosMAXIM));
}
void Viteza_Masina_0()
{
  vSpeed = 0;
  analogWrite(ENA, vSpeed);
  analogWrite(ENB, vSpeed);
  digitalWrite(Led_Viteza_1, LOW);
  digitalWrite(Led_Viteza_2, LOW);
  digitalWrite(Led_Viteza_3, LOW);
  digitalWrite(Led_Viteza_4, LOW);
  Serial.println("Viteza 0 activata");
}
void Viteza_Masina1()
{
  if ((digitalRead(Motor_IN1) == LOW) && (digitalRead(Motor_IN2) == LOW) && (digitalRead(Motor_IN3) == LOW) && (digitalRead(Motor_IN4) == LOW))
  {
    digitalWrite(Led_Viteza_1, LOW);
    digitalWrite(Led_Viteza_2, LOW);
    digitalWrite(Led_Viteza_3, LOW);
    digitalWrite(Led_Viteza_4, LOW);
  }
  else
  {
    vSpeed = 150;
    if (digitalRead(Motor_IN1) == LOW && digitalRead(Motor_IN2) == HIGH && digitalRead(Motor_IN3) == HIGH && digitalRead(Motor_IN4) == LOW)
    {
      analogWrite(ENA, vSpeed + eroareInainte);
      analogWrite(ENB, vSpeed);
    }
    else if ( digitalRead(Motor_IN1) == HIGH && digitalRead(Motor_IN2) == LOW && digitalRead(Motor_IN3) == LOW && digitalRead(Motor_IN4) == HIGH)
    {
      analogWrite(ENA, vSpeed + eroareInapoi);
      analogWrite(ENB, vSpeed);
    }
    digitalWrite(Led_Viteza_1, HIGH);
    digitalWrite(Led_Viteza_2, LOW);
    digitalWrite(Led_Viteza_3, LOW);
    digitalWrite(Led_Viteza_4, LOW);
  }
}
void Viteza_Masina2()
{
  if ((digitalRead(Motor_IN1) == LOW) && (digitalRead(Motor_IN2) == LOW) && (digitalRead(Motor_IN3) == LOW) && (digitalRead(Motor_IN4) == LOW))
  {
    digitalWrite(Led_Viteza_1, LOW);
    digitalWrite(Led_Viteza_2, LOW);
    digitalWrite(Led_Viteza_3, LOW);
    digitalWrite(Led_Viteza_4, LOW);
  }
  else
  {
    vSpeed = 190;
    if (digitalRead(Motor_IN1) == LOW && digitalRead(Motor_IN2) == HIGH && digitalRead(Motor_IN3) == HIGH && digitalRead(Motor_IN4) == LOW)
    {
      analogWrite(ENA, vSpeed + eroareInainte);
      analogWrite(ENB, vSpeed);
    }
    else if ( digitalRead(Motor_IN1) == HIGH && digitalRead(Motor_IN2) == LOW && digitalRead(Motor_IN3) == LOW && digitalRead(Motor_IN4) == HIGH)
    {
      analogWrite(ENA, vSpeed + eroareInapoi);
      analogWrite(ENB, vSpeed);
    }
    digitalWrite(Led_Viteza_1, LOW);
    digitalWrite(Led_Viteza_2, HIGH);
    digitalWrite(Led_Viteza_3, LOW);
    digitalWrite(Led_Viteza_4, LOW);
  }
}
void Viteza_Masina3()
{

  if (digitalRead(Motor_IN1) == LOW && digitalRead(Motor_IN2) == LOW && digitalRead(Motor_IN3) == LOW && digitalRead(Motor_IN4) == LOW)
  {
    digitalWrite(Led_Viteza_1, LOW);
    digitalWrite(Led_Viteza_2, LOW);
    digitalWrite(Led_Viteza_3, LOW);
    digitalWrite(Led_Viteza_4, LOW);
  }
  else
  {
    vSpeed = 220;
    if (digitalRead(Motor_IN1) == LOW && digitalRead(Motor_IN2) == HIGH && digitalRead(Motor_IN3) == HIGH && digitalRead(Motor_IN4) == LOW)
    {
      analogWrite(ENA, vSpeed + eroareInainte);
      analogWrite(ENB, vSpeed);
    }
    else if ( digitalRead(Motor_IN1) == HIGH && digitalRead(Motor_IN2) == LOW && digitalRead(Motor_IN3) == LOW && digitalRead(Motor_IN4) == HIGH)
    {
      analogWrite(ENA, vSpeed + eroareInapoi);
      analogWrite(ENB, vSpeed);
    }
    digitalWrite(Led_Viteza_1, LOW);
    digitalWrite(Led_Viteza_2, LOW);
    digitalWrite(Led_Viteza_3, HIGH);
    digitalWrite(Led_Viteza_4, LOW);
  }
}
void Viteza_Masina4()
{
  if (digitalRead(Motor_IN1) == LOW && digitalRead(Motor_IN2) == LOW && digitalRead(Motor_IN3) == LOW && digitalRead(Motor_IN4) == LOW)
  {
    digitalWrite(Led_Viteza_1, LOW);
    digitalWrite(Led_Viteza_2, LOW);
    digitalWrite(Led_Viteza_3, LOW);
    digitalWrite(Led_Viteza_4, LOW);
  }
  else
  {
    vSpeed = 241;
    if (digitalRead(Motor_IN1) == LOW && digitalRead(Motor_IN2) == HIGH && digitalRead(Motor_IN3) == HIGH && digitalRead(Motor_IN4) == LOW)
    {
      analogWrite(ENA, vSpeed + eroareInainte);
      analogWrite(ENB, vSpeed);
    }
    else if ( digitalRead(Motor_IN1) == HIGH && digitalRead(Motor_IN2) == LOW && digitalRead(Motor_IN3) == LOW && digitalRead(Motor_IN4) == HIGH)
    {
      analogWrite(ENA, vSpeed + eroareInapoi);
      analogWrite(ENB, vSpeed);
    }
    digitalWrite(Led_Viteza_1, LOW);
    digitalWrite(Led_Viteza_2, LOW);
    digitalWrite(Led_Viteza_3, LOW);
    digitalWrite(Led_Viteza_4, HIGH);
  }
}

void Viteza_Dreapta_Stanga()
{
  vSpeed = 220;
  //analogWrite(ENA, vSpeed);
  //analogWrite(ENB, vSpeed);
  digitalWrite(Led_Viteza_1, LOW);
  digitalWrite(Led_Viteza_2, LOW);
  digitalWrite(Led_Viteza_3, HIGH);
  digitalWrite(Led_Viteza_4, LOW);
  Serial.println("Viteza (3) dreapta-stanga");
}

void Inainte()
{
  if (vSpeed == 0)
  {
    vSpeed = 150;
    analogWrite(ENA, vSpeed + eroareInainte);
    analogWrite(ENB, vSpeed);
    digitalWrite(Led_Viteza_1, HIGH);
    digitalWrite(Led_Viteza_2, LOW);
    digitalWrite(Led_Viteza_3, LOW);
    digitalWrite(Led_Viteza_4, LOW);
  }
  analogWrite(ENA, vSpeed + eroareInainte);
  analogWrite(ENB, vSpeed);
  digitalWrite(Motor_IN1, LOW);
  digitalWrite(Motor_IN2, HIGH);
  digitalWrite(Motor_IN3, HIGH);
  digitalWrite(Motor_IN4, LOW);
  Serial.println("Masina se misca inainte cu viteza cea mai mica.");
}

void Inapoi()
{
  if (vSpeed == 0)
  {
    vSpeed = 150;
    analogWrite(ENA, vSpeed + eroareInapoi);
    analogWrite(ENB, vSpeed);
    digitalWrite(Led_Viteza_1, HIGH);
    digitalWrite(Led_Viteza_2, LOW);
    digitalWrite(Led_Viteza_3, LOW);
    digitalWrite(Led_Viteza_4, LOW);
    Serial.println("Viteza 1 activata");
  }
  analogWrite(ENA, vSpeed + eroareInapoi);
  analogWrite(ENB, vSpeed);
  digitalWrite(Motor_IN1, HIGH);
  digitalWrite(Motor_IN2, LOW);
  digitalWrite(Motor_IN3, LOW);
  digitalWrite(Motor_IN4, HIGH);
  Serial.println("Masina se misca inapoicu viteza cea mai mica.");
}
void Stop()
{

  digitalWrite(Motor_IN1, LOW);
  digitalWrite(Motor_IN2, LOW);
  digitalWrite(Motor_IN3, LOW);
  digitalWrite(Motor_IN4, LOW);
  Viteza_Masina_0();
  Serial.println("Masina s-a oprit");
}

void InainteStanga()
{
  Viteza_Dreapta_Stanga();
  analogWrite(ENA, vSpeed);
  digitalWrite(Motor_IN1, LOW);
  digitalWrite(Motor_IN2, HIGH);
  digitalWrite(Motor_IN3, LOW);
  digitalWrite(Motor_IN4, LOW);
  Serial.println("Masina a mers Inainte-Stanga si s-a oprit");
}
void InapoiStanga()
{
  Viteza_Dreapta_Stanga();
  analogWrite(ENA, vSpeed+eroareInapoi);
  digitalWrite(Motor_IN1, HIGH);
  digitalWrite(Motor_IN2, LOW);
  digitalWrite(Motor_IN3, LOW);
  digitalWrite(Motor_IN4, LOW);
  Serial.println("Masina a mers Inapoi-Stanga si s-a oprit");
}

void InainteDreapta()
{
  Viteza_Dreapta_Stanga();
  analogWrite(ENB, vSpeed + eroareInainte);
  digitalWrite(Motor_IN1, LOW);
  digitalWrite(Motor_IN2, LOW);
  digitalWrite(Motor_IN3, HIGH);
  digitalWrite(Motor_IN4, LOW);
  Serial.println("Masina a mers Inainte-Dreapta si s-a oprit");
}
void InapoiDreapta()
{
  Viteza_Dreapta_Stanga();
  analogWrite(ENB, vSpeed + eroareInapoi);
  digitalWrite(Motor_IN1, LOW);
  digitalWrite(Motor_IN2, LOW);
  digitalWrite(Motor_IN3, LOW);
  digitalWrite(Motor_IN4, HIGH);
  Serial.println("Masina a mers Inapoi-Dreapta si s-a oprit");
}

void TimerLuminiOn()
{
  if (inputString == "InainteDreapta" || inputString == "InapoiDreapta")
  {
    for (int i = 0; i < 4; i++)
    {
      digitalWrite(Led_DreaptaPin, LOW);
      delay(190);
      digitalWrite(Led_DreaptaPin, HIGH);
      delay(190);
    }
  }
  else if (inputString == "InainteStanga" || inputString == "InapoiStanga")
  {
    for (int i = 0; i < 4; i++)
    {
      digitalWrite(Led_StangaPin, LOW);
      delay(190);
      digitalWrite(Led_StangaPin, HIGH);
      delay(190);
    }
  }
}
void TimerLuminiOff()
{
  if (inputString == "InainteStanga" || inputString == "InapoiStanga")
  {
    for (int i = 0; i < 4; i++)
    {
      digitalWrite(Led_StangaPin, HIGH);
      delay(190);
      digitalWrite(Led_StangaPin, LOW);
      delay(190);
    }
  }
  if (inputString == "InainteDreapta" || inputString == "InapoiDreapta")
  {
    for (int i = 0; i < 4; i++)
    {
      digitalWrite(Led_DreaptaPin, HIGH);
      delay(190);
      digitalWrite(Led_DreaptaPin, LOW);
      delay(190);
    }
  }
 
}
void LuminiOn()
{
  digitalWrite(Led_StangaPin, HIGH);
  digitalWrite(Led_DreaptaPin, HIGH);
  Serial.println("Lumini aprinse");
}
void LuminiOff()
{
  digitalWrite(Led_StangaPin, LOW);
  digitalWrite(Led_DreaptaPin, LOW);
  Serial.println("Lumini oprite");
}

int CalculUnghi(int unghi, int MINIM, int MAXIM)
{
  int pulse = map(unghi, 0, 180, MINIM, MAXIM);
  Serial.print("Unghi: "); Serial.print(unghi);
  Serial.print("      Pulse: "); Serial.print(pulse);
  Serial.println();
  return pulse;
}

void MasurareDistanta()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  Durata = pulseIn(EchoPin, HIGH);
  Distanta = Durata * 0.034 / 2;
  Serial.println("Distanta: ");
  Serial.print(Distanta);
  Serial.println("\n");
}
void VerificareDistanta()
{
  while (Serial.available() == 0)
  {
    MasurareDistanta();
    if ((Distanta < DistantaMINIMA))
    {
      Stop();
      break;
    }
  }
  if (Serial.available())
  {
    inputString = Serial.readString();
    inputString.trim();
    if (inputString == "LuminiOn" || (inputString == "LuminiOff") || (inputString == "VitezaUnu") || (inputString == "VitezaDoi") || (inputString == "VitezaTrei") || (inputString == "VitezaPatru") ||(inputString == "CameraSus")||(inputString == "CameraJos")||(inputString == "CameraStanga")||(inputString == "CameraDreapta"))
    {
      ValidareComenzi();
      VerificareDistanta();
    }
    else
    {
      ValidareComenzi();
    }
  }
}
void ValidareComenzi()
{
  int Led_Stanga = digitalRead(Led_StangaPin);
  int Led_Dreapta = digitalRead(Led_DreaptaPin);

  /*--------------------------------------------------------------------Comenzi masina--------------------------------------------------------------------*/
  if (inputString == "Inainte") {
    UnghiMotorSenzorFata = 85;
    pwm.setPWM(ServoMotorSenzorFata, 0 , CalculUnghi(UnghiMotorSenzorFata, ServoMotorSenzorFataMINIM, ServoMotorSenzorFataMAXIM));
    MasurareDistanta();
    if (Distanta > DistantaMINIMA )
    {
      Inainte();
      VerificareDistanta();
    }
    else
    {
      Stop();
    }
  }
  else if (inputString == "Inapoi") {
    Inapoi();
  }
  else if (inputString == "InainteDreapta") {
    UnghiMotorSenzorFata = 0;
    pwm.setPWM(ServoMotorSenzorFata, 0 , CalculUnghi(UnghiMotorSenzorFata, ServoMotorSenzorFataMINIM, ServoMotorSenzorFataMAXIM));
    delay(500);
    MasurareDistanta();
    if (Distanta > DistantaMINIMA)
    {
      UnghiMotorSenzorFata = 85;
      pwm.setPWM(ServoMotorSenzorFata, 0 , CalculUnghi(UnghiMotorSenzorFata, ServoMotorSenzorFataMINIM, ServoMotorSenzorFataMAXIM));
      Viteza_Dreapta_Stanga();
      if (Led_Stanga == HIGH && Led_Dreapta == HIGH)
      {
        InainteDreapta();
        TimerLuminiOn();
        Stop();
      }
      if (Led_Stanga == LOW && Led_Dreapta == LOW)
      {
        InainteDreapta();
        TimerLuminiOff();
        Stop();
      }
    }
    else
    {
      UnghiMotorSenzorFata = 85;
      pwm.setPWM(ServoMotorSenzorFata, 0 , CalculUnghi(UnghiMotorSenzorFata, ServoMotorSenzorFataMINIM, ServoMotorSenzorFataMAXIM));
    }

  }
  else if (inputString == "InainteStanga") {
    UnghiMotorSenzorFata = 180;
    pwm.setPWM(ServoMotorSenzorFata, 0 , CalculUnghi(UnghiMotorSenzorFata, ServoMotorSenzorFataMINIM, ServoMotorSenzorFataMAXIM));
    delay(500);
    MasurareDistanta();
    if (Distanta > DistantaMINIMA)
    {
      UnghiMotorSenzorFata = 85;
      pwm.setPWM(ServoMotorSenzorFata, 0 , CalculUnghi(UnghiMotorSenzorFata, ServoMotorSenzorFataMINIM, ServoMotorSenzorFataMAXIM));
      Viteza_Dreapta_Stanga();
      if (Led_Stanga == HIGH && Led_Dreapta == HIGH)
      {
        InainteStanga();
        TimerLuminiOn();
        Stop();

      }
      if (Led_Stanga == LOW && Led_Dreapta == LOW)
      {
        InainteStanga();
        TimerLuminiOff();
        Stop();
      }
    }
    else
    {
      UnghiMotorSenzorFata = 85;
      pwm.setPWM(ServoMotorSenzorFata, 0 , CalculUnghi(UnghiMotorSenzorFata, ServoMotorSenzorFataMINIM, ServoMotorSenzorFataMAXIM));
    }

  }
  else if ( inputString == "InapoiDreapta") {
    Viteza_Dreapta_Stanga();
    if (Led_Stanga == HIGH && Led_Dreapta == HIGH)
    {
      InapoiDreapta();
      TimerLuminiOn();
      Stop();
    }
    if (Led_Stanga == LOW && Led_Dreapta == LOW)
    {
      InapoiDreapta();
      TimerLuminiOff();
      Stop();
    }
  }
  else if ( inputString == "InapoiStanga") {
    Viteza_Dreapta_Stanga();
    if (Led_Stanga == HIGH && Led_Dreapta == HIGH)
    {
      InapoiStanga();
      TimerLuminiOn();
      Stop();
    }
    if (Led_Stanga == LOW && Led_Dreapta == LOW)
    {
      InapoiStanga();
      TimerLuminiOff();
      Stop();
    }
  }
  else if ( inputString == "Stop") {
    Stop();
  }
  else if ( inputString == "LuminiOn") {
    LuminiOn();
  }
  else if ( inputString == "LuminiOff") {
    LuminiOff();
  }
  else if ( inputString == "VitezaUnu") {
    Viteza_Masina1();
  }
  else if ( inputString == "VitezaDoi") {
    Viteza_Masina2();
  }
  else if ( inputString == "VitezaTrei") {
    Viteza_Masina3();
  }
  else if ( inputString == "VitezaPatru") {
    Viteza_Masina4();
  }
  else if ( inputString == "CameraSus") {
    if (UnghiMotorCameraSus > 0)
    {
      UnghiMotorCameraSus -= 45;
      pwm.setPWM(ServoMotorCameraSus, 0 , CalculUnghi(UnghiMotorCameraSus, ServoMotorSenzorCameraSusMINIM, ServoMotorSenzorCameraSusMAXIM));
      delay(15);
    }
  }
  else if ( inputString == "CameraJos") {
    if (UnghiMotorCameraSus < 90)
    {
      UnghiMotorCameraSus += 45;
      pwm.setPWM(ServoMotorCameraSus, 0 , CalculUnghi(UnghiMotorCameraSus, ServoMotorSenzorCameraSusMINIM, ServoMotorSenzorCameraSusMAXIM));
    }
  }
  else if ( inputString == "CameraStanga") {
    if (UnghiMotorCameraJos < 180)
    {
      UnghiMotorCameraJos += 45;
      pwm.setPWM(ServoMotorCameraJos, 0 , CalculUnghi(UnghiMotorCameraJos, ServoMotorSenzorCameraJosMINIM, ServoMotorSenzorCameraJosMAXIM));
    }
  }
  else if ( inputString == "CameraDreapta") {
    if (UnghiMotorCameraJos > 0)
    {
      UnghiMotorCameraJos -= 45;
      pwm.setPWM(ServoMotorCameraJos, 0 , CalculUnghi(UnghiMotorCameraJos, ServoMotorSenzorCameraJosMINIM, ServoMotorSenzorCameraJosMAXIM));
    }
  }

}
void loop() {
  if (Serial.available())
  {
    inputString = Serial.readString();
    inputString.trim();
    ValidareComenzi();
  }
}
