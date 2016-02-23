#include "base64.h"
#include <iostream>
#include <stdint.h>

int main() {
	std::string cookie_save = "Mnx8MTQyMzMzNTYxNzY0MTsxNDIzMzM1NjE3NzA4OzE0NTYyNjgzNDUyMjg7UG93ZXIgVGVhcG90fMOnwr3CoAZ8NTYxNi40MzY2NjY2NjE2ODg7NTY5Mi40MzY2NjY2NjE2Mjk7ODU7MDs4NTszMTswOzA7MDswOzA7MDswOzA7MDswOzA7MDswOzA7MDswOzswOzA7MDswOzA7MDswOy0xOy0xOy0xOy0xOy0xOzA7MDswOzA7NTA7fDQsNCw1NjA3LDA7MCwwLDAsMDswLDAsMCwwOzAsMCwwLDA7MCwwLDAsMDswLDAsMCwwOzAsMCwwLDA7MCwwLDAsMDswLDAsMCwwOzAsMCwwLDA7MCwwLDAsMDswLDAsMCwwOzAsMCwwLDA7MCwwLDAsMDt8w6bCoMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAQHzDp8KAwoDDpMKAwoDDpMKDwoDDpMKAwoDDpMKAwoDDpcKAwoDDpMKAwoDDpMKAwoDDpMKAwoDDpMKAwoDDpMKAwoDDpMKAwoDDpMKAwoDDpMKAwoDDpMKAwoDDpMKAwoDDpMKAwoDDpMKAwoDDoMKgwoA % 3D % 21END % 21";
	
	/* prepare save for decoding  - remove % 21END % 21 from the end, replace " % 3D" with = */
	const std::string SAVE_END = " % 21END % 21";
	const std::string EQUALS = " % 3D";
	uint32_t save_end_index = cookie_save.find(SAVE_END);
	cookie_save = cookie_save.replace(save_end_index, save_end_index + SAVE_END.length(), "");
	uint32_t equals_index = cookie_save.find(EQUALS);
	while (equals_index != std::string::npos) {
		cookie_save = cookie_save.replace(equals_index, equals_index + EQUALS.length(), "=");
		equals_index = cookie_save.find(EQUALS);
	}
	
	std::cout << cookie_save << std::endl;

	char* decoded = new char[cookie_save.length() * 3 / 4 + 1];
	std::fill(decoded, decoded + cookie_save.length() * 3 / 4 + 1, 0);
	base64_decode(cookie_save, decoded);
	std::cout << decoded << std::endl;
	std::cout << std::endl;

	delete[] decoded;
	return 0;
}