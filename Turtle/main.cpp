#include <iostream>

#include "src/graphics/window.h"
#include "src/math/maths.h"

#include "src/utils/fileutils.h"
#include "src/graphics/shader.h"
#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"

#include "src/graphics/renderer2d.h"
#include "src/graphics/simple2drenderer.h"
#include "src/graphics/batchrenderer2d.h"

#include "src/graphics/static_sprite.h"
#include "src/graphics/sprite.h"

#include <time.h>

#define BATCH_RENDERER_2D

int main()
{
	using namespace turtle;
	using namespace graphics;
	using namespace math;

	Window window("Turtle Engine", 960, 540);
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	
	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);

	std::vector<Renderable2D*> sprites;
	
	srand(time(NULL));
	
	for (float y = 0; y < 9.0f; y += 0.05f)
	{
		for (float x = 0; x < 16.0f; x += 0.05f)
		{
			
			sprites.push_back(new 
#ifdef BATCH_RENDERER_2D
				Sprite
#else
				StaticSprite
#endif
				(x, y, 0.04f, 0.04f, math::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)
#ifndef BATCH_RENDERER_2D
				, shader
#endif
			));
		}
	}
#ifdef BATCH_RENDERER_2D
	Sprite sprite1(5, 5, 4, 4, math::vec4(1, 0, 1, 0.8));
	Sprite sprite2(7, 1, 2, 3, math::vec4(0.2f, 0, 0.2f, 0.4f));
	BatchRenderer2D renderer;

#else
	StaticSprite sprite1(5, 5, 4, 4, math::vec4(1, 0, 1, 1), shader);
	StaticSprite sprite2(7, 1, 2, 3, math::vec4(0.2f, 0, 1, 1), shader);
	Simple2DRenderer renderer;
#endif
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	std::cout << sizeof(math::vec3) << std::endl;
	std::cout << sizeof(math::vec4) << std::endl;

	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / window.getWidth()), (float)(9.0f - y * 9.0f / window.getHeight())));
#ifdef BATCH_RENDERER_2D
		renderer.begin();
#endif
		for (int i = 0; i < sprites.size(); i++)
		{
			renderer.submit(sprites[i]);
		}
		//renderer.submit(&sprite1);
		//renderer.submit(&sprite2);
#ifdef BATCH_RENDERER_2D
		renderer.end();
#endif
		renderer.flush();
		printf("Sprites: %d\n", sprites.size());
		window.update();
	}

	return 0;
}