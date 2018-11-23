#include "vec4.h"
#include <iostream>

namespace turtle {
	namespace math {

		vec4::vec4()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 0.0f;
		}

		vec4::vec4(const float& x,
				   const float& y,
				   const float& z,
				   const float& w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		vec4::vec4(const vec4& other)
		{
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			this->w = other.w;
		}

		//vec4 vec4::operator=(const vec4& other)
		//{
			//return vec4(other);
		//}

		vec4& vec4::add(const vec4& other)
		{
			x += other.x;
			y += other.y;
			y += other.z;
			y += other.w;

			return *this;
		}

		vec4& vec4::subtract(const vec4& other)
		{
			x -= other.x;
			y -= other.y;
			y -= other.z;
			y -= other.w;

			return *this;
		}

		vec4& vec4::multiply(const vec4& other)
		{
			x *= other.x;
			y *= other.y;
			y *= other.z;
			y *= other.w;

			return *this;
		}

		vec4& vec4::divide(const vec4& other)
		{
			x /= other.x;
			y /= other.y;
			y /= other.z;
			y /= other.w;

			return *this;
		}

		vec4 operator+(vec4 left, const vec4& right)
		{
			return left.add(right);
		}

		vec4 operator-(vec4 left, const vec4& right)
		{
			return left.subtract(right);
		}

		vec4 operator*(vec4 left, const vec4& right)
		{
			return left.multiply(right);
		}

		vec4 operator/(vec4 left, const vec4& right)
		{
			return left.divide(right);
		}

		vec4& vec4::operator+=(const vec4& other)
		{
			return add(other);
		}

		vec4& vec4::operator-=(const vec4& other)
		{
			return subtract(other);
		}

		vec4& vec4::operator*=(const vec4& other)
		{
			return multiply(other);
		}

		vec4& vec4::operator/=(const vec4& other)
		{
			return divide(other);
		}

		bool vec4::operator==(const vec4& other)
		{
			return x == other.x && 
				   y == other.y &&
				   z == other.z &&
				   y == other.w;
		}

		bool vec4::operator!=(const vec4& other)
		{
			return !(*this == other);
		}

		//bool vec4::operator<(const vec4& other) {}

		//bool vec4::operator>(const vec4& other) {}

		std::ostream& operator<<(std::ostream& os, const vec4& vector)
		{
			os << "vec4: (" << vector.x << ", " 
							<< vector.y << ", "
							<< vector.z << ", "
							<< vector.w << ")";

			return os;
		}

	}
}

