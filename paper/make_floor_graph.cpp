#include <iostream>
#include <cmath>
#include <unordered_set>

int main(int argc, char **argv) {
	std::unordered_set< float > done;
	std::cout << "\"x\", \"x+a+b-c\", \"floorf(x)\"" << std::endl;
	for (float a = 0.0f; a < 256.0f; a += 1.0f) {
		for (float b = 1.0f; b < 256.0f; b += 1.0f) {
			float x = a / b;
			if (!done.insert(x).second) continue;
			float y = x + 0.50390625f + 8388608.0f - 8388609.0f;
			std::cout << x << "," << y << "," << floorf(x) << std::endl;
		}
	}
}
