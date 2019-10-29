#include <Keyboard.h>

int toLeft1 ;
int toLeft2 ;
int toRight1 ;
int toRight2 ;
int toJump1 ; 
int toJump2 ; 

int shelterKeyBoard = 12 ;

int rightSensor2 = A0 ;
int rightSensor1 = A1 ;  
int leftSensor2 = A2 ;
int leftSensor1 = A3;
int jumpSensor1 = A4 ;
int jumpSensor2 = A5 ;

void setup() {
  pinMode(shelterKeyBoard,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() 
{
  int allowKeyboard=digitalRead(shelterKeyBoard);

   if(allowKeyboard == LOW)
   {
    PressOn (' ', jumpSensor1, jumpSensor2);

    toLeft1 = analogRead(leftSensor1);
    toLeft2 = analogRead(leftSensor2);
    
    if(toLeft1 <= 15 || toLeft2 <= 15)
    {
        Keyboard.release(KEY_RIGHT_ARROW);
        Keyboard.press(KEY_LEFT_ARROW);
    }
    else
    {
          Keyboard.release(KEY_LEFT_ARROW);
    }
    

    toRight1 = analogRead(rightSensor1);
    toRight2 = analogRead(rightSensor2);

    Serial.println(toLeft1);    
    Serial.println(toLeft2);    
    Serial.println(toRight1);    
    Serial.println(toJump1);    
    
    if(toRight1 <= 15 || toRight2 <= -15 )
    {
        Keyboard.release(KEY_LEFT_ARROW);
        Keyboard.press(KEY_RIGHT_ARROW);
    }
    else
    {
        Keyboard.release(KEY_RIGHT_ARROW);
    }

      if( (toRight1 <= 15 || toRight2 <= -15) && (toJump1 <= 15 || toJump2 <= 15) )
      {
        Keyboard.press(KEY_RIGHT_ARROW);
        delay (30);
        Keyboard.press(' ');
        //Keyboard.release (' ');
      }

      //if
      if( (toLeft1 <= 15 || toLeft2 <= 15) && (toJump1 <= 15 || toJump2 <= 15) )
      {
        Keyboard.press(KEY_LEFT_ARROW);
        delay (30);
        Keyboard.press(' ');
        //Keyboard.release (' ');
      }
        Keyboard.release(' ');
   }    
else 
{
  Keyboard.release(' ');
  Keyboard.release(KEY_LEFT_ARROW);
  Keyboard.release(KEY_RIGHT_ARROW);
}
}

//---------------------------------functions-----------------//
//function for jump .
void PressOn(char toPressOn, int leg1, int leg2)
{
  toJump1 = analogRead(leg1);
  toJump2 = analogRead(leg2);
  //Keyboard.press(toPressOn);
  //toJump3 = analogRead(leg3);
  //toJump4 = analogRead(leg4)  ;
  
    if(toJump1 <= 15 || toJump2 <= 15)
    {
       Keyboard.press(toPressOn);
                       //Keyboard.release(toPressOn                 );
    }
    Serial.println(toJump1);    
    Serial.println(toJump2);
  } 
