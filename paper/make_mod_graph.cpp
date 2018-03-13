#include <iostream>
#include <cmath>

int main(int argc, char **argv) {
	for (float a = -256.0f; a <= 512.0f; a += 1.0f) {
		float x = a;
		x -= x - 127.5f + 3221225472.0f - 3221225472.0f;
		float y = fmodf(a, 256.0f);
		std::cout << a << "," << x << "," << y << std::endl;
	}
}
