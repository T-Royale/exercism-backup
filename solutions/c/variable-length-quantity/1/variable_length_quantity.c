#include "variable_length_quantity.h"

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output) {
	size_t output_index = 0;
	for(size_t i = 0; i < integers_len; i++){
		uint32_t value = integers[i];
		uint8_t temp[5] = {0};		// máximo 5 bytes para uint32_t
		int count = 0;

		do {
			temp[count++] = value & 0x7F;
			value >>= 7;
		} while(value > 0);

		for(int j = count - 1; j >= 0; j--){
			uint8_t byte = temp[j];
			if(j != 0) byte |= 0x80;
			output[output_index++] = byte;
		}
	}
	return output_index;
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output) {
	uint32_t value = 0;
	size_t output_index = 0;
	int bytes_seen = 0;
	for(size_t i = 0; i < buffer_len; i++){
		uint8_t byte = bytes[i];
		value = (value << 7) | (byte & 0x7F);
		bytes_seen++;

		if((byte & 0x80) == 0){
			output[output_index++] = value;
			bytes_seen = 0;
			value = 0;
		} else if (bytes_seen > 5) return -1;
	}
	if(bytes_seen != 0){
		return -1;
	}
	return output_index;
}
