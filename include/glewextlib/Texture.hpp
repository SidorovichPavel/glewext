#pragma once

#include <cstdint>
#include <string_view>

#include <glewextlib/glewext_types.hpp>

namespace glewext
{
    class Texture {
    public:

        Texture();
        ~Texture();

        // load image from file to texture
        void load_texture(const char* imagePath);

        //load from memory
        void load_image_from_memory(TextureLevel level, TextureInternalFormat internal_format,
            int width, int height, TextureBorder border, TextureFormat format, GLType gl_type, const void* data);

        // Set texture params
        void set_texture_parameters(); // TODO:

        // Bind texture to unit
        void bind(TextureUnit unit);
        static void unbind();

    private:
        uint32_t texture_id_;
        int width_, height_;
    };
}