#include "VertexBuffer.h"
#include "Renderer.h"

VertexBuffer::VertexBuffer(const void * data, unsigned int size)
{
    CallGL(glGenBuffers(1, &m_RendererID)); // Requesting OpenGL for 1 buffer. The buffer IDs are stored in buffer.
    CallGL(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID)); // Selecting the buffer that we "generated" in the last function call
    CallGL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW)); // Filling the buffer with data
}

VertexBuffer::~VertexBuffer()
{
    CallGL(glDeleteBuffers(1, &m_RendererID));
}

void VertexBuffer::bind() const
{
    CallGL(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::unbind() const
{
    CallGL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}