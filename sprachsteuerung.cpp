#include <Servo.h>
Servo myservo;

String voice;
int richtungA           =12;
int richtungB           =13; 
int pwmA                =3;
int pwmB                =11;
int bremseA             =9;
int bremseB             =8;
int geschwindigkeit   =140;
int winkel             =90;
int led               =7;


void servorechts(){
  for (winkel = 90; winkel <= 180; winkel += 1) { 
    delay(15);  
    myservo.write(winkel);
}
}

void servolinks(){
 for (winkel = 90; winkel >= 0; winkel -= 1) { 
    delay(15);  
    myservo.write(winkel);
 }
}
    
void vor() {
  digitalWrite(richtungA, HIGH);
  digitalWrite(richtungB, HIGH);
  digitalWrite(bremseA, LOW);
  digitalWrite(bremseB, LOW);
}
void zurueck() {
  digitalWrite(richtungA, LOW);
  digitalWrite(richtungB, LOW);
  digitalWrite(bremseA, LOW);
  digitalWrite(bremseB, LOW);
}
void rechts() {
  digitalWrite(richtungA, HIGH);
  digitalWrite(richtungB, LOW);
  digitalWrite(bremseA, LOW);
  digitalWrite(bremseB, LOW);
}
void links() {
  digitalWrite(richtungA, LOW);
  digitalWrite(richtungB, HIGH);
  digitalWrite(bremseA, LOW);
  digitalWrite(bremseB, LOW);
}

void halt() {
  digitalWrite(bremseA, HIGH);
  digitalWrite(bremseB, HIGH);
}

void lichtan() {
  digitalWrite(led, HIGH);
  }
void lichtaus() {
  digitalWrite(led, LOW);
  }
void setup() {
  
  Serial.begin(9600);
  myservo.attach(5);
  pinMode(richtungA, OUTPUT);  
  pinMode(richtungB, OUTPUT);  
  pinMode(bremseA, OUTPUT);
  pinMode(bremseB, OUTPUT);
  analogWrite(pwmA, geschwindigkeit);
  analogWrite(pwmB, geschwindigkeit);
  digitalWrite(bremseA, HIGH);
  digitalWrite(bremseB, HIGH);
}

void loop() {
  while (Serial.available()){
    delay(10);
    char c=Serial.read();
    if (c=='#') {break;}
    voice +=c;
  }
   if (voice.length() > 0){
    Serial.println(voice);
  }
  if(voice == "*vor") 
    {vor();}
  else if(voice == "*zurück") 
    {zurueck();}
  else if(voice == "*rechts") 
    {rechts();}
  else if(voice == "*links") 
    {links();}
  else if(voice == "*halt") 
   {halt();}
  else if(voice == "*licht an") 
   {lichtan();}
  else if(voice == "*licht aus") 
   {lichtaus();}
  else if(voice == "*servo rechts") 
   {servorechts();}
  else if(voice =="*servo links")
   {servolinks();}
   
   voice="";}
