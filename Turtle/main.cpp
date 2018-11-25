#include <iostream>

#include "src/graphics/window.h"
#include "src/math/maths.h"

//#include "src/utils/fileutils.h"
#include "src/graphics/shader.h"

//#include "src/graphics/renderer2d.h"
//#include "src/graphics/simple2drenderer.h"
//#include "src/graphics/batchrenderer2d.h"

//#include "src/graphics/static_sprite.h"
#include "src/graphics/sprite.h"

#include "src/utils/timer.h"
#include <time.h>

#include "src/graphics/layers/tilelayer.h"

#define BATCH_RENDERER_2D

int main()
{
	using namespace turtle;
	using namespace graphics;
	using namespace math;

	Window window("Turtle Engine", 960, 540);
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	
	Shader* shader = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader* shader2 = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader->enable();
	shader2->enable();
	shader->setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader2->setUniform2f("light_pos", vec2(4.0f, 1.5f));

	TileLayer layer(shader);
	for (float y = -9.0f; y < 9.0f; y += 0.1f)
	{
		for (float x = -16.0f; x < 16.0f; x += 0.1f)
		{
			layer.add(new Sprite(x, y, 0.09f, 0.09f, math::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}

	TileLayer layer2(shader2);
	layer2.add(new Sprite(-2, -2, 4, 4, math::vec4(1, 0, 1, 1)));
	
	double lastTimeGL = glfwGetTime();
	unsigned int nbFramesGL = 0;

	Timer time;
	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader->enable();
		//shader->setUniform2f("light_pos", vec2((float)(x * 32.0f / window.getWidth() - 16.0f), (float)(9.0f - y * 18.0f / window.getHeight())));
		shader->setUniform2f("light_pos", vec2(-8, -3));
		shader2->enable();
		shader2->setUniform2f("light_pos", vec2((float)(x * 32.0f / window.getWidth() - 16.0f), (float)(9.0f - y * 18.0f / window.getHeight())));

		layer.render();
		layer2.render();

		window.update();

		// OpenGL framecounter
		nbFramesGL++;
		double currentTimeGL = glfwGetTime();
		if (currentTimeGL - lastTimeGL >= 1.0) {
			printf("%u FPS GL\n", nbFramesGL);
			nbFramesGL = 0;
			lastTimeGL += 1.0f;
		}
	}

	return 0;
}