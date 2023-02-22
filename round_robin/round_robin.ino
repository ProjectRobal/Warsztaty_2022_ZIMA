/*
  Przykład sekwecyjnego odczytu danych z pinów analogowych.
Przy pomocy statycznej tablicy.
*/

#include <Arduino.h>

#define BUFFER_SIZE 1024

// piny analogowe
const uint8_t analog_pins[]={28,27,26};

uint16_t buffer[BUFFER_SIZE];


uint32_t srednia(uint16_t tab[])
{
  uint32_t out=0;

  for(uint16_t i=0;i<BUFFER_SIZE;++i)
  {
    out+=tab[i];
  }

  out/=BUFFER_SIZE;

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

  uint8_t d=0;

  for(uint16_t i=0;i<BUFFER_SIZE;++i)
  {

    buffer[i]=analogRead(analog_pins[d]);

    ++d;

    // pinów analogowych mamy tylko trzy
    if(d==3)
    {
      d=0;
    }
  }

  Serial.print("Średnia: ");
  Serial.println(srednia(buffer));


  //czekaj 100 ms
  delay(100);
}
