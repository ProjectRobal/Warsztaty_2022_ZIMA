/*
  Przykład sekwecyjnego odczytu danych z pinów analogowych.
A także przykład użycia pamięci dynamicznej.
Na mikrokontrolerach , w szczególność pokroju Arduino Uno , staramy się minimalizować użycie dynamicznej alokacji.
*/

#include <Arduino.h>

#define MAX_SIZE 1024

// piny analogowe
const uint8_t analog_pins[]={28,27,26};


volatile uint16_t rozmiar=2;




uint32_t srednia(uint16_t *tab)
{
  uint32_t out=0;

  for(uint16_t i=0;i<rozmiar;++i)
  {
    out+=tab[i];
  }

  out/=rozmiar;

  return out;

}


void setup() {
  // put your setup code here, to run once:
  Serial.begin();

  // używam const uint8_t& bo tak jest szybciej
  // iteruje po wszystkich elementach tablicy analog_pins
  for(const uint8_t& a : analog_pins)
  {
    pinMode(a,INPUT);
  }

  analogReadResolution(12);

}

void loop() {
  // put your main code here, to run repeatedly:

  // wskaźnik 
  uint16_t *odczyty;

  // alokacja tablicy dynamicznej
  odczyty= new uint16_t[rozmiar];

  uint8_t d=0;

  for(uint16_t i=0;i<rozmiar;++i)
  {

    odczyty[i]=analogRead(analog_pins[d]);

    ++d;

    // pinów analogowych mamy tylko trzy
    if(d==3)
    {
      d=0;
    }
  }

  Serial.print("Średnia: ");
  Serial.print(srednia(odczyty));
  Serial.print(" rozmiar buffora: ");
  Serial.println(rozmiar);

  // należy zwolnić pamięć
  delete [] odczyty;

  // zwiększamy rozmiar buffora
  rozmiar+=2;

  // wróć do pierwotenj wartość po przekroczeniu max size
  if(rozmiar>MAX_SIZE)
  {
    rozmiar=2;
  }

  //czekaj 100 ms
  delay(100);
}
