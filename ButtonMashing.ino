/*
  Name: SomeNerdNamedSteve
  Date: March 12th, 2017
  Project: Hello, Arduino, 
  Purpose: Teach the basics of Arduino programming
*/

//library imports
#include "Keypad.h"

//Global Variables

//define number of rows and columns.
#define ROWS 4
#define COLS 4

//Seven Segment Display pins
#define A 2
#define B 4
#define C 6
#define D 8
#define E 10
#define F 12
#define G 22

//array declaration
int sevSegPinArr[] = {A,B,C,D,E,F,G};

//declare array size for sdevSegPinArr
int arrSize = sizeof(sevSegPinArr)/sizeof(int);

//Array for the key columns and rows
char keys[ROWS][COLS] = 
{ {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'E', '0', 'F', 'D'}
};

//Rows 0 to 3
byte rPins[ROWS]= {35,33,39,41};

//Columns 0 to 3
byte cPins[COLS]= {45,47,51,53}; 

Keypad kpd = Keypad(makeKeymap(keys), rPins, cPins, ROWS, COLS);

//this function runs once, but for initialization
void setup() 
{
  //set all pins to output
  for(int i = 0; i < arrSize; i++){ pinMode(sevSegPinArr[i], OUTPUT); }
}

//This function will loop infinitely
void loop() 
{
  char keyPressed = kpd.getKey();
   
  //if a key is pressed, display the key pressed
  if (keyPressed != NO_KEY)
  { 
    printKeyValue(keyPressed);
  }

}

//print the key value and check if input is 
//* or #
void printKeyValue(char c)
{

  //reset pins to LOW
  for(int i = 0; i < arrSize; i++){ digitalWrite(sevSegPinArr[i], LOW); }
  
  if(c == '0')
  { //display 0
    for(int i = 0; i < arrSize; i++)
    {
      if(sevSegPinArr[i] != G){ digitalWrite(sevSegPinArr[i], HIGH); }
    }
  } 
  else if(c == '1')
  { //display 1
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
  } 
  else if(c == '2')
  { //display 2
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(D, HIGH);
  } 
  else if(c == '3')
  { //display 3
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
  } 
  else if(c == '4')
  { //display 4
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  } 
  else if(c == '5')
  { //display 5
    digitalWrite(A, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
  } 
  else if(c == '6')
  { //display 6
    digitalWrite(A, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
  } 
  else if(c == '7')
  { //display 7
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
  } 
  else if(c == '8')
  { //display 8
    for(int i = 0; i < arrSize; i++){ digitalWrite(sevSegPinArr[i], HIGH); }
  } 
  else if(c == '9')
  { //display 9
     for(int i = 0; i < arrSize; i++)
    {
      if(sevSegPinArr[i] != E){ digitalWrite(sevSegPinArr[i], HIGH); }
    }
  } 
  else if(c == 'A')
  { //display A
     for(int i = 0; i < arrSize; i++)
    {
      if(sevSegPinArr[i] != D){ digitalWrite(sevSegPinArr[i], HIGH); }
    }
  } 
  else if(c == 'B')
  { //display B
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
  } 
  else if(c == 'C')
  { //display C
    digitalWrite(A, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(D, HIGH);
  } 
  else if(c == 'D')
  { //display D
    digitalWrite(E, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
  } 
  else if(c == 'E')
  { //display E
    digitalWrite(A, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  } 
  else if(c == 'F')
  { //display F
    digitalWrite(A, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  }

}

