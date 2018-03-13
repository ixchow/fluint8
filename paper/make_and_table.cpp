#include <iostream>
#include <cmath>

int main(int argc, char **argv) {
	float a = 171.0f;
	float b = 226.0f;

	float ax, bx, x = 0.0f;
	std::cout << a << "&" << b << "&" << " " << "&" << " " << "&" << " " << "&" << " " << "\\\\" << std::endl;
	for (float c = 2147483648.0f; c != 8388608.0f; c *= 0.5f) {
		a -= ax = (a + 1.0f + c-c)/ 2.0f;
		b -= bx = (b + 1.0f + c-c)/ 2.0f;
		x = 0.5f * x + ax * bx;
		std::cout << a << "&" << b << "&" << ax << "&" << bx << "&" << x << "&" << uint64_t(c) << "\\\\" << std::endl;
	}
}
