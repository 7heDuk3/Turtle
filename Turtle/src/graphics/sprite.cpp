#include "sprite.h"

namespace turtle {
	namespace graphics {

		Sprite::Sprite(float x, float y, float width, float height, math::vec4& color)
			: Renderable2D(math::vec3(x, y, 0), math::vec2(width, height), color/*math::vec4(color.x, color.y, color.z, color.w)*/)
		{
			/*m_Position.x = x;
			m_Position.y = y;
			m_Position.z = 0;

			m_Size.x = width;
			m_Size.y = height;
			
			m_Color.x = color.x;
			m_Color.y = color.y;
			m_Color.z = color.z;
			m_Color.w = color.w;*/
		}

	}
}