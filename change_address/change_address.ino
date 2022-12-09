/*
  Przykładowy program do odczytu odległośći z czujników TOF VL53L0X.
  Czujniki te posiadają te sam adres ( adres to 0x52 ) co za tym idzie muszą one być podpiętę do 
  dwóch osobnych interfejsów I2C.
  Chyba że użyje się funkcji setAddress(uint8_t new_addr), wcześniej jednak należy 
  pin XSHUT jednego z podłączonych czujników ustawić w stan niski.
  Powoduje to wyłączenie jednego z dwóch sensorów a co za tym idzie możliwość
  ustawienie nowego adresu dla aktywnego czujnika. 

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

// pin xshut
#define XSHUT 16


//lewy czujnik 
VL53L0X left;

//prawy czujnik
VL53L0X right;


void setup() {

  // pin xshut w trybie wyjścia
  pinMode(XSHUT,OUTPUT);

  // ustawienie czujnika w trybie czuwania
  digitalWrite(XSHUT,LOW);

  //inicjacja wyjścia szeregowego, (logowanie danych w terminalu)
  Serial.begin();
  
  //ustawienie pinów dla pierwszego interfejsu i2c
  Wire.setSDA(I2C0_SDA);
  Wire.setSCL(I2C0_SCL);

  //inicjalizacja interfeju i2c
  Wire.begin();

  //ustawienie interfejsów dla czujników, oba czujnik podłączone do wspólnego interfejsu
  left.setBus(&Wire);
  right.setBus(&Wire);

  // zmieni adres prawego czujnika
  right.setAddress(0x53);

  // ustaw czujnika w stan aktywny
  digitalWrite(XSHUT,HIGH);

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