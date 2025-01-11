#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <iostream>

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

    glfwTerminate();
    return 0;
    
}