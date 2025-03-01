#version 330 core

layout(location = 0) in vec3 aPos;  // Vertex position

uniform mat4 model;  // Model transformation matrix

void main() {
    gl_Position = model * vec4(aPos, 1.0);  // Apply transformation to position
}

