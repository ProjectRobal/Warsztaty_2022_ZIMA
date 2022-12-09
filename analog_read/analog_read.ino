/*
  Przykład odczytu danych z pinów analogowych.
A także przykład zastosowania enum.
*/

#include <Arduino.h>

// analog pins
#define A1 28
#define A2 27
#define A3 26

#define THRESHOLD 256

// przydatny enum
enum Direction
{
  LEFT,
  RIGHT,
  FORWARD,
  BACKWARD,
  NOPE,
  WHATEVER
}; 

// funkcja do podejmowania decyzji
Direction make_decision()
{
  uint16_t left=analogRead(A1);
  uint16_t right=analogRead(A2);
  uint16_t back=analogRead(A3);

  if(back<=THRESHOLD)
  {
    return Direction::BACKWARD;
  }
  
  if(left<=THRESHOLD)
  {
    return Direction::LEFT;
  }

  if(right<=THRESHOLD)
  {
    return Direction::RIGHT;
  }

  return Direction::FORWARD;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin();

  //ustawienie pinów analogowych jako wyjście
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  Direction dir=make_decision();

  // switch potrafi być szybszy od if
  switch(dir)
  {
    case Direction::LEFT:

    Serial.println("Go left!");

    break;

    case Direction::RIGHT:

    Serial.println("Go right!");

    break;

    case Direction::FORWARD:

    Serial.println("Go forward!");

    break;

    case Direction::BACKWARD:

    Serial.println("Go backward!");

    break;
    default:
    Serial.println("nope");
  }

  //czekaj 500 ms
  delay(500);
}
