#include <stdexcept>

#include <glewextlib/glewext.hpp>

namespace glewext
{
    void init()
    {
        if (glewInit() != GLEW_OK)
            throw std::runtime_error("glewextlib::GLEW init failed. Make sure that glcontext is enabled");
    }


}