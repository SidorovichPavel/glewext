#pragma once

#include <stdexcept>
#include <exception>

namespace glewext
{

    class Exception : public std::exception {
    public:
        Exception(const std::string& message);

        const char* what() const noexcept override;

    private:
        std::string message_;
    };

}