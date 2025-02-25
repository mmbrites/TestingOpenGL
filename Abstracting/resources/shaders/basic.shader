#shader vertex
#version 330 core

layout(location = 0) in vec4 position; // 'location' --> Index of the vertex attribute. We use vec4 instead of a vec2 because 'gl_Position' is a vec4
layout(location = 1) in vec2 texCoord;

out vec2 v_TexCoord;

uniform mat4 u_MVP; // MVP - model view projection matrix

void main()
{
   gl_Position = u_MVP * position; // Multiply by the orthographic projection matrix
   v_TexCoord = texCoord;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

uniform vec4 u_Color; // Uniform variable that connects with the CPU side of things. To differentiate between uniform variables and the rest, we prefix these with 'u_'
uniform sampler2D u_Texture;

void main()
{
   vec4 texColor = texture(u_Texture, v_TexCoord);
   color = texColor;
};