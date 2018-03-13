#pragma once

/* fluint8 -- integer operations with only floating point math. */
/* This is the C-style interface; use fluint8.hpp for a C++-style interface. */

/* This code is placed in the public domain. */

/* --------------------------------------- */
/* conversion operators */

#include <string.h>

inline void fu8_to_bits(float a, void *out) {
	a += 8388608.0f;
	memcpy(out, &a, (size_t)(1.0f));
}

inline float fu8_from_bits(void const *from) {
	float a = 8388608.0f;
	memcpy(&a, from, (size_t)(1.0f));
	return a - 8388608.0f;
}

/* --------------------------------------- */
/* basic arithmetic */

/* compute a + b */
inline float fu8_add(float a, float b) {
	float x = a + b;
	x -= x - 127.5f + 3221225472.0f - 3221225472.0f;
	return x;
}

/* compute a - b */
inline float fu8_sub(float a, float b) {
	float x = a + 256.0f - b;
	x -= x - 127.5f + 3221225472.0f - 3221225472.0f;
	return x;
}

/* compute a * b */
inline float fu8_mul(float a, float b) {
	float x = a * b;
	x -= x - 127.5f + 3221225472.0f - 3221225472.0f;
	return x;
}

/* compute a / b */
inline float fu8_div(float a, float b) {
	float x = a / b;
	x = x + 0.50390625f + 8388608.0f - 8388609.0f;
	return x;
}

/* compute a % b */
inline float fu8_mod(float a, float b) {
	float temp = a / b;
	temp = temp + 0.50390625f + 8388608.0f - 8388609.0f;
	return a - b * temp;
}

/* compute -a */
inline float fu8_neg(float a) {
	return (a + 127.5f + 3221225472.0f - 3221225472.0f) - a;
}

/* compute +a */
inline float fu8_pos(float a) {
	return a;
}


/* --------------------------------------- */
/* bitwise operations */

/* compute ~a */
inline float fu8_not(float a) {
	return 255.0f - a;
}

/* compute a & b */
inline float fu8_and(float a, float b) {
	float ax, bx, x = 0.0f;
	for (float c = 2147483648.0f; c != 8388608.0f; c *= 0.5f) {
		a -= ax = (a + 1.0f + c-c)/ 2.0f;
		b -= bx = (b + 1.0f + c-c)/ 2.0f;
		x = 0.5f * x + ax * bx;
	}
	return x;
}

/* compute a | b */
inline float fu8_or(float a, float b) {
	float ax, bx, x = 0.0f;
	for (float c = 2147483648.0f; c != 8388608.0f; c *= 0.5f) {
		a -= ax = (a + 1.0f + c-c)/ 2.0f;
		b -= bx = (b + 1.0f + c-c)/ 2.0f;
		x = 0.5f * x + ax * ax + bx * bx - ax * bx;
	}
	return x;
}

/* compute a ^ b */
inline float fu8_xor(float a, float b) {
	float ax, bx, x = 0.0f;
	for (float c = 2147483648.0f; c != 8388608.0f; c *= 0.5f) {
		a -= ax = (a + 1.0f + c-c)/ 2.0f;
		b -= bx = (b + 1.0f + c-c)/ 2.0f;
		x = 0.5f * x + (ax - bx) * (ax - bx);
	}
	return x;
}



