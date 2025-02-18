#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <signal.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#define ASSERT(x) if (!(x)) raise(SIGTRAP) // The raise() function sends a signal to the calling process, and SIGTRAP stops program state when debugging. When running, the program aborts.
#define CallGL(x) clearErrorGL();\
    x;\
    ASSERT(logCallGL(#x, __FILE__, __LINE__)) // This whole macro lets us wrap the OpenGL functions instead of calling clearErrorGL() and ASSERT(logCallGL()) before and after every OpenGL function call. The first argument transforms 'x' into a string, the second argument is a predefined macro that expands to the name of the current source file as a string literal, and the third argument is a predefined macro that expands to the current line number in the source file.

void clearErrorGL();
bool logCallGL(const char * function, const char * file, int line);

class Renderer
{
    public:
        void clear() const;
        void draw(const VertexArray & va, const IndexBuffer & ib, const Shader & shader) const;
};