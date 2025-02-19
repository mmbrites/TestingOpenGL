#pragma once

#include "Renderer.h"

class Texture
{
    private:
        unsigned int m_RendererID;
        std::string m_FilePath;
        unsigned char * m_LocalBuffer;
        int m_Width, m_Height, m_BPP; // BPP = bits per pixel

    public:
        Texture(const std::string & path);
        ~Texture();

        void bind(unsigned int slot = 0) const; // If the parameter 'slot' is not specified, it will be '0'. It represents texture slots - there is a finite number
        void unbind() const;
        
        inline int getWidth() const { return m_Width; }
        inline int getHeight() const { return m_Height; }
};