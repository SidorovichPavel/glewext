

#include <GL/glew.h>

#include <glewextlib/Texture.hpp>

namespace glewext
{
    Texture::Texture()
        :
        texture_id_(0u),
        width_(0),
        height_(0)
    {
        glGenTextures(1, &texture_id_);
    }

    Texture::~Texture()
    {
        if (texture_id_ != 0) {
            glDeleteTextures(1, &texture_id_);
        }
    }

    void Texture::load_texture(const char* imagePath)
    {
        glBindTexture(GL_TEXTURE_2D, texture_id_);

        //TODO

        width_ = 1;
        height_ = 1;
        unsigned char data[4] = { 255, 0, 0, 255 }; // Красный цвет

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width_, height_, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

        glGenerateMipmap(GL_TEXTURE_2D);
    }


    void Texture::load_image_from_memory(TextureLevel level, TextureInternalFormat internal_format,
        int width, int height, TextureBorder border, TextureFormat format, GLType gl_type, const void* data)
    {
        width_ = width;
        height_ = height;
        glBindTexture(GL_TEXTURE_2D, texture_id_);

        glTexImage2D(GL_TEXTURE_2D, static_cast<int>(level), static_cast<int>(internal_format),
            width_, height_, static_cast<int>(border), static_cast<int>(format), static_cast<int>(gl_type), data);

        glGenerateMipmap(GL_TEXTURE_2D);
    }

    void Texture::set_texture_parameters()
    {
        glBindTexture(GL_TEXTURE_2D, texture_id_);

        // Устанавливаем параметры фильтрации
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // Устанавливаем параметры повторения текстуры
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }

    // Метод для привязки текстуры к конкретному текстурному юниту
    void Texture::bind(TextureUnit unit)
    {
        glActiveTexture(GL_TEXTURE0 + static_cast<int>(unit));
        glBindTexture(GL_TEXTURE_2D, texture_id_);
    }

    //Unbind texture
    void Texture::unbind()
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}