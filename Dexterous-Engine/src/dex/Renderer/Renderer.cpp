#include "Renderer.hpp"

#include <glad/glad.h>

#include "ImGui/ImGuiAPI.hpp"

namespace dex
{
	void Renderer::Init(glm::uvec4 viewport)
	{
		trySetViewport(viewport);

		glEnable(GL_DEPTH_TEST);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		//glEnable(GL_CULL_FACE);
		//glCullFace(GL_BACK);
		glClearColor(.1, .1, .1, 1.0f); // Clear the color buffer

		ImGuiAPI::Init();
	}

	void Renderer::Shutdown() 
	{
		ImGuiAPI::Shutdown();
	}

	void Renderer::beginFrame()
	{
		ImGuiAPI::beginFrame();
	}

	void Renderer::endFrame()
	{
		ImGuiAPI::endFrame();
	}

	void Renderer::update() {}

	void Renderer::renderScene(Scene& scene)
	{
		scene.render();
	}

	void Renderer::trySetViewport(glm::uvec4 viewport)
	{
		if (s_LastViewport != viewport)
		{
			glViewport(viewport.x, viewport.y, viewport.z, viewport.w);
			s_LastViewport = viewport;
		}
	}

	void Renderer::setClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void Renderer::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	/*
	*  Initialize member variables here.
	*/

	glm::uvec4 Renderer::s_LastViewport(glm::uvec4(0));

	Shader::Manager Renderer::s_ShaderManager;
}
