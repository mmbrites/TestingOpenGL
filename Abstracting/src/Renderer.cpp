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