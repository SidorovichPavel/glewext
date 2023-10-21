#pragma once

#include <string_view>

#include <glewextlib/glewext_types.hpp>

namespace glewext
{

    class Shader
    {
    public:

        Shader(std::string_view vertex_shader, std::string_view fragment_shader);
        ~Shader();

        void use() const noexcept;

    private:

        unsigned int compileShader(const std::string& shaderCode, ShaderType type);

        unsigned int program_;
    };

}