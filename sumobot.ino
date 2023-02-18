#include <NewPing.h>

int motora1 = 2;
int motora2 = 3;
int motorb1 = 5;
int motorb2 = 4;
int enablea = 6;
int enableb = 7;

int trigPin = 8; //white
int echoPin = 9; //brown

int l1= 11; //white
int c1= 12; //orange
int r1= 13; //brown

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trigPin, echoPin, maximum_distance); //sensor function

void setup(){
  
  pinMode(motora1, OUTPUT);
  pinMode(motora2, OUTPUT);
  pinMode(motorb1, OUTPUT);
  pinMode(motorb2, OUTPUT);

  pinMode(trigPin, OUTPUT);      
  pinMode(echoPin, INPUT);

  pinMode(l1, INPUT);
  pinMode(c1, INPUT);
  pinMode(r1, INPUT);
  
  Serial.begin (9600);
}


void loop (){
  
  int Lsensor = digitalRead(11);
  int Csensor = digitalRead(12);
  int Rsensor = digitalRead(13);  


  Serial.println(Rsensor);
 

  if((Csensor == 1) && (Rsensor == 1) && (Lsensor == 1)) 
  {moveForward();
  
  }
  if((Lsensor == 0) && (Rsensor == 1) && (Csensor == 1))
   {
      moveStop();
      moveBackward();
      delay(500);
      turnLeft;
      delay(800);
   }
  if((Rsensor == 0) && (Lsensor == 1) && (Csensor == 1))
   {
      moveStop();
      moveBackward();
      delay(500);
      turnLeft();
      delay(800);
    }
  if((Csensor == 0) && (Rsensor == 0) && (Lsensor == 0))
   {
      moveStop();
      moveBackward();
      delay(500);
      turnRight();
      delay(800);
   }

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);  

  if (distance <= 30){
    moveForward();
    delay(1000);
  
  if (distance >= distanceLeft){
      turnLeft();
      moveForward();
    }
    else{
      turnRight();
      moveForward();
    }
  }
  else{
    moveForward(); 
  }
    distance = readPing();
}


int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  
  digitalWrite (motora1, HIGH);
  digitalWrite (motora2, HIGH);
  analogWrite  (enablea, 130);
  digitalWrite (motorb1, HIGH);
  digitalWrite (motorb2, HIGH);
  analogWrite (enableb, 130);
}

void moveForward(){
    
  digitalWrite (motora1, HIGH);
  digitalWrite (motora2, LOW);
  analogWrite (enablea, 130);
  digitalWrite (motorb1, HIGH);
  digitalWrite (motorb2, LOW);
  analogWrite (enableb, 130);
}

void moveBackward(){

  digitalWrite (motora1, LOW);
  digitalWrite (motora2, HIGH);
  analogWrite (enablea, 130);
  digitalWrite (motorb1, LOW);
  digitalWrite (motorb2, HIGH);
  analogWrite (enableb, 130);
  
}

void turnRight(){

  digitalWrite (motora1, HIGH);
  digitalWrite (motora2, LOW);
  analogWrite (enablea, 130);
  digitalWrite (motorb1, LOW);
  digitalWrite (motorb2, HIGH);
  analogWrite (enableb, 130);
}

void turnLeft(){

  digitalWrite (motora1, LOW);
  digitalWrite (motora2, HIGH);
  analogWrite (enablea, 130);
  digitalWrite (motorb1, HIGH);
  digitalWrite (motorb2, LOW);
  analogWrite (enableb, 130);
}


  
