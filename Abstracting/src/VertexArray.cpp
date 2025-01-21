#include "VertexArray.h"
#include "Renderer.h"

VertexArray::VertexArray()
{
    CallGL(glGenVertexArrays(1, &m_RendererID)); // generate vertex array object IDs
}

VertexArray::~VertexArray()
{
    CallGL(glDeleteVertexArrays(1, &m_RendererID));
}

void VertexArray::addBuffer(const VertexBuffer & vb, const VertexBufferLayout & layout)
{
    bind();
    vb.bind();
    const auto & elements = layout.getElements();
    unsigned int offset = 0;

    // During this cycle, we are sending the layout information to OpenGL
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto & element = elements[i];
        CallGL(glEnableVertexAttribArray(i)); // the index of the vertex attribute to be enabled
        CallGL(glVertexAttribPointer(i, element.count, element.type, element.normalised, layout.getStride(), (const void *) offset));
        offset += element.count * VertexBufferElement::getSizeOfType(element.type);
    }
}

void VertexArray::bind() const
{
    CallGL(glBindVertexArray(m_RendererID));
}

void VertexArray::unbind() const
{
    CallGL(glBindVertexArray(0));
}