#pragma once

#include "layer.h"
#include "../batchrenderer2d.h"

namespace turtle {
	namespace graphics {

		class TileLayer : public Layer
		{
		public:
			TileLayer(Shader* shader);
			~TileLayer();
		};

	}
}