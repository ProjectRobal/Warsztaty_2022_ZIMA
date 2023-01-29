/*
 Przykład przedstawiający zmianę jasność diody przy pomocy PWM (modulacji zmiany długości impulsu).
Gdy sygnał ma amplitudę 3.3V a wypełnienie wynosi 50% to teoretycznie docelowy odbiornik powinien zachowywać się jakby na
wejście otrzymał napięcie 1.65V. Sprawdza się to przy sterowaniu jasnością LED, jednak bez użycia filtru dolnoprzepustowego 
nie zalecałbym zasilać tym sygnałem mikrokontrolera :)
Rozdzielczość kanału PWM na pico to 16bit.
Co za tym idzie wypełnie sygnału obliczamy z:

 D=100% * (u/65535)

u - wartość będąca argumentem funkcji analogWrite

Każdy pin pico może być wyjściem dla PWM, aczkolwiek maksymalnie może być ich tylko 16.
Pico posiada 8 generatorów PWM każdy po dwa kanały , każdy generator wraz z kanałami jest przypisany do
konkretnych par pinów. Dodaje tabele z rozpiską pinów formie obrazka pin_pwm.jpg .

Funkcja analogWrite może się przydać przy sterowaniu silników.

*/

// wbudowana w pico dioda LED na pinie 25
#define LED 25


unsigned short pwm=0;

void setup() {
  // put your setup code here, to run once:

  // ustawienie pinu LED jako wyjście
  pinMode(LED,OUTPUT);

  //ustawienie częstotliwości PWM ( 50 Hz )
  analogWriteFreq(50);

  //ustawienie rozdzielczości na 16bit
  analogWriteResolution(16);

  //wypełnienie sygnału na 0%
  analogWrite(LED,0);

  //Czekaj 3000 ms 
  delay(3000);

}

void loop() {
  // put your main code here, to run repeatedly:

  // cykliczna zmianna jasność świecenia diodą 

  //Jeżeli osiągnie 100 wróci z powrotem do zera
  if(pwm==100)
  {
    pwm=0;
  }

  // Zmień wartość wypełnienia 
  analogWrite(LED,pwm*100);
  //Zwiększ o jeden ( szybsze od pwm++ )
  ++pwm;
  //czekaj 2500 ms
  delay(2500);
}
