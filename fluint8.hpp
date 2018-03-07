#pragma once

#include <cmath>
#include <cstring>

struct fluint8 {
	//-------------------------------------------
	//constructors:
	fluint8(float val_) : val(val_) {
		val = std::fmod(std::floor(val), 256.0f);
		if (val < 0.0f) val += 256.0f;
	}
	//-------------------------------------------
	//conversions from uint8_t-style bit patterns:
	void get_bits(void *out) const {
		float temp = val + 8388608.0f;
		memcpy(out, &temp, size_t(1.0f));
	}
	void set_bits(void const *from) {
		val = 8388608.0f;
		memcpy(&val, from, size_t(1.0f));
		val -= 8388608.0f;
	}
	//-------------------------------------------
	//basic arithmetic:
	fluint8 &operator+=(fluint8 const &other) {
		val += other.val;
		if (val >= 256.0f) val -= 256.0f;
		return *this;
	}
	fluint8 &operator-=(fluint8 const &other) {
		val -= other.val;
		if (val < 0.0f) val += 256.0f;
		return *this;
	}
	fluint8 &operator*=(fluint8 const &other) {
		val *= other.val;
		val = std::fmod(val, 256.0f);
		return *this;
	}
	fluint8 &operator/=(fluint8 const &other) {
		val /= other.val;
		val = std::floor(val);
		return *this;
	}
	fluint8 &operator%=(fluint8 const &other) {
		val = std::fmod(val, other.val);
		return *this;
	}
	//-------------------------------------------
	//bitwise arithmetic:
	fluint8 &operator&=(fluint8 const &other) {
		*this = (*this & other);
		return *this;
	}
	fluint8 &operator|=(fluint8 const &other) {
		*this = (*this | other);
		return *this;
	}
	fluint8 &operator^=(fluint8 const &other) {
		*this = (*this ^ other);
		return *this;
	}

	//-------------------------------------------
	//unary operations:
	fluint8 operator~() const {
		fluint8 ret(*this);
		ret.val = 255.0f - ret.val;
		return ret;
	}
	fluint8 operator-() const {
		fluint8 ret(*this);
		ret.val = -ret.val;
		if (ret.val != 0.0f) ret.val += 256.0f;
		return ret;
	}
	//-------------------------------------------
	//binary operations:
	fluint8 operator&(fluint8 const &other) const {
		float a = val;
		float b = other.val;

		float ax, bx, x = 0.0f;
		for (float c = 2147483648.0f; c != 8388608.0f; c *= 0.5f) {
			a -= ax = (a + 1.0f + c-c)/ 2.0f;
			b -= bx = (b + 1.0f + c-c)/ 2.0f;
			x = 0.5f * x + ax * bx;
		}
		return fluint8(x);
	}
	fluint8 operator|(fluint8 const &other) const {
		return ~(~(*this) & ~other);
	}
	fluint8 operator^(fluint8 const &other) const {
		return ~(~(*this) & ~other) & ~(*this & other);
	}

	//-------------------------------------------
	//internals:
	float val;
};
