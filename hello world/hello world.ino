/*
  Program wyświetla co 500 milisekund 
napis Hello world wraz z liczbą iteracji 
pętli.
*/

void setup() {
  // put your setup code here, to run once:

  Serial.begin();

}

int counter=0;

void loop() {
  // put your main code here, to run repeatedly:

  //zwiększ wartość licznika
  ++counter;

  //wypisuje tekst
  Serial.print("Kocham PWR: ");
  //wypisuje tekst zaczynając nową linię
  Serial.println(counter);
  //czekaj 500 ms
  delay(500);
   
}
