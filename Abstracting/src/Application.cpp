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

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

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
    window = glfwCreateWindow(960, 540, "Hello World", NULL, NULL);
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

    int width, height;
    glfwGetFramebufferSize(window, &width, &height); // Retrieves the size, in pixels, of the framebuffer of the specified window. Without this function call, Linux window managers override OpenGL's window placement.
    glViewport(0, 0, width, height);  // A viewport defines the portion of the window where rendering occurs. It maps Normalised Device Coordinates (NDC), which range from -1 to 1, into actual screen coordinates (pixels).

    {   // Creating scope instead of heap allocating Vertex and Index buffers
        float positions[] = {
             100.0f, 100.0f,  0.0f, 0.0f, // 0 & the bottom-left corner of the texture
             200.0f, 100.0f,  1.0f, 0.0f, // 1 & the bottom-right corner of the texture
             200.0f, 200.0f,  1.0f, 1.0f, // 2 & the top-right corner of the texture
             100.0f,  200.0f,  0.0f, 1.0f // 3 & the top-left corner of the texture
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

        glm::mat4 projection = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f); // Orthographic projection - means of representing three-dimensional objects in two dimensions. In an orthographic projection, objects that are far way do not get smaller, unlike a perspective projection. The arguments of the function just need to be specified according to the window proportions, in this case, we are using a 640 x 480 window, which adheres to the 4:3 aspect ratio. We can also roughly interpret this as a window resize, where the boundaries are the ones sent to the ortho function. Any vertex that is not within these boundaries, is not rendered.
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0)); // Applying a transformation to an identity matrix

        Shader shader("../resources/shaders/basic.shader");
        shader.bind();
        shader.setUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

        Texture texture("../resources/textures/ChernoLogo.png");
        texture.bind(); // Binding texture to slot 0
        shader.setUniform1i("u_Texture", 0); // '0' because we bound our texture to slot 0!

        // Unbinding buffers
        va.unbind();
        vb.unbind();
        ib.unbind();
        shader.unbind();

        Renderer renderer;

        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        // Setup Platform / Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(window, true); // Second param install_callback = true will install GLFW callbacks and chain to existing ones.
        ImGui_ImplOpenGL3_Init();
        ImGui::StyleColorsDark();

        glm::vec3 translation(200, 200, 0);

        float r = 0.0f; // Used to update the 'R' in 'RGB'
        float increment = 0.05f;

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {

            /* Render here */
            renderer.clear();

            // Start the Dear ImGui frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
            ImGui::ShowDemoWindow(); // Show demo window! :)

            glm::mat4 model = glm::translate(glm::mat4(1.0f), translation); // Applying a transformation to an identity matrix
            glm::mat4 mvp = projection * view * model; // MVP matrix

            shader.bind();
            shader.setUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);
            shader.setUniformMat4f("u_MVP", mvp);

            renderer.draw(va, ib, shader);

            // Some logic to change color
            if (r > 1.0f)
                increment = -0.05f;
            else if (r < 0.0f)
                increment = 0.05f;

            r += increment;

            // GUI Window
            {
                ImGui::SliderFloat3("Translation", &translation.x, 0.0f, 960.0f);
                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
                // ImGui::End();
            }

            // Rendering
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            /* Swap front and back buffers */
            CallGL(glfwSwapBuffers(window));

            /* Poll for and process events */
            CallGL(glfwPollEvents());
        
        }

    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
    return 0;
    
}