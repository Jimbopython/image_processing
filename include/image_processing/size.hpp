#pragma once

#include <cstddef>

namespace image_processing::types
{

struct Area
{
    size_t value;
    friend bool operator==(const Area &lhs, size_t otherValue)
    {
        return lhs.value == otherValue;
    }
    friend bool operator!=(const Area &lhs, size_t otherValue)
    {
        return !(lhs == otherValue);
    }
};

struct Size
{
    size_t width;
    size_t height;

    [[nodiscard]] Area area() const { return Area{width * height}; }
};
} // namespace image_processing::types