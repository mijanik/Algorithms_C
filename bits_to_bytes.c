//
// Created by Milosz on 2025-05-03.
//
#include "bits_to_bytes.h"

void print_bytes_array(const uint8_t* bytes, int byte_count) {
    printf("{");
    for (int i = 0; i < byte_count; i++) {
        for (int j = 7; j>=0; j--) {
            uint8_t bit = bytes[i] >> j;
            bit &= 0b00000001;
            printf("%d", bit);
        }
        printf(", ");
    }
    printf("}\n");
}

void pack_bits_to_bytes(const uint8_t* bits, int bit_count, uint8_t* out_bytes, int* out_byte_count) {
    *out_byte_count = bit_count/8;
    if (bit_count % 8 > 0) {
        (*out_byte_count)++;
    }
    printf("out_byte_count: %d\n", *out_byte_count);
    for (int i = 0; i < *out_byte_count; i++) {
        for (int j = 0; j < 8; j++) {
            if (i*8+j<bit_count)
                out_bytes[i] |= bits[i*8+j] << 7-j;
        }
    }
    print_bytes_array(out_bytes, *out_byte_count);
}



void test_pack_bits_to_bytes() {
    int failed = 0;

    {
        // Test 1: dokładnie 8 bitów → 1 bajt
        uint8_t bits[] = {1,0,1,0,1,0,1,0};
        uint8_t expected[] = {0b10101010};
        uint8_t output[10] = {0};
        int out_size = 0;

        pack_bits_to_bytes(bits, 8, output, &out_size);
        if (out_size != 1 || memcmp(output, expected, 1) != 0) {
            printf("Test 1 FAILED\n");
            failed++;
        } else {
            printf("Test 1 passed\n");
        }
    }

    {
        // Test 2: 16 bitów → 2 bajty
        uint8_t bits[] = {1,1,1,1, 0,0,0,0,  0,0,1,1, 1,1,0,0};
        uint8_t expected[] = {0b11110000, 0b00111100};
        uint8_t output[10] = {0};
        int out_size = 0;

        pack_bits_to_bytes(bits, 16, output, &out_size);
        if (out_size != 2 || memcmp(output, expected, 2) != 0) {
            printf("Test 2 FAILED\n");
            failed++;
        } else {
            printf("Test 2 passed\n");
        }
    }

    {
        // Test 3: mniej niż 8 bitów → dopełnienie zerami
        uint8_t bits[] = {1,0,1}; // powinno dać: 10100000 = 0xA0
        uint8_t expected[] = {0b10100000};
        uint8_t output[10] = {0};
        int out_size = 0;

        pack_bits_to_bytes(bits, 3, output, &out_size);
        if (out_size != 1 || memcmp(output, expected, 1) != 0) {
            printf("Test 3 FAILED\n");
            failed++;
        } else {
            printf("Test 3 passed\n");
        }
    }

    {
        // Test 4: 0 bitów
        uint8_t bits[] = {};
        uint8_t expected[] = {};
        uint8_t output[10] = {0xFF}; // ustal coś niezerowego
        int out_size = -1;

        pack_bits_to_bytes(bits, 0, output, &out_size);
        if (out_size != 0) {
            printf("Test 4 FAILED\n");
            failed++;
        } else {
            printf("Test 4 passed\n");
        }
    }

    if (failed == 0) {
        printf("== ALL TESTS PASSED ==\n");
    } else {
        printf("== %d TEST(S) FAILED ==\n", failed);
    }
}