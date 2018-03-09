#include "fluint8.hpp"

#include <iostream>

int main() {
	uint32_t failed = 0;

	std::cerr << "Testing 'get_bits':"; std::cerr.flush();
	for (uint32_t a = 0; a < 256; ++a) {
		uint8_t expected = uint8_t(a);
		fluint8 fla = fluint8(a);
		uint8_t result;
		fla.get_bits(&result);
		if (expected != result) {
			std::cerr << "Failed: get_bits(" << a << ") expected " << uint32_t(expected) << " got " << uint32_t(result) << "." << std::endl;
			++failed;
		}
	}
	std::cerr << " done." << std::endl;

	std::cerr << "Testing 'set_bits':"; std::cerr.flush();
	for (uint32_t a = 0; a < 256; ++a) {
		fluint8 expected = fluint8(a);
		fluint8 result = fluint8(0.0f);
		uint8_t a8 = uint8_t(a);
		result.set_bits(&a8);
		if (expected.val != result.val) {
			std::cerr << "Failed: set_bits(" << a << ") expected " << expected.val << " got " << result.val << "." << std::endl;
			++failed;
		}
	}
	std::cerr << " done." << std::endl;


	#define TEST_UNARYOP( OP ) \
		std::cerr << "Testing '" #OP "':"; std::cerr.flush(); \
		for (uint32_t a = 0; a < 256; ++a) { \
			uint8_t expected = OP uint8_t(a); \
			fluint8 result = OP fluint8(a); \
			if (float(expected) != result.val) { \
				std::cerr << "Failed: " #OP << a << " expected " << uint32_t(expected) << " got " << result.val << "." << std::endl; \
				++failed; \
			} \
		} \
		std::cerr << " done." << std::endl;

	TEST_UNARYOP( ~ )
	TEST_UNARYOP( - )


	#define TEST_BINARYOP( OP, BSTART ) \
		std::cerr << "Testing '" #OP "':"; std::cerr.flush(); \
		for (uint32_t a = 0; a < 256; ++a) { \
			for (uint32_t b = BSTART; b < 256; ++b) { \
				uint8_t expected = uint8_t(a) OP uint8_t(b); \
				fluint8 result = fluint8(a) OP fluint8(b); \
				if (float(expected) != result.val) { \
					std::cerr << "Failed: " << a << " " #OP " " << b << " expected " << uint32_t(expected) << " got " << result.val << "." << std::endl; \
					++failed; \
				} \
			} \
		} \
		std::cerr << " done." << std::endl;

	TEST_BINARYOP( &, 0 )
	TEST_BINARYOP( ^, 0 )
	TEST_BINARYOP( |, 0 )

	#define TEST_EQUALOP( OP, BSTART ) \
		std::cerr << "Testing '" #OP "':"; std::cerr.flush(); \
		for (uint32_t a = 0; a < 256; ++a) { \
			for (uint32_t b = BSTART; b < 256; ++b) { \
				uint8_t expected = uint8_t(a); \
				expected OP uint8_t(b); \
				fluint8 result = fluint8(a); \
				result OP fluint8(b); \
				if (float(expected) != result.val) { \
					std::cerr << "Failed: " << a << " " #OP " " << b << " expected " << uint32_t(expected) << " got " << result.val << "." << std::endl; \
					++failed; \
				} \
			} \
		} \
		std::cerr << " done." << std::endl;
	
	TEST_EQUALOP( += , 0)
	TEST_EQUALOP( -= , 0)
	TEST_EQUALOP( *= , 0)
	TEST_EQUALOP( /= , 1)
	TEST_EQUALOP( %= , 1)

	TEST_EQUALOP( &= , 0)
	TEST_EQUALOP( ^= , 0)
	TEST_EQUALOP( |= , 0)

	if (failed > 0) return 1;
	else return 0;
}
