#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <signal.h>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"

int main(void)
{
   
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Setting OpenGL version for 3.x
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Setting OpenGL version y.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // OpenGL profiles define sets of features and behaviors of the API, allowing developers to target specific versions or subsets of OpenGL functionality GLFW_OPENGL_CORE_PROFILE only includes modern OpenGL features introduced in OpenGL 3.2 and later. GLFW_OPENGL_COMPAT_PROFILE includes both modern features and legacy OpenGL functionality.

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

    {   // Creating scope instead of heap allocating Vertex and Index buffers
        float positions[] = {
            -0.5f, -0.5f, 0.0f, 0.0f, // 0 & the bottom-left corner of the texture
            0.5f, -0.5f, 1.0f, 0.0f, // 1 & the bottom-right corner of the texture
            0.5f,  0.5f, 1.0f, 1.0f, // 2 & the top-right corner of the texture
            -0.5f,  0.5f,  0.0f, 1.0f // 3 & the top-left corner of the texture
        };

        // Index Buffer: Vertex indices used for each triangle. Note: you can use unsigned char or unsigned short if you want to save memory, but the type has to be "unsigned"
        unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
        };

        CallGL(glEnable(GL_BLEND)); // Enables blending
        CallGL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)); // used in OpenGL to set the blending mode for rendering transparent or semi-transparent objects. GL_SRC_ALPHA: This is the source factor. It means that the transparency of the source pixel will be based on its alpha value. A fully opaque source will contribute fully to the final color, while a transparent source will contribute less. GL_ONE_MINUS_SRC_ALPHA: This is the destination factor. It means the destination's transparency will be based on the inverse of the source's alpha value. So, a fully opaque source will let the destination show through, while a transparent source will mix more with the destination.

        VertexArray va;
        VertexBuffer vb(positions, 4 * 4 * sizeof(float));
        
        VertexBufferLayout layout;
        layout.push<float>(2); // The parameter number corresponds to the number of arguments per elements, in this case, we are using an (x, y) model, so there are only two arguments
        layout.push<float>(2);
        va.addBuffer(vb, layout);

        IndexBuffer ib(indices, 6);

        Shader shader("../resources/shaders/basic.shader");
        shader.bind();
        shader.setUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

        Texture texture("../resources/textures/Sunny.png");
        texture.bind(); // Binding texture to slot 0
        shader.setUniform1i("u_Texture", 0); // '0' because we bound our texture to slot 0!

        // Unbinding buffers
        va.unbind();
        vb.unbind();
        ib.unbind();
        shader.unbind();

        Renderer renderer;

        float r = 0.0f; // Used to update the 'R' in 'RGB'
        float increment = 0.05f;

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {

            /* Render here */
            renderer.clear();

            shader.bind();
            shader.setUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);

            renderer.draw(va, ib, shader);

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

    }

    glfwTerminate();
    return 0;
    
}