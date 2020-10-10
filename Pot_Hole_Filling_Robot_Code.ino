#include <Servo.h>

Servo myservo;
int pos = 0; 

int IR1_Right =12;

int IR2_Left =11;

//servo pin 10

int trigger_pin_up=9;
int echo_pin_up=8;
int time_up;
int distance_up; 

int trigger_pin_down = 7;
int echo_pin_down = 6;
int time_down;
int distance_down;

void setup ( ) {

        Serial.begin (9600); 
        myservo.attach(10);

        pinMode (trigger_pin_down, OUTPUT); 

        pinMode (echo_pin_down, INPUT);

        pinMode (trigger_pin_up, OUTPUT); 

        pinMode (echo_pin_up, INPUT);

        pinMode (IR1_Right,INPUT);
        pinMode(IR2_Left,INPUT);

        pinMode(2, OUTPUT);
        pinMode(3, OUTPUT);
        pinMode(4, OUTPUT);
        pinMode(5, OUTPUT);


}


void loop ( ) 
{

    int statusSensor_Right = digitalRead (IR1_Right);
    int statusSensor_Left = digitalRead (IR2_Left);
    digitalWrite (trigger_pin_up, HIGH);

    delayMicroseconds (10);

    digitalWrite (trigger_pin_up, LOW);

    time_up = pulseIn (echo_pin_up, HIGH);

    distance_up = (time_up * 0.034) / 2;



    digitalWrite (trigger_pin_down, HIGH);

    delayMicroseconds (10);

    digitalWrite (trigger_pin_down, LOW);

    time_down = pulseIn (echo_pin_down, HIGH);

    distance_down= (time_down * 0.034) / 2;

  if (distance_up <= 10) 

 {
  digitalWrite(2, HIGH);   
 
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);   
  digitalWrite(5, HIGH);

  delay(2000);

 }

  if (distance_down >= 5) 
  {

    
  digitalWrite(2, HIGH);   
  digitalWrite(3, LOW); 
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  }
  else
  {
  digitalWrite(2, HIGH);   
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);  
  digitalWrite(5, HIGH);
  delay(800);
     for(int i=0;i< 2; i++)
    {
    for (pos = 0; pos <= 180; pos += 1) 
      { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
    }
  }



  if (statusSensor_Right == 0)
  {
      digitalWrite(2, HIGH);   
      digitalWrite(3, LOW); 
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      delay(800);
  }
  
  else 
  {

  digitalWrite(2, HIGH);   
  digitalWrite(3, LOW); 
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  } 


  if (statusSensor_Left == 0)
  {
      digitalWrite(2, HIGH);   
      digitalWrite(3, HIGH); 
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      delay(800);
  }
 else 
 {

  digitalWrite(2, HIGH);   
  digitalWrite(3, LOW); 
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
       

  } 


 if (statusSensor_Left==0 && statusSensor_Right==0 && distance_up <= 10)
 {
      digitalWrite(2, HIGH);   
      digitalWrite(3, HIGH); 
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      delay(2000);

      for(int i=0;i<10;i++)
      {
        digitalWrite(2, LOW);   
        digitalWrite(3, HIGH); 
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        delay(500);
      }
 }
else
{
  digitalWrite(2, HIGH);   
  digitalWrite(3, LOW); 
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}





 if (statusSensor_Left==0 && distance_up <= 10)
 {
      digitalWrite(2, HIGH);   
      digitalWrite(3, HIGH); 
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      delay(2000);

      for(int i=0;i<20;i++)
      {
        digitalWrite(2, LOW);   
        digitalWrite(3, HIGH); 
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        delay(500);
      }

      for(int i=0;i<8;i++)
      {
        digitalWrite(2, HIGH);   
        digitalWrite(3, HIGH); 
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        delay(500);
      }
 }
else
{
  digitalWrite(2, HIGH);   
  digitalWrite(3, LOW); 
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}




 if (statusSensor_Right==0 && distance_up <= 10)
 {
      digitalWrite(2, HIGH);   
      digitalWrite(3, HIGH); 
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      delay(2000);

      for(int i=0;i<20;i++)
      {
        digitalWrite(2, LOW);   
        digitalWrite(3, HIGH); 
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        delay(500);
      }

      for(int i=0;i<8;i++)
      {
        digitalWrite(2, HIGH);   
        digitalWrite(3, LOW); 
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        delay(500);
      }
 }
else
{
  digitalWrite(2, HIGH);   
  digitalWrite(3, LOW); 
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}







  }
