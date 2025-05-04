#include "gpio_driver.h"
#include <stdio.h>

static uint8_t GPIO = 0b00000000;
// piny 7-6-5-4-3-2-1-0 (numery)
//      0 0 0 0 0 0 0 0

inline void gpio_set_pin(const uint8_t pin) {
    if (pin > 7) return;
    GPIO |= 0b00000001 << pin;
}

inline void gpio_clear_pin(const uint8_t pin) {
    if (pin > 7) return;
    uint8_t gpio_to_clear = 0b00000001 << pin;
    gpio_to_clear = ~gpio_to_clear; // np 0b11111110
    GPIO &= gpio_to_clear;
}

inline int gpio_get_pin(const uint8_t pin) {
    if (pin > 7) return 0;
    uint8_t gpio_to_read = GPIO >> pin;
    return gpio_to_read & 0b00000001;
}

void gpio_write(uint8_t value) {
    GPIO = value;
}

uint8_t gpio_read(void) {
    return GPIO;
}


inline void test_gpio(void) {
    int failed = 0;

    printf("== GPIO TEST START ==\n");

    // Test 1
    gpio_write(0b10101010);
    if (gpio_read() != 0b10101010) {
        printf("Test 1 FAILED\n");
        failed++;
    } else {
        printf("Test 1 passed\n");
    }

    // Test 2
    gpio_set_pin(0);  // powinno być 0b10101011
    if (gpio_read() != 0b10101011 || gpio_get_pin(0) != 1) {
        printf("Test 2 FAILED\n");
        failed++;
    } else {
        printf("Test 2 passed\n");
    }

    // Test 3
    gpio_clear_pin(1); // powinno być 0b10101001
    if (gpio_read() != 0b10101001 || gpio_get_pin(1) != 0) {
        printf("Test 3 FAILED\n");
        failed++;
    } else {
        printf("Test 3 passed\n");
    }

    // Test 4
    if (gpio_get_pin(3) != 1 || gpio_get_pin(2) != 0 || gpio_get_pin(4) != 0) {
        printf("Test 4 FAILED\n");
        failed++;
    } else {
        printf("Test 4 passed\n");
    }

    // Test 5
    gpio_write(0xFF);
    int ok = 1;
    for (int i = 0; i < 8; ++i) {
        if (gpio_get_pin(i) != 1) {
            ok = 0;
            break;
        }
    }
    if (!ok || gpio_read() != 0xFF) {
        printf("Test 5 FAILED\n");
        failed++;
    } else {
        printf("Test 5 passed\n");
    }

    // Test 6
    gpio_write(0x00);
    gpio_set_pin(3);
    gpio_set_pin(6);
    if (gpio_read() != ((1 << 3) | (1 << 6))) {
        printf("Test 6 FAILED (set)\n");
        failed++;
    } else {
        gpio_clear_pin(3);
        if (gpio_read() != (1 << 6)) {
            printf("Test 6 FAILED (clear)\n");
            failed++;
        } else {
            printf("Test 6 passed\n");
        }
    }

    if (failed == 0) {
        printf("== ALL TESTS PASSED ==\n");
    } else {
        printf("== %d TEST(S) FAILED ==\n", failed);
    }
}
