#ifndef _BASE_64_H_
#define _BASE_64_H_

#include <string>

namespace Base64
{
	std::string encode(const char* bytes, unsigned int len);
	void decode(std::string const& encoded_string, char* decoded_bytes);
}

#endif /* _BASE_64_H_ */