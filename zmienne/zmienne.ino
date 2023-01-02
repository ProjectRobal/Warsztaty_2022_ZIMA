//zawiera maksymalne wartości zmiennych
#include <climits>

void setup() {
  // put your setup code here, to run once:

  // ważne!!
  Serial.begin();

}

// 1
void zmienne_liczbowe()
{
  Serial.println("Zmienne liczbowe: ");
  Serial.print("byte rozmiar: ");
  Serial.println(sizeof(byte));
  Serial.print("Maksymalna wartość: ");
  Serial.println(SCHAR_MAX);
  Serial.print("Minimalna wartość: ");
  Serial.println(SCHAR_MIN);

  Serial.print("short rozmiar: ");
  Serial.println(sizeof(short));
  Serial.print("Maksymalna wartość: ");
  Serial.println(SHRT_MAX);
  Serial.print("Minimalna wartość: ");
  Serial.println(SHRT_MIN);

  Serial.print("int rozmiar: ");
  Serial.println(sizeof(int));
  Serial.print("Maksymalna wartość: ");
  Serial.println(INT_MAX);
  Serial.print("Minimalna wartość: ");
  Serial.println(INT_MIN);

  Serial.print("long rozmiar: ");
  Serial.println(sizeof(long));
  Serial.print("Maksymalna wartość: ");
  Serial.println(LONG_MAX);
  Serial.print("Minimalna wartość: ");
  Serial.println(LONG_MIN);

  Serial.print("long long rozmiar: ");
  Serial.println(sizeof(long long));
  Serial.print("Maksymalna wartość: ");
  Serial.println(LLONG_MAX);
  Serial.print("Minimalna wartość: ");
  Serial.println(LLONG_MIN);

  
}

// 2
void alt_zmienne_liczbowe()
{
  Serial.println("Zmienne liczbowe: ");
  Serial.print("int8_t rozmiar: ");
  Serial.println(sizeof(int8_t));
  Serial.print("Maksymalna wartość: ");
  Serial.println(INT8_MAX);
  Serial.print("Minimalna wartość: ");
  Serial.println(INT8_MIN);

  Serial.print("int16_t rozmiar: ");
  Serial.println(sizeof(int16_t));
  Serial.print("Maksymalna wartość: ");
  Serial.println(INT16_MAX);
  Serial.print("Minimalna wartość: ");
  Serial.println(INT16_MIN);

  Serial.print("int32_t rozmiar: ");
  Serial.println(sizeof(int32_t));
  Serial.print("Maksymalna wartość: ");
  Serial.println(INT32_MAX);
  Serial.print("Minimalna wartość: ");
  Serial.println(INT32_MIN);

  Serial.print("int64_t rozmiar: ");
  Serial.println(sizeof(int64_t));
  Serial.print("Maksymalna wartość: ");
  Serial.println(INT64_MAX);
  Serial.print("Minimalna wartość: ");
  Serial.println(INT64_MIN);

}

// 3
void zmienne_tekstowe()
{
  // tego lepiej nie używać
    String text="Hello world!";
    Serial.println(text);
  // to jest lepsze
    const char c_text[]="Hello world!";
    Serial.println(c_text);


  // kopiowanie łańcucha znaków
  // więcje przydatnych funkcji:
  // https://cplusplus.com/reference/cstring/
    char copy[32];

    strcpy(copy,c_text);

    Serial.println(copy);

  // kopiowanie łańcucha znaków
    char *dyn_copy=new char[32];

    strcpy(dyn_copy,c_text);

    Serial.println(dyn_copy);

  // nie zapominajmy
    delete [] dyn_copy;
}

bool sprawdzenie(int x) 
{
  return x<10;
}

// 4
void zmienna_logiczna()
{
  bool warunek=sprawdzenie(4);

  Serial.println(warunek);
}

// h
void help()
{
  Serial.print("Wpisz liczbę: ");

  for(uint8_t i=1;i<=4;++i)
  {
  Serial.println(i);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  // Jeżeli nie ma nic do odczytania, przerwij wykonywanie funkcji.
  if(!Serial.available())
  {
    return;
  }

  // odczyt jednego bajtu
  switch(Serial.read())
  {
    case '1':

    zmienne_liczbowe();

    break;

    case '2':

    alt_zmienne_liczbowe();

    break;

    case '3':

    zmienne_tekstowe();

    break;

    case '4':

    zmienna_logiczna();

    break;

    case 'h':

    help();

    break;

    default:
    Serial.println("Nie ma takiej opcji!");
  }

  
}
