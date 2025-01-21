#pragma once

#include "Renderer.h"

#include <vector>

// Each elements corresponds to one characteristic, e.g., 3 vertices = 1 elements, 3 floats (RGB) = 1 element, ...
struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalised;

    static unsigned int getSizeOfType(unsigned int type)
    {
        switch (type)
        {
            case GL_FLOAT:         return 4;
            case GL_UNSIGNED_INT:  return 4;
            case GL_UNSIGNED_BYTE: return 1;
        }
        ASSERT(false);
        return 0;
    }
};

class VertexBufferLayout
{

    private:
        std::vector<VertexBufferElement> m_Elements;
        unsigned int m_Stride;

    public:
        VertexBufferLayout() : m_Stride(0) {}

        template<typename T>
        void push(unsigned int count)
        {
            static_assert(false); // static_assert(false) will cause a compile-time error and prevent the program from compiling. It is useful here, because we only want this function used with template parameters
        }

        inline const std::vector<VertexBufferElement> & getElements() const { return m_Elements; };
        inline unsigned int getStride() const { return m_Stride; };

};

template<>
void VertexBufferLayout::push<float>(unsigned int count);

template<>
void VertexBufferLayout::push<unsigned int>(unsigned int count);

template<>
void VertexBufferLayout::push<unsigned char>(unsigned int count);