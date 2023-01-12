/*
 Przykład przedstawiający miganie wbudowaną diodą.

 Funkcja pinMode oraz digitalWrite może się przydać przy sterowaniu silników.
*/

//opcjonalne na Arduino IDE
#include <Arduino.h>

// wbudowana w pico dioda LED na pinie 25
#define LED 25

void setup() {
  // put your setup code here, to run once:

  // ustawienie pinu LED jako wyjście
  pinMode(LED,INPUT);

  //ustawienie pinu LED w stan wysoki (równoważne z zapaleniem diody)
  digitalWrite(LED,HIGH);

  //ustawienie pinu LED w stan niski (równoważne z zgaszeniem diody)
  //digitalWrite(LED,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  //gasi i zapalaj diodę co 500ms

  //odczytaj stan na pinie LED
  if(digitalRead(LED)==HIGH)
  {
    digitalWrite(LED,LOW);
  }
  else
  {
    digitalWrite(LED,HIGH);
  }

  //Alternatywnie:
  //digitalWrite(LED,!digitalRead(LED));

  //czekaj 500 ms
  delay(500);
}
