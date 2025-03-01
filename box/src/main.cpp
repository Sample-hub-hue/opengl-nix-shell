// #include <GLFW/glfw3.h>
//
// int main(void)
// {
//     GLFWwindow* window;
//
//     /* Initialize the library */
//     if (!glfwInit())
//         return -1;
//
//     /* Create a windowed mode window and its OpenGL context */
//     window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//     if (!window)
//     {
//         glfwTerminate();
//         return -1;
//     }
//
//     /* Make the window's context current */
//     glfwMakeContextCurrent(window);
//
//     /* Loop until the user closes the window */
//     while (!glfwWindowShouldClose(window))
//     {
//         /* Render here */
//         glClear(GL_COLOR_BUFFER_BIT);
//
//         /* Swap front and back buffers */
//         glfwSwapBuffers(window);
//
//         /* Poll for and process events */
//         glfwPollEvents();
//     }
//
//     glfwTerminate();
//     return 0;
// }

// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <iostream>
// #include <string>
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>
//
// // Compile shader
// GLuint CompileShader(const std::string& shaderCode, GLenum shaderType) {
//     GLuint shader = glCreateShader(shaderType);
//     const char* shaderCodeCStr = shaderCode.c_str();
//     glShaderSource(shader, 1, &shaderCodeCStr, nullptr);
//     glCompileShader(shader);
//
//     // Check for compile errors
//     GLint success;
//     glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
//     if (!success) {
//         char infoLog[512];
//         glGetShaderInfoLog(shader, 512, nullptr, infoLog);
//         std::cerr << "Shader compilation failed: " << infoLog << std::endl;
//     }
//
//     return shader;
// }
//
// // Create shader program
// GLuint CreateShaderProgram(const std::string& vertexShaderCode, const
// std::string& fragmentShaderCode) {
//     GLuint vertexShader = CompileShader(vertexShaderCode, GL_VERTEX_SHADER);
//     GLuint fragmentShader = CompileShader(fragmentShaderCode,
//     GL_FRAGMENT_SHADER);
//
//     GLuint shaderProgram = glCreateProgram();
//     glAttachShader(shaderProgram, vertexShader);
//     glAttachShader(shaderProgram, fragmentShader);
//     glLinkProgram(shaderProgram);
//
//     // Check for linking errors
//     GLint success;
//     glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//     if (!success) {
//         char infoLog[512];
//         glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
//         std::cerr << "Program linking failed: " << infoLog << std::endl;
//     }
//
//     glDeleteShader(vertexShader);
//     glDeleteShader(fragmentShader);
//
//     return shaderProgram;
// }
//
// int main() {
//     // Shader source code
//     const std::string vertexShaderCode = R"(
//         #version 330 core
//         layout(location = 0) in vec3 aPos;
//         uniform mat4 transform;  // Transformation matrix
//         void main() {
//             gl_Position = transform * vec4(aPos, 1.0);
//         }
//     )";
//
//     const std::string fragmentShaderCode = R"(
//         #version 330 core
//         out vec4 FragColor;
//         void main() {
//             FragColor = vec4(0.2f, 0.3f, 0.3f, 1.0f);  // Set a light blue
//             color
//         }
//     )";
//
//     // Initialize GLFW
//     if (!glfwInit()) {
//         std::cerr << "GLFW initialization failed!" << std::endl;
//         return -1;
//     }
//
//     // Create GLFW windowed context
//     GLFWwindow* window = glfwCreateWindow(800, 600, "Bouncing Square",
//     nullptr, nullptr); if (!window) {
//         std::cerr << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         return -1;
//     }
//
//     glfwMakeContextCurrent(window);
//
//     // Initialize GLAD (must be done after creating OpenGL context)
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//         std::cerr << "Failed to initialize GLAD" << std::endl;
//         return -1;
//     }
//
//     // Create shader program
//     GLuint shaderProgram = CreateShaderProgram(vertexShaderCode,
//     fragmentShaderCode);
//
//     // Define vertices for a square (2 triangles)
//     float vertices[] = {
//         // Positions
//         -0.5f,  0.5f, 0.0f,  // Top left
//          0.5f,  0.5f, 0.0f,  // Top right
//          0.5f, -0.5f, 0.0f,  // Bottom right
//
//          0.5f, -0.5f, 0.0f,  // Bottom right
//         -0.5f, -0.5f, 0.0f,  // Bottom left
//         -0.5f,  0.5f, 0.0f   // Top left
//     };
//
//     // Set up buffers and array objects
//     GLuint VBO, VAO;
//     glGenVertexArrays(1, &VAO);
//     glGenBuffers(1, &VBO);
//
//     // Bind VAO and VBO
//     glBindVertexArray(VAO);
//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,
//     GL_STATIC_DRAW);
//
//     // Define vertex attributes
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
//     (void*)0); glEnableVertexAttribArray(0);
//
//     // Unbind VBO and VAO
//     glBindBuffer(GL_ARRAY_BUFFER, 0);
//     glBindVertexArray(0);
//
//     // Square movement variables
//     float xPos = 0.0f, yPos = 0.0f;  // Initial position
//     float xSpeed = 0.01f, ySpeed = 0.01f;  // Speed of the square
//     float squareSize = 0.5f;  // Size of the square (controls the size of the
//     square's movement)
//
//     // Set up projection and view matrix for camera
//     glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
//     // Orthographic projection
//
//     // Render loop
//     while (!glfwWindowShouldClose(window)) {
//         glClear(GL_COLOR_BUFFER_BIT);
//
//         // Move the square
//         xPos += xSpeed;
//         yPos += ySpeed;
//
//         // Bounce off the walls
//         if (xPos + squareSize > 1.0f || xPos - squareSize < -1.0f) {
//             xSpeed = -xSpeed;  // Reverse direction if hitting the left or
//             right wall
//         }
//         if (yPos + squareSize > 1.0f || yPos - squareSize < -1.0f) {
//             ySpeed = -ySpeed;  // Reverse direction if hitting the top or
//             bottom wall
//         }
//
//         // Use the shader program
//         glUseProgram(shaderProgram);
//
//         // Create transformation matrix for movement
//         glm::mat4 transform = projection;  // Start with projection matrix
//         transform = glm::translate(transform, glm::vec3(xPos, yPos, 0.0f));
//         // Translate square GLuint transformLoc =
//         glGetUniformLocation(shaderProgram, "transform");
//         glUniformMatrix4fv(transformLoc, 1, GL_FALSE,
//         glm::value_ptr(transform));
//
//         // Bind VAO and draw the square
//         glBindVertexArray(VAO);
//         glDrawArrays(GL_TRIANGLES, 0, 6);  // Render the square (2 triangles)
//         glBindVertexArray(0);
//
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }
//
//     // Cleanup
//     glDeleteVertexArrays(1, &VAO);
//     glDeleteBuffers(1, &VBO);
//     glDeleteProgram(shaderProgram);
//     glfwDestroyWindow(window);
//     glfwTerminate();
//
//     return 0;
// }
//

#define GLAD_GL_IMPLEMENTATION
#include "glad.h"

#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "GLFW initialization failed!" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "Simple Triangle", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable v-sync

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD!" << std::endl;
        return -1;
    }

    // Define the triangle's vertices
    float vertices[] = {
        0.0f,  0.5f, 0.0f,  // Top vertex
       -0.5f, -0.5f, 0.0f,  // Bottom-left vertex
        0.5f, -0.5f, 0.0f   // Bottom-right vertex
    };

    // Generate and bind VAO and VBO
    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Specify the layout of the vertex data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Simple Shader Code (Vertex Shader + Fragment Shader in a single line)
    const char* vertexShaderSource = "#version 330 core\nlayout(location = 0) in vec3 aPos;void main(){gl_Position = vec4(aPos, 1.0);}";
    const char* fragmentShaderSource = "#version 330 core\nout vec4 FragColor;void main(){FragColor = vec4(1.0, 0.0, 0.0, 1.0);}"; // Red

    // Compile and create the shaders
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Link shaders to a shader program
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    // Clean up shaders (no longer needed after linking)
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Process input
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        // Clear the screen with a color
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the triangle
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    // Terminate GLFW
    glfwTerminate();
    return 0;
}

