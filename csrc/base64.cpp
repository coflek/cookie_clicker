#include "base64.h"
#include <string>
#include <iostream>
#include <stdint.h>

const unsigned char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

inline uint8_t get_base64_index(unsigned char c) {
	if (c >= 'A' && c <= 'Z') {
		return c - 'A';
	}
	else if (c >= 'a' && c <= 'z') {
		return c - 'a' + 26;
	}
	else if (c >= '0' && c <= '9') {
		return c - '0' + 52;
	}
	else if (c == '+') {
		return 62;
	}
	else if (c == '/') {
		return 63;
	}
	return '=';
}

std::string base64_encode(const char* bytes, unsigned int len) {
	uint32_t encoded_len = len * 4 / 3 + 4; // additional space for padding and '\0'
	char *encoded = new char[encoded_len];
	std::fill(encoded, encoded + encoded_len, 0);
	uint32_t j = 0;
	bool break_loop = false;
	for (uint32_t i = 0; i < len && !break_loop; i += 3) {
		uint32_t bits = 0;
		bits |= bytes[i] << 16;
		if (i + 1 < len) {
			bits |= bytes[i + 1] << 8;
		}
		if (i + 2 < len) {
			bits |= bytes[i + 2];
		}
		encoded[j] = base64_chars[(bits >> 18) & 0x3f];
		encoded[j + 1] = base64_chars[(bits >> 12) & 0x3f];
		if (i + 1 > len || bytes[i + 1] == 0) {
			encoded[j + 2] = '=';
			encoded[j + 3] = '=';
			break_loop = true;
		}
		else if (i + 2 > len || bytes[i + 2] == 0) {
			encoded[j + 2] = base64_chars[(bits >> 6) & 0x3f];
			encoded[j + 3] = '=';
			break_loop = true;
		}
		else {
			encoded[j + 2] = base64_chars[(bits >> 6) & 0x3f];
			encoded[j + 3] = base64_chars[bits & 0x3f];
		}
		j += 4;
	}
	return std::string((const char*)encoded);
}
void base64_decode(std::string const& encoded_string, char* decoded_bytes) {
	uint32_t j = 0;
	for (uint32_t i = 0; i < encoded_string.length(); i += 4) {
		uint32_t bits = 0;
		bits |= get_base64_index(encoded_string[i]) << 18;
		bits |= get_base64_index(encoded_string[i + 1]) << 12;
		bits |= get_base64_index(encoded_string[i + 2]) << 6;
		bits |= get_base64_index(encoded_string[i + 3]);
		decoded_bytes[j] = (bits >> 16) & 0xff;
		decoded_bytes[j + 1] = (bits >> 8) & 0xff;
		decoded_bytes[j + 2] = bits & 0xff;
		if (encoded_string[i + 3] == '=') {
			decoded_bytes[j + 2] = '\0';
		}
		if (encoded_string[i + 2] == '=') {
			decoded_bytes[j + 1] = '\0';
		}
		j += 3;
	}
}


