#pragma once

#include "math_general.h"
#include "vec3.h"
#include "vec4.h"


namespace turtle {
	namespace math {

		struct mat4
		{
			union
			{
				float elements[4 * 4];
				struct
				{
					vec4 columns[4];
				};
			};

			//float elements[16];

			mat4();
			mat4(float diagonal);
			mat4(const mat4& other);

			static mat4 identity();

			mat4& multiply(const mat4& other);
			friend mat4 operator*(mat4 left, const mat4& right);
			mat4& operator*=(const mat4& other);

			static mat4 orthographic(float left, float right, float top, float bottom, float near, float far);
			static mat4 perspective(float fov, float aspectRatio, float near, float far);

			static mat4 translation(const vec3& translation);
			static mat4 rotation(float angle, const vec3& axis);
			static mat4 scale(const vec3& scale);
		};
	}
}