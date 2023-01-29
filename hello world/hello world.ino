/*
  Program wyświetla co 500 milisekund 
napis wraz z liczbą iteracji 
pętli.
*/

int counter=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin();

}


void loop() {
  // put your main code here, to run repeatedly:
  //zwiększ wartość licznika
  ++counter;
  
  //wypisuje tekst
  Serial.print("Zbysiu daj mi: ");
  //wypisuje tekst zaczynając nową linię
  Serial.println(counter);
  //czekaj 500 ms
  delay(500);
   
}
