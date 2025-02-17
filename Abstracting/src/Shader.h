#pragma once

#include <string>
#include <unordered_map>

struct ShaderProgramSource
{
    std::string vertexSourceCode;
    std::string fragmentSourceCode;
};

class Shader
{
    private:
        std::string m_FilePath; // For debugging purposes
        unsigned int m_RendererID;
        std::unordered_map<std::string, int> m_UniformLocationCache;
    
    public:
        Shader(const std::string & filepath);
        ~Shader();

        void bind() const;
        void unbind() const;

        void setUniform1f(const std::string & name, float value);
        // Set uniforms - this is a tutorial, so we are assuming that every 'uniform' is a vec4 of floats. In a real world scenario, we could parse the shader source code and obtain the data types of the 'uniform' variables.
        void setUniform4f(const std::string & name, float v0, float v1, float v2, float v3);
    
    private:
        ShaderProgramSource parseShader(const std::string & filePath);
        unsigned int compileShader(unsigned int type, const std::string & source);
        unsigned int createShader(const std::string & vertexShader, const std::string & fragmentShader);
        unsigned int getUniformLocation(const std::string & name);
};