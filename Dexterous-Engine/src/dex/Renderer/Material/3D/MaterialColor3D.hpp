#pragma once

#include "../Material.hpp"

namespace dex
{
	namespace Material
	{
		struct Color3D : public Base
		{
		public:
			Color3D(std::weak_ptr<Shader::Base> shader, glm::vec4 color)
				: Base(shader), m_Color(color)
			{}

			virtual void setUniforms() override {}

			glm::vec4 m_Color;
		};
	}
}