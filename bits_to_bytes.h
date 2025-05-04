//
// Created by Milosz on 2025-05-03.
//

#ifndef BITS_TO_BYTES_H
#define BITS_TO_BYTES_H
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void pack_bits_to_bytes(const uint8_t* bits, int bit_count, uint8_t* out_bytes, int* out_byte_count);
void test_pack_bits_to_bytes();


#endif //BITS_TO_BYTES_H
