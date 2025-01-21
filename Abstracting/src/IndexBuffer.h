#pragma once

class IndexBuffer
{

    private:
        unsigned int m_RendererID; // ID for every vertex buffer created
        unsigned int m_Count; // Number of indices
    public:
        IndexBuffer(const unsigned int * data, unsigned int count); // Supporting 32-bit data and how many indices were supplied
        ~IndexBuffer();

        void bind() const;
        void unbind() const;

        inline unsigned int getCount() const { return m_Count; };

};