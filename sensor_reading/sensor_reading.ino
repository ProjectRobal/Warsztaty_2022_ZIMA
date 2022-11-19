/*
  Przykładowy program do odczytu odległośći z czujników TOF VL53L0X.
  Czujniki te posiadają te sam adres ( adres to 0x52 ) co za tym idzie muszą one być podpiętę do 
  dwóch osobnych interfejsów I2C.
  Czujnik pozwala na pomiar do 2 m.
  Chyba że użyje się funkcji setAddress(uint8_t new_addr), wcześniej jednak należy 
  pin XSHUT jednego z podłączonych czujników ustawić w stan niski.
  Powoduje to wyłączenie jednego z dwóch sensorów a co za tym idzie 
  ustawienie nowego adresu dla aktywnego czujnika. 

  Note:
  Jeżeli czujnik zwraca 65535, sprawdź połączenia i zresetuj pico
  Jeżeli czujnik zwraca 8190 , to znaczy że dystans wyszedł poza zakres
  Poszczególne interfejsy i2c można przypisać tylko do konkretnych pinów, patrz rozkład pinów raspberry pi pico.


  Użyta biblioteka:
  https://github.com/pololu/vl53l0x-arduino
*/

//opcjonalne na Arduino IDE
#include <Arduino.h>

//biblioteka od I2C
#include <Wire.h>
//biblioteka od czujnika
#include <VL53L0X.h>


// pomocnicze makra dla pinów I2C
#define I2C0_SDA 0
#define I2C0_SCL 1

#define I2C1_SDA 2
#define I2C1_SCL 3


//lewy czujnik 
VL53L0X left;

//prawy czujnik
VL53L0X right;

void setup() {

  //inicjacja wyjścia szeregowego, (logowanie danych w terminalu)
  Serial.begin();
  
  //ustawienie pinów dla pierwszego interfejsu i2c
  Wire.setSDA(I2C0_SDA);
  Wire.setSCL(I2C0_SCL);

  //ustawienie pinów dla durgiego interfejsu i2c
  Wire1.setSDA(I2C1_SDA);
  Wire1.setSCL(I2C1_SCL);

  //inicjalizacja interfejsów i2c
  Wire.begin();
  Wire1.begin();

  //ustawienie interfejsów dla czujników
  left.setBus(&Wire);
  right.setBus(&Wire1);

  //ustaw timeout dla czujników na 500 ms, kiedy pomiar trwa dłużej niż 500 ms , funkcja timeoutOccured() zwróci true w przeciwnym wypadku false
  left.setTimeout(500);
  right.setTimeout(500);

  //Czekaj na inicjalizację czujnika
  while(!left.init(false))
  {
    Serial.println("Cannot init left sensor");
    delay(1000);
  }

  //Czekaj na inicjalizację czujnika
  while(!right.init(false))
  {
    Serial.println("Cannot init right sensor");
    delay(1000);
  }

  //Czujnik może działać w dwóch trybach, w ciągłym lub pojedynczy pomiar.
  // w trybie ciągłym czujnik dokonuje pomiaru cały czas
  // w trybie pojedynczy pomiar , pomiar jest dokonowany w momencie żądania użytkownika

  // lewy czujnik działa w trybie ciągłym
  left.startContinuous();

  //prawy będzie działać w trybie pojedynczych pomiarów

  // dodatkowe parametry czujnika (dla ludzi którzy chcą się trochę pobawić)
  /*

  // ustawienie limitu prędkości sygnału, im mniejsza wartość tym potencjalnie większy zasięg czujnika , ale może zmniejszyć jego dokładaność, standardowa wartość to 0.25
  right.setSignalRateLimit(0.1);

  // ustawienie okresu impulsu laser (normalnie 14 i 10 PCLKs), funkcje przyjmują wartość parzyste, im większe wartość tym większy zasięg
  // od 12 do 18
  right.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  // od 8 do 14
  right.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);

  // ustawienie czasu pomiarowego ( w us ), większa wartość pozwala na dokładniejsze wyniki, wartość minimalna to 20000 us, standardowo 33000 us
  right.setMeasurementTimingBudget(20000);

  */

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("Left: ");
  Serial.print(left.readRangeContinuousMillimeters());
  Serial.println(" mm");

  
  uint16_t distance=right.readRangeSingleMillimeters();

  // dystans mniejszy lub równy 50 mm
  if(distance<=50)
  {
    Serial.println("Odsuni się zasłaniasz mi widok!!");
  }

  //Czekaj 500 ms
  delay(500);

}