#include "vec3.h"
#include <iostream>

namespace turtle {
	namespace math {

		vec3::vec3()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		vec3::vec3(const float& x, const float& y, const float& z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		vec3::vec3(const vec3& other)
		{
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			std::cout << "Called COPY ctor" << std::endl;
		}

		vec3& vec3::add(const vec3& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		vec3& vec3::subtract(const vec3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		vec3& vec3::multiply(const vec3& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;

			return *this;
		}

		vec3& vec3::divide(const vec3& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;

			return *this;
		}

		vec3 operator+(vec3 left, const vec3& right)
		{
			return left.add(right);
		}

		vec3 operator-(vec3 left, const vec3& right)
		{
			return left.subtract(right);
		}

		vec3 operator*(vec3 left, const vec3& right)
		{
			return left.multiply(right);
		}

		vec3 operator/(vec3 left, const vec3& right)
		{
			return left.divide(right);
		}

		vec3& vec3::operator+=(const vec3& other)
		{
			return add(other);
		}

		vec3& vec3::operator-=(const vec3& other)
		{
			return subtract(other);
		}

		vec3& vec3::operator*=(const vec3& other)
		{
			return multiply(other);
		}

		vec3& vec3::operator/=(const vec3& other)
		{
			return divide(other);
		}

		bool vec3::operator==(const vec3& other)
		{
			return x == other.x && y == other.y && z == other.z;
		}

		bool vec3::operator!=(const vec3& other)
		{
			return !(*this == other);
		}

		//bool vec3::operator<(const vec3& other) {}

		//bool vec3::operator>(const vec3& other) {}

		std::ostream& operator<<(std::ostream& os, const vec3& vector)
		{
			os << "vec3: (" << vector.x << ", "
							<< vector.y << ", "
							<< vector.z << ")";

			return os;
		}

	}
}

