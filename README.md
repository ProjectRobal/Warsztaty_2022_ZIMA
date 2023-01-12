# Przykładowe kody dla warsztatów 2022

## Opis pinów dla RPI PICO

![alt text](./pico_pins.webp)

- GPx - pin gpio (wyjście/wejście)
- GND - uziemienie
- SPIx - piny x interfejsu SPI
- I2Cx - piny x interfejsu I2C
- UARTx - piny x interfejsu UART
- VBUS - zasilanie z portu USB +5V
- VSYS - wejście zasilania od 1.8V do 5.5V
- 3V3 - zasilanie 3.3V
- 3V3_EN - podpięcie do uziemienia powoduje wyłączenie zasilania 3.3V i samego mikrokontrolera
- RUN - zwarcie pinu do uziemienia powoduje wyłączenie mikrokontrolera, może być użyte do resetowania mikrokontrolera

Piny GPIO26-29 mogę być użyte jako wejścia analogowe z rozdzielczością 12bit

## Instalacja dla Arduino IDE

0. Pobierz Arduino IDE ze strony https://www.arduino.cc/en/software
1. Uruchom Arduino IDE i wejdź w Plik -> Preferencje.
2. W Dodatkowe adresy URL do menadżera płytek wklej https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
3. Naciśnij OK
4. Wejdź w Narzędzia->Płytka->Menedżer Płytek 
5. W polu wyszukiwania wpisz "pico"
6. Znajdź "Raspberry Pi Pico/RP2040" i wybierz "dodaj"
7. SDK do biblioteki powinno się zainstalować
8. Have fun

## Instalacja biblioteki do czujników

1. W Arduino IDE wchodzimy do Narzędzia->Płytka->Zarządzaj bibliotekami
2. Wpisujemy w wyszukiwarce pololu vl53L0X
3. Wybieramy VL53L0X przez Polou i klikamy zainstaluje
4. Po chwili biblioteka powinna już być zainstalowana

## Wgrywanie programu do RPI Pico

1. Przy pierwszym wgrywaniu należy odłączyć Raspberry Pi Pico od zasilania
2. Przytrzymaj przycisk BOOTSEL podłączając Pico do zasilania
3. Windows powinien wykryć nowy dysk
4. W Arduino IDE w Narzędzia -> Port wybieramy UF2 (czyli jedyny port inny od COM-a)
5. Naciskamy Wgraj/Upload
6. O ile was program działa poprawnie, od tej pory wystarczy wybrać port COM i nacisnąć Wgraj/Upload przy wgrywaniu.

## Przykłady

### HELLO WORLD

Program typu hello world

### ZMIENNE

Program który przestawia podstawowe zmienne, oraz funkcję switch

### LED_BLINK

Proste miganie wbudowaną diodą.

### LED_PWM

Sterowanie jasnością wbudowanej diody.

### BUTTON_PRESS

Uruchamianie diody przy pomocy przycisku.

### BUTTON_INTERUPT

Uruchamianie diody przy pomocy przycisku za pomocą przerwania.

### SENSOR_READING

Test czyjników odległości TOF VL53L0X.

### CHANGE_ADDRESS

Zmianna adresu czujnika odległości TOF VL53L0X, przydatne dla ludzi z większą ilością czujników

### ANALOG_READ

Odczyt danych analogowych 

### ROUND_ROBIN_DYNAMIC

Sekwecyjny odczyt z wejść analogowych oraz przykład zastosowania pamięc dynamicznej.

### ROUND_ROBIN

Sekwecyjny odczyt z wejść analogowych przy pomocy statycznej tablicy.

Źródło:
[RPI Pico pinout](https://peppe8o.com/raspberry-pi-pico-pinout/)



