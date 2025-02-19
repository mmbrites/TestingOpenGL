#include "Texture.h"

#include "vendor/stb_image/stb_image.h"

Texture::Texture(const std::string & path) 
    : m_RendererID(0), m_FilePath(path), m_LocalBuffer(nullptr), m_Width(0), m_Height(0), m_BPP(0)
{
    stbi_set_flip_vertically_on_load(1); // Flips the texture upside down. OpenGL expects the first pixel to be the bottom-left corner of the image (remember that in OpenGL, the bottom-left is (0, 0)). Since in the case of the .png format, the image is stored as is displayed, we need to use this function to flip it. However, keep in mind that it varies with texture format.
    // Loads the image onto the buffer
    m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4); // '4' for RGBA - Red Green Blue Alpha

    CallGL(glGenTextures(1, &m_RendererID));
    CallGL(glBindTexture(GL_TEXTURE_2D , m_RendererID));

    // Set these 4 texture parameters, otherwise, you will obtain a black texture!
    CallGL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)); // GL_TEXTURE_MIN_FILTER controls how OpenGL samples a texture when it is shrunk (minified), meaning when a texture is displayed smaller than its original size (e.g., when a far-away object uses a high-resolution texture). GL_LINEAR is a texture filtering mode in OpenGL that performs bilinear interpolation to smooth out textures when sampling.
    CallGL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)); // GL_TEXTURE_MAG_FILTER controls how OpenGL magnifies a texture when it is scaled up (i.e., when a small texture covers many pixels on the screen). This happens when an object is close to the camera, and OpenGL needs to decide how to fill in the extra pixel details.
    CallGL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE)); // GL_TEXTURE_WRAP_S controls how a texture is wrapped (repeated or clamped) along the S (horizontal/X) axis when texture coordinates are outside the 0.0 - 1.0 range. This setting determines how OpenGL handles texture coordinate overflow. GL_CLAMP was an older texture wrapping mode in OpenGL, used to clamp texture coordinates to the range [0.0, 1.0]. It prevented textures from repeating but caused artifacts along the edges. Replaced by GL_CLAMP_TO_EDGE: This mode provides better results by clamping directly to the last valid texel.
    CallGL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE)); // // GL_TEXTURE_WRAP_T controls how a texture is wrapped (repeated or clamped) along the T (vertical/Y) axis when texture coordinates are outside the 0.0 - 1.0 range. This setting determines how OpenGL handles texture coordinate overflow.

    // Send buffer data to OpenGL
    CallGL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer)); // Specifies a 2D texture image. 'internalFormat' is how OpenGL stores your texture data, whereas 'format' is the format of the data you are providing OpenGL. Check documentation for more information regarding the parameters.
    CallGL(glBindTexture(GL_TEXTURE_2D, 0));

    if (m_LocalBuffer)
        stbi_image_free(m_LocalBuffer);
}

Texture::~Texture()
{
    CallGL(glDeleteTextures(1, &m_RendererID));
}

void Texture::bind(unsigned int slot /*= 0*/) const
{
    CallGL(glActiveTexture(GL_TEXTURE0 + slot)); // Activates a specific texture slot
    CallGL(glBindTexture(GL_TEXTURE_2D, m_RendererID));
}

void Texture::unbind() const
{
    CallGL(glBindTexture(GL_TEXTURE_2D, 0));
}