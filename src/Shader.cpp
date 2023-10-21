#include <fstream>
#include <algorithm>
#include <iterator>
#include <stdexcept>

#include <GL/glew.h>

#include <glewextlib/Shader.hpp>

namespace glewext
{

    Shader::Shader(std::string_view vertex_shader, std::string_view fragment_shader)
        : program_(0)
    {
        std::string vertex_code;
        std::string fragment_code;

        std::ifstream vert_shader_file(vertex_shader.data());
        std::ifstream frag_shader_file(fragment_shader.data());

        std::copy(std::istreambuf_iterator<char>(vert_shader_file), {}, std::back_inserter(vertex_code));
        std::copy(std::istreambuf_iterator<char>(frag_shader_file), {}, std::back_inserter(fragment_code));

        auto vertex = compileShader(vertex_code, ShaderType::Vertex);
        auto fragment = compileShader(fragment_code, ShaderType::Fragment);

        program_ = glCreateProgram();
        glAttachShader(program_, vertex);
        glAttachShader(program_, fragment);
        glLinkProgram(program_);

        GLint success;
        glGetProgramiv(program_, GL_LINK_STATUS, &success);
        if (!success)
        {
            char log[512];
            glGetProgramInfoLog(program_, sizeof(log), nullptr, log);
            std::string excpt_data("glewext::link program error::");
            excpt_data += log;
            throw std::runtime_error(excpt_data.c_str());
        }

        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    unsigned int Shader::compileShader(const std::string& shaderCode, ShaderType type)
    {
        const char* shaderCodeCStr = shaderCode.c_str();

        auto shader = glCreateShader(static_cast<GLenum>(type));
        glShaderSource(shader, 1, &shaderCodeCStr, nullptr);
        glCompileShader(shader);

        int success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            char log[512];
            glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
            std::string excpt_data("glewext::compile shader error::");
            excpt_data += log;
            throw std::runtime_error(excpt_data.c_str());
        }

        return shader;
    }

    Shader::~Shader()
    {
        glDeleteProgram(program_);
    }

    void Shader::use() const noexcept
    {
        glUseProgram(program_);
    }
}