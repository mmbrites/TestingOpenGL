#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <signal.h>

#define ASSERT(x) if (!(x)) raise(SIGTRAP) // The raise() function sends a signal to the calling process, and SIGTRAP stops program state when debugging. When running, the program aborts.
#define CallGL(x) clearErrorGL();\
    x;\
    ASSERT(logCallGL(#x, __FILE__, __LINE__)) // This whole macro lets us wrap the OpenGL functions instead of calling clearErrorGL() and ASSERT(logCallGL()) before and after every OpenGL function call. The first argument transforms 'x' into a string, the second argument is a predefined macro that expands to the name of the current source file as a string literal, and the third argument is a predefined macro that expands to the current line number in the source file.

static void clearErrorGL()
{   
    while(glGetError() != GL_NO_ERROR)
        ;
}

static bool logCallGL(const char * function, const char * file, int line)
{
    while(GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] (0x" << std::hex << error; // Transformed into hexadecimal format to conform to OpenGL documentation
        std::cout << std::dec << "): " << function << " " << file << ":"  << line << std::endl; // Go back to decimal, otherwise 'line' gets printed as an hexadecimal number!
        return false;
    }
    return true;
}

struct ShaderProgramSource
{
    std::string vertexSourceCode;
    std::string fragmentSourceCode;
};

static ShaderProgramSource parseShader(const std::string & filePath)
{

    // Not the most efficient way of dealing with files. The C way is better for performance
    std::ifstream stream(filePath);

    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2]; // Two stringstreams: one for the vertex shader, one the fragment shader
    ShaderType type = ShaderType::NONE;
    while (getline(stream, line)) // 'line' stores the result
    {
        if (line.find("shader") != std::string::npos) // "find" returns the position of the first character of the found substring or 'npos' if no such substring is found.
        {
            if (line.find("vertex") != std::string::npos)
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                type = ShaderType::FRAGMENT;

        }
        else
            ss[(int)type] << line << '\n';
    }

    return { ss[0].str(), ss[1].str() };

}

static unsigned int compileShader(unsigned int type, const std::string & source)
{
    
    unsigned int id = glCreateShader(type);
    const char * src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char * message = (char *) alloca(length * sizeof(char)); // Since C++ does not let you declare a C-style array with an arbitrary length, and you want to declare it on the stack, you can use alloca -- the only problem arises when the array is too big, since it may cause a stack overflow.
        glGetShaderInfoLog(id, length, &length, message);

        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
        std::cout << message << std::endl;

        glDeleteShader(id);
        return 0;

    }

    return id;

}

/*
    vertexShader - vertex shader source code
    fragmentShader - fragment shader source code
*/
static unsigned int createShader(const std::string & vertexShader, const std::string & fragmentShader)
{

    // Code necessary to compile both shaders
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    // Frees memory - although there are some that like to argue that it is inneffective in case you want to debug the shader source code
    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;

}

int main(void)
{
   
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1); // Syncs your rendering loop to the refresh rate of the monitor - VSync

    int version = gladLoadGL(glfwGetProcAddress);

    if (version == 0)
    {
        std::cout << "Failed to initialise OpenGL context." << std::endl;
        return -1;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;
    std::cout << "GL " << GLAD_VERSION_MAJOR(version) << "." << GLAD_VERSION_MINOR(version) << std::endl;

    float positions[] = {
        -0.5f, -0.5f, // 0
         0.5f, -0.5f, // 1
         0.5f,  0.5f, // 2
        -0.5f,  0.5f  // 3
    };

    // Index Buffer: Vertex indices used for each triangle. Note: you can use unsigned char or unsigned short if you want to save memory, but the type has to be "unsigned"
    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    unsigned int buffer;
    CallGL(glGenBuffers(1, &buffer)); // Requesting OpenGL for 1 buffer. The buffer IDs are stored in buffer.
    CallGL(glBindBuffer(GL_ARRAY_BUFFER, buffer)); // Selecting the buffer that we "generated" in the last function call
    CallGL(glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), positions, GL_STATIC_DRAW)); // Filling the buffer with data

    /*
        Tell OpenGL how to interpret data:
            index = 0 --> index of the vertex attribute to be modified
            size = 2 --> size of the vertex attribute
            type = GL_FLOAT --> type of the contents in the vertex attribute
            normalized = GL_FALSE --> normalising is changing the range to 0 - 1
            stride = 2 * sizeof(float) --> bytes in between vertices
            pointer = 0 --> offset of the vertex attribute
    */
    CallGL(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));
    // 0 --> the index of the vertex attribute to be enabled
    CallGL(glEnableVertexAttribArray(0));

    unsigned int indexBufferObject;
    CallGL(glGenBuffers(1, &indexBufferObject));
    CallGL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject)); // Selecting the buffer that we "generated" in the last function call
    CallGL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW)); // Filling the buffer with data

    ShaderProgramSource source = parseShader("../resources/shaders/basic.shader"); // The relative path is relative to the executable, not to the source code!
    unsigned int shader = createShader(source.vertexSourceCode, source.fragmentSourceCode);
    CallGL(glUseProgram(shader));

    // Uniforms can only be sent to the shader after the call 'glUseProgram()' is done
    CallGL(int location = glGetUniformLocation(shader, "u_Color")); // Obtains the index of the u_Color variable in the shader
    ASSERT(location != -1); // OpenGL actually returns '-1' even if the variable is declared in the shader. The only time that happens is when the variable is not used in the shader
    CallGL(glUniform4f(location, 0.8f, 0.3f, 0.8f, 1.0f)); // Specifies the value of a uniform variable composed of 4 floats. Check 'glUniform' in the OpenGL documentation for more information.

    float r = 0.0f; // Used to update the 'R' in 'RGB'
    float increment = 0.05f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        /* Render here */
        CallGL(glClear(GL_COLOR_BUFFER_BIT));

        CallGL(glUniform4f(location, r, 0.3f, 0.8f, 1.0f)); 

        // glDrawArrays(GL_TRIANGLES, 0, 6);
        /*
            Used most of the time instead of glDrawArrays since it allows the specification of an index buffer.
            mode - GL_TRIANGLES
            count - number of indices we are drawing
            type - type of data inside the index buffer
            indices - offset of the first index in the array in the data store of the buffer currently bound to the GL_ELEMENT_ARRAY_BUFFER 
        */
        CallGL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

        // Some logic to change color
        if (r > 1.0f)
            increment = -0.05f;
        else if (r < 0.0f)
            increment = 0.05f;

        r += increment;

        /* Swap front and back buffers */
        CallGL(glfwSwapBuffers(window));

        /* Poll for and process events */
        CallGL(glfwPollEvents());
    
    }

    // glDeleteProgram(shader);

    glfwTerminate();
    return 0;
    
}