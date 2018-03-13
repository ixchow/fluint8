#include <iostream>
#include <cmath>

int main(int argc, char **argv) {
	std::cout << "\"a\", \"milt8\", \"milt7\", \"milt6\", \"milt5\", \"milt4\", \"milt3\", \"milt2\", \"milt1\"" << std::endl;
	for (float a = 0.0f; a < 256.0f; a += 1.0f) {
		std::cout << a;
		for (float c = 2147483648.0f; c != 8388608.0f; c *= 0.5f) {
			std::cout << "," << (a + 1.0f + c-c)/ 2.0f;
		}
		std::cout << std::endl;
	}
}
