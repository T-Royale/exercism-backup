#include "intergalactic_transmission.h"
#include <stdint.h>

static int get_bit(const uint8_t *data, int bit_index) {
    return (data[bit_index / 8] >> (7 - (bit_index % 8))) & 1;
}

int transmit_sequence(uint8_t *buffer, const uint8_t *message, int message_length) {
    int input_bits = message_length * 8;
    int output_len = (input_bits + 6) / 7;
    for (int i = 0; i < output_len; i++) {
        int data = 0;
        int ones = 0;
        for (int j = 0; j < 7; j++) {
            int bit_index = i * 7 + j;
            int bit = 0;
            if (bit_index < input_bits) {
                bit = get_bit(message, bit_index);
            }
            data = (uint8_t)((data << 1) | bit);
            ones += bit;
        }
        int parity = ones & 1;
        buffer[i] = (uint8_t)((data << 1) | parity);
    }
    return output_len;
}

static int count_ones(uint8_t value) {
    int count = 0;

    while (value) {
        count += value & 1;
        value >>= 1;
    }

    return count;
}

static void set_bit(uint8_t *data, int bit_index, int bit) {
    if (bit) {
        data[bit_index / 8] |= (uint8_t)(1u << (7 - (bit_index % 8)));
    }
}

int decode_message(uint8_t *buffer, const uint8_t *message, int message_length) {
    int output_length = (message_length * 7 / 8);

    for (int i = 0; i < message_length; i++)
        buffer[i] = 0;
    for (int i = 0; i < message_length; i++)
        if (count_ones(message[i]) & 1) return -1;

    int output_bit = 0;
    int total_output_bits = output_length * 8;

    for (int i = 0; i < message_length; i++) {
        uint8_t data = message[i] >> 1; // Quitar bit de paridad
        for (int j = 0; j < 7; j++) {
            if (output_bit > total_output_bits) {
                break;
            }
            int bit = (data >> (6 - j)) & 1;
            set_bit(buffer, output_bit, bit);
            output_bit++;
        }
    }

    return output_length;
}
