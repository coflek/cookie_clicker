#include "base64.h"
#include <string>
#include <iostream>

const unsigned char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string base64_encode(unsigned char const* bytes, unsigned int len) {
	return "";
}
void base64_decode(std::string const& encoded_string, unsigned char *decoded_bytes) {
	for (auto c : encoded_string) {
		std::cout << c << std::endl;
	}
}


