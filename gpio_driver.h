//
// Created by Milosz on 2025-05-02.
//

#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H
#include <stdint.h>
// Napisz w języku C symulację prostego character device działającego jak sterownik GPIO.
// Urządzenie ma obsługiwać 8-bitowy port, gdzie każdy bit odpowiada jednemu pinowi GPIO.

// Udostępnij dwie funkcje:
// void gpio_write(uint8_t value) – ustawia stan portu GPIO
// uint8_t gpio_read(void) – odczytuje aktualny stan portu

// Dodatkowo:
// Funkcja void gpio_set_pin(uint8_t pin) ustawia pojedynczy pin
// Funkcja void gpio_clear_pin(uint8_t pin) czyści pojedynczy pin
// Funkcja int gpio_get_pin(uint8_t pin) zwraca stan pojedynczego pinu(0/1)
// Zaimplementuj te funkcje jako symulację sprzętu w pamięci (bez użycia rzeczywistego/dev)

// Wymagania:
// Użyj tylko języka C (bez bibliotek zewnętrznych)
// Wartość portu GPIO przechowuj jako statyczną zmienną w pamięci
// Obsłuż błędne piny(np. pin> 7)
// Dodaj prosty main() do demonstracji

void gpio_set_pin(const uint8_t pin);

void gpio_clear_pin(const uint8_t pin);

int gpio_get_pin(const uint8_t pin);

void gpio_write(uint8_t value);

uint8_t gpio_read(void);

void test_gpio(void);

#endif //GPIO_DRIVER_H
