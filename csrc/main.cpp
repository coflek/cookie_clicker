#include "base64.h"
#include <iostream>

int main() {
	std::string decoded = "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlz"
		"IHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2Yg"
		"dGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGlu"
		"dWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRo"
		"ZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=";

	/*
	Mnx8MTQyMzMzNTYxNzY0MTsxNDIzMzM1NjE3NzA4OzE0NTYyNTYzNDg1MDA7UG93ZXIgVGVhcG90fMOnwr3CoAZ8ODE2Ljc0MzMzMzMzMjcxODI7ODkyLjc0MzMzMzMzMjY1OTY7ODQ7MDs4NDs1OzA7MDswOzA7MDswOzA7MDswOzA7MDswOzA7MDswOzA7OzA7MDswOzA7MDswOzA7LTE7LTE7LTE7LTE7LTE7MDswOzA7MDs1MDt8NCw0LDgwOCwwOzAsMCwwLDA7MCwwLDAsMDswLDAsMCwwOzAsMCwwLDA7MCwwLDAsMDswLDAsMCwwOzAsMCwwLDA7MCwwLDAsMDswLDAsMCwwOzAsMCwwLDA7MCwwLDAsMDswLDAsMCwwOzAsMCwwLDA7fMOmwqDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgMOkwoDCgEB8w6bCgMKAw6TCgMKAw6TCg8KAw6TCgMKAw6TCgMKAw6XCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6TCgMKAw6DCoMKA%21END%21
	*/

	base64_decode(decoded, NULL);
	return 0;
}