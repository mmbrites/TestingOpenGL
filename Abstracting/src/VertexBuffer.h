#pragma once

class VertexBuffer
{

    private:
        unsigned int m_RendererID; // ID for every vertex buffer created
    public:
        VertexBuffer(const void * data, unsigned int size);
        ~VertexBuffer();

        void bind() const;
        void unbind() const;

};