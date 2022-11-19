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

1. Uruchom Arduino IDE i wejdź w Plik -> Preferencje.
2. W Dodatkowe adresy URL do menadżera płytek wklej https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
3. Naciśnij OK
4. W Narzędzia->Płytka->Menedżer Płytek 
5. W polu wyszukiwania wpisz "pico"
6. Znajdź "Raspberry Pi Pico/RP2040" i wybierz "dodaj"
7. SDK do biblioteki powinno się zainstalować
8. Have fun

## Przykłady

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

Źródło:
[RPI Pico pinout](https://peppe8o.com/raspberry-pi-pico-pinout/)



