#ifndef _BASE_64_
#define _BASE_64

#include <string>

std::string base64_encode(const char* bytes, unsigned int len);
void base64_decode(std::string const& encoded_string, char* decoded_bytes);

#endif /* _BASE_64_ */