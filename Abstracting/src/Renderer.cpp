#include "Renderer.h"

#include <iostream>

void clearErrorGL()
{   
    while(glGetError() != GL_NO_ERROR)
        ;
}

bool logCallGL(const char * function, const char * file, int line)
{
    while(GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] (0x" << std::hex << error; // Transformed into hexadecimal format to conform to OpenGL documentation
        std::cout << std::dec << "): " << function << " " << file << ":"  << line << std::endl; // Go back to decimal, otherwise 'line' gets printed as an hexadecimal number!
        return false;
    }
    return true;
}

void Renderer::clear() const
{
    CallGL(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::draw(const VertexArray & va, const IndexBuffer & ib, const Shader & shader) const
{
    shader.bind();
    va.bind();
    ib.bind(); // Supposedly not needed

    /*
        Used most of the time instead of glDrawArrays since it allows the specification of an index buffer.
        mode - GL_TRIANGLES
        count - number of indices we are drawing
        type - type of data inside the index buffer
        indices - offset of the first index in the array in the data store of the buffer currently bound to the GL_ELEMENT_ARRAY_BUFFER 
    */
    CallGL(glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr));
}