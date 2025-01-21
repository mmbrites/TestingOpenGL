#include "IndexBuffer.h"
#include "Renderer.h"

IndexBuffer::IndexBuffer(const unsigned int * data, unsigned int count) : m_Count(count)
{
    ASSERT(sizeof(unsigned int) == sizeof(GLuint)); // There is an low possibility that an 'unsigned int' is not 4 bytes in some systems
    CallGL(glGenBuffers(1, &m_RendererID)); // Requesting OpenGL for 1 buffer. The buffer IDs are stored in buffer.
    CallGL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID)); // Selecting the buffer that we "generated" in the last function call
    CallGL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW)); // Filling the buffer with data
}

IndexBuffer::~IndexBuffer()
{
    CallGL(glDeleteBuffers(1, &m_RendererID));
}

void IndexBuffer::bind() const
{
    CallGL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
}

void IndexBuffer::unbind() const
{
    CallGL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}