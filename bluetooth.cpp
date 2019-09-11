#include <Servo.h> //Servo Bibliothek einbinden                          
Servo myservo; //Servo mit myservo ansprechen
int winkel=90; //Servo auf 90 Grad

char blueToothVal;
char lastValue;
int richtungA           =12;
int pwmA                =3;
int bremseA             =9;

int richtungB         =13;
int pwmB              =11;
int bremseB           =8;
int geschwindigkeit   =255;  

int led=7; //Licht an Pin 7

void setup() {

  pinMode(led,OUTPUT); //Pin 7 als Output
  myservo.attach(5); //Servo an Pin 5
  Serial.begin(9600); //serielle Kommunikation starten
  pinMode(richtungA, OUTPUT); //richtungA als Output festlegen
  pinMode(bremseA, OUTPUT); //bremseA als Output festlegen
  analogWrite(pwmA, geschwindigkeit); //Geschwindigkeit A an Pin 3 
  pinMode(richtungB, OUTPUT); //richtungB als Output 
  pinMode(bremseB, OUTPUT); //bremseB als Output
  analogWrite(pwmB , geschwindigkeit); //Geschwindigkeit auf Pin 11
  
  digitalWrite(bremseA, HIGH);
  digitalWrite(bremseB, HIGH);  
 }

void loop() {
  if(Serial.available())
  {
    blueToothVal=Serial.read();
  }
  
  if (blueToothVal=='0')                              //Motor stopp
  {
    digitalWrite(bremseA, HIGH);
    digitalWrite(bremseB, HIGH);
  }
  
  else if(blueToothVal=='1')                          //vorwärts fahren bei empfangener 1
  {
    digitalWrite(bremseA, LOW);
    digitalWrite(bremseB, LOW);
    digitalWrite(richtungA, HIGH);
    digitalWrite(richtungB, HIGH);
    lastValue=blueToothVal;
  }
  
  else if(blueToothVal=='2')                          //rückwärts fahren bei empfangener 2
  {
    digitalWrite(bremseA, LOW);
    digitalWrite(bremseB, LOW);
    digitalWrite(richtungA, LOW);
    digitalWrite(richtungB, LOW);
    lastValue=blueToothVal;
  }
  
  else if (blueToothVal=='3')                          //links fahren bei empfangener 3
  {
    digitalWrite(bremseA, LOW);
    digitalWrite(bremseB, LOW);
    digitalWrite(richtungA, HIGH);
    digitalWrite(richtungB, LOW);
    lastValue=blueToothVal;
  }

  else if (blueToothVal=='4')                           //rechts fahren bei empfangener 4
  {
    digitalWrite(bremseA, LOW);
    digitalWrite(bremseB, LOW);
    digitalWrite(richtungA, LOW);
    digitalWrite(richtungB, HIGH);
    lastValue=blueToothVal;
  }

  else if (blueToothVal=='5')                               //servo auf 180 Grad
  {
    for (winkel = 90; winkel <= 180; winkel += 1) { //solange Winkel kleiner als 180 Grad,um 1 Grad erhöhen 
    delay(15);              //15 ms bis Endposition
    myservo.write(winkel);
      }
  }
  
  else if (blueToothVal=='6') //servo auf 0 Grad
  {
    for (winkel = 90; winkel >= 0; winkel -= 1) { //solange Winkel größer als 0 Grad ist, um // 1 Grad verringern
    delay(15);              //15 ms bis Endposition
    myservo.write(winkel); //Servo auf Position in Variable Winkel       
        //fahren
      }
    }
  
  else if (blueToothVal=='7') //servo auf Mittelstellung 90 Grad
  {
    winkel=90;
    myservo.write(winkel);
   
  }
  
  else if (blueToothVal=='8') //LED an
  {
    digitalWrite(led,HIGH);
  }
  
  else if (blueToothVal=='9') //LED aus
  {
    digitalWrite(led,LOW);
  }
  }
