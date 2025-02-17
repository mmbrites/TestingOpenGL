#include "Shader.h"
#include "Renderer.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Shader::Shader(const std::string & filepath) : m_FilePath(filepath), m_RendererID(0)
{
    ShaderProgramSource source = parseShader(filepath); // The relative path is relative to the executable, not to the source code!
    m_RendererID = createShader(source.vertexSourceCode, source.fragmentSourceCode);
}

Shader::~Shader()
{
    CallGL(glDeleteProgram(m_RendererID));
}

void Shader::bind() const
{
    CallGL(glUseProgram(m_RendererID));
}

void Shader::unbind() const
{
    CallGL(glUseProgram(0));
}

void Shader::setUniform1f(const std::string & name, float value)
{
    CallGL(glUniform1f(getUniformLocation(name), value));
}

void Shader::setUniform4f(const std::string & name, float v0, float v1, float v2, float v3)
{
    CallGL(glUniform4f(getUniformLocation(name), v0, v1, v2, v3));
}

unsigned int Shader::getUniformLocation(const std::string & name)
{
    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
        return m_UniformLocationCache[name];

    CallGL(unsigned int location = glGetUniformLocation(m_RendererID, name.c_str()));
    if (location == -1) // 'location' can be '-1' if the uniform variable is not used
        std::cout << "Warning: uniform '" << name << "' does not exist!" << std::endl;
    m_UniformLocationCache[name] = location;
    return location;
}

ShaderProgramSource Shader::parseShader(const std::string & filePath)
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

unsigned int Shader::compileShader(unsigned int type, const std::string & source)
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
unsigned int Shader::createShader(const std::string & vertexShader, const std::string & fragmentShader)
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