//
// Created by Milosz on 2025-05-04.
//

#ifndef REVERSE_BITS_UINT32_H
#define REVERSE_BITS_UINT32_H
#include <stdint.h>
#include <math.h>

// Reverse bits of a given 32 bits unsigned integer.

inline uint8_t getNthBit(uint32_t number, uint8_t bit_index) {
    if (bit_index > 31) return 0; // ERROR
    return (number >> bit_index) & 1;
}

inline void setNthBit(uint32_t* number, uint8_t bit_index, uint8_t bit_value) {
    if (bit_index > 31 || bit_value > 1) return; // ERROR
    if (bit_value == 1){
        const uint32_t temp_number = pow(2, bit_index); // Tworzymy maskę z jedna 1 np 0b000010000...
        *number |= temp_number;  // a później ustawiamy na 1
    }
    else if (bit_value == 0){
        const uint32_t temp_number = UINT32_MAX - pow(2, bit_index); // Tworzymy maskę z jednym 0 np 0b111011...
        *number &= temp_number;  // a później ustawiamy na 0
    }
}

inline uint32_t reverseBits(uint32_t n) {
    for (int i = 0; i< 16; i++) {
        const uint8_t temp = getNthBit(n, i); // kopia pierwszego
        setNthBit(&n, i, getNthBit(n, 31-i) ); // pierwszy zastępujemy ostatnim
        setNthBit(&n, 31-i, temp ); // a ostatni pierwszym
    }
    return n;
}

#endif //REVERSE_BITS_UINT32_H
