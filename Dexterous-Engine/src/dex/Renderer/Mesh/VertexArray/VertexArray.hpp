#pragma once

#include <vector>
#include "Buffers/VertexBuffer.hpp"
#include "Buffers/IndexBuffer.hpp"

namespace dex
{
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void render();
		void renderAsLines();

		void bind();
		void unbind();
	public:
		VertexBuffer m_VertexBuffers;
		IndexBuffer m_IndexBuffer;
	private:
		uint32 m_ID;
	};
}
