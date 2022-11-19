/*
 Przykład przedstawiający zapalenie diody po naciśnięciu przycisku, przy użyciu przerwania.

 Funkcja pinMode oraz digitalWrite może się przydać przy sterowaniu silników.
Przerwanie działa tak że kiedy zostanie wykryty odpowiedni stan na odpowiednim pinie
to mikrokontroler przerywa aktulanie wykonany kod i uruchamia funkcję przypisaną do 
do odpowiedniego pinu. Gdy się wykona powraca on do miesjca w głównym kodzie w którym
praca została przerwana.
*/

//opcjonalne na Arduino IDE
#include <Arduino.h>

// wbudowana w pico dioda LED na pinie 25
#define LED 25

// podłącz przycisku do tego pinu, może być dowolny inny pin
#define BUTTON 16 

void zmieni_przycisk()
{
  digitalWrite(LED,!digitalRead(BUTTON));
}


void setup() {
  // put your setup code here, to run once:

  // ustawienie pinu 25 jako wyjście
  pinMode(LED,OUTPUT);

  // ustawienie pinu z przyciskiem na wejście z wenwnętrznym rezystorem podpiętym do zasilania
  pinMode(BUTTON,INPUT_PULLUP);

  // tak też można ale do pinu musisz jeszcze podpiąć rezystor podciągnięty do zasilania
  //pinMode(BUTTON,INPUT);

  //ustawienie LED w stan niski (równoważne z zgaszeniem diody)
  digitalWrite(LED,LOW);

  //funkcja zmieni_przycsik włączy się kiedy zostanie wykryta zmianna stanu na pinie BUTTON.
  attachInterrupt(BUTTON,zmieni_przycisk,CHANGE);

}

void loop() {
// wyszstko wykonuje przerwanie :)
}
