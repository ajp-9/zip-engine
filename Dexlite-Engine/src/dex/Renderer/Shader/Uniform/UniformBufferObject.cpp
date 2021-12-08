#include "UniformBufferObject.hpp"

#include <glad/glad.h>
#include "../ShaderBase.hpp"

namespace dex
{
    namespace Shader
    {
        UniformBufferObject::UniformBufferObject(const char* name)
            : m_Name(name)
        {
            glGenBuffers(1, &m_ID);

            bind();

            m_BlockBinding = s_NextBlockBinding++;
        }

        void UniformBufferObject::bindMultipleShaders(const std::vector<std::shared_ptr<Shader::Base>>& shaders)
        {
        }

        void UniformBufferObject::bindShader(const std::shared_ptr<Shader::Base>& shader)
        {
            bind();

            uint32_t internalBlockBinding = glGetUniformBlockIndex(shader->getID(), m_Name.c_str());

            glUniformBlockBinding(shader->getID(), internalBlockBinding, m_BlockBinding);
            glGetActiveUniformBlockiv(shader->getID(), internalBlockBinding, GL_UNIFORM_BLOCK_DATA_SIZE, &m_BlockSize);
            std::cout << m_BlockSize << "\n";
        }

        void UniformBufferObject::setup()
        {
            bind();

            glBufferData(GL_UNIFORM_BUFFER, m_BlockSize, NULL, GL_STATIC_DRAW);

            glBindBufferBase(GL_UNIFORM_BUFFER, m_BlockBinding, m_ID); // Or maybe glBindBufferBase
        }

        void UniformBufferObject::uploadData(const void* data)
        {
            bind();

            glBufferSubData(GL_UNIFORM_BUFFER, 0, m_BlockSize, data);
        }

        void UniformBufferObject::bind()
        {
            glBindBuffer(GL_UNIFORM_BUFFER, m_ID);
        }

        void UniformBufferObject::unbind()
        {
            glBindBuffer(GL_UNIFORM_BUFFER, 0);
        }

        /* 
        ** Initialize Static Memeber Variables
        */

        uint32_t UniformBufferObject::s_NextBlockBinding = 0;
    }
}