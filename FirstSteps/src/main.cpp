#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <iostream>

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

    int version = gladLoadGL(glfwGetProcAddress);

    if (version == 0)
    {
        std::cout << "Failed to initialise OpenGL context." << std::endl;
        return -1;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;
    std::cout << "GL " << GLAD_VERSION_MAJOR(version) << "." << GLAD_VERSION_MINOR(version) << std::endl;

    float positions[6] = {
        -0.5f, -0.5f, 
         0.0f,  0.5f, 
         0.5f, -0.5f
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer); // Requesting OpenGL for 1 buffer. The buffer IDs are stored in buffer.
    glBindBuffer(GL_ARRAY_BUFFER, buffer); // Selecting the buffer that we "generated" in the last function call
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW); // Filling the buffer with data

    /*
        index = 0 --> index of the vertex attribute to be modified
        size = 2 --> size of the vertex attribute
        type = GL_FLOAT --> type of the contents in the vertex attribute
        normalized = GL_FALSE --> normalising is changing the range to 0 - 1
        stride = 2 * sizeof(float) --> bytes in between vertices
        pointer = 0 --> offset of the vertex attribute
    */
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
    // 0 --> the index of the vertex attribute to be enabled
    glEnableVertexAttribArray(0);

    // This should have been done in a file, but whatever
    std::string vertexShader = 
        "#version 330 core\n" // Specifies the version of the GLSL (Shading Language). 'core' means that you cannot use deprecated functions
        "\n"
        "layout(location = 0) in vec4 position;\n" // 'location' --> Index of the attribute. We use vec4 instead of a vec2 because 'gl_Position' is a vec4
        "\n"
        "void main()\n"
        "{\n"
        "   gl_Position = position;\n"
        "}\n";

     std::string fragmentShader = 
        "#version 330 core\n" // Specifies the version of the GLSL (Shading Language). 'core' means that you cannot use deprecated functions
        "\n"
        "layout(location = 0) out vec4 color;\n" // We want to output a 'color'
        "\n"
        "void main()\n"
        "{\n"
        "   color = vec4(1.0, 0.0, 0.0, 1.0);\n" // Color: red
        "}\n";
    
    unsigned int shader = createShader(vertexShader, fragmentShader);
    glUseProgram(shader);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    
    }

    glDeleteProgram(shader);

    glfwTerminate();
    return 0;
    
}