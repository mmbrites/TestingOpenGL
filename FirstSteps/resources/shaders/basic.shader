#shader vertex
#version 330 core // Specifies the version of the GLSL (Shading Language). 'core' means that you cannot use deprecated functions

layout(location = 0) in vec4 position; // 'location' --> Index of the attribute. We use vec4 instead of a vec2 because 'gl_Position' is a vec4

void main()
{
   gl_Position = position;
};

#shader fragment
#version 330 core // Specifies the version of the GLSL (Shading Language). 'core' means that you cannot use deprecated functions

layout(location = 0) out vec4 color; // We want to output a 'color'

void main()
{
   color = vec4(0.2, 0.3, 0.8, 1.0); // Color: red
};