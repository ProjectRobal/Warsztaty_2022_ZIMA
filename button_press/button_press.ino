/*
 Przykład przedstawiający zapalenie diody po naciśnięciu przycisku.

 Funkcja pinMode oraz digitalWrite może się przydać przy sterowaniu silników.
*/

//opcjonalne na Arduino IDE
#include <Arduino.h>

// wbudowana w pico dioda LED na pinie 25
#define LED 25

// podłącz przycisku do tego pinu, może być dowolny inny pin
#define BUTTON 16 

void setup() {
  // put your setup code here, to run once:

  // ustawienie pinu 25 jako wyjście
  pinMode(LED,OUTPUT);

  // ustawienie pinu z przyciskiem na wejście z wenwnętrznym rezystorem podpiętym do zasilania
  pinMode(BUTTON,INPUT_PULLUP);

  // tak też można ale do pinu musisz jeszcze podpiąć rezystor podciągnięty do zasilania
  //pinMode(BUTTON,INPUT);

  //ustawienie pinu 25 w stan niski (równoważne z zgaszeniem diody)
  digitalWrite(LED,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  //odczytaj stan przycisku
  bool button_state=digitalRead(BUTTON);

  //przypisz stan pinu do stanu wyjścia diody
  digitalWrite(LED,!button_state);
}
