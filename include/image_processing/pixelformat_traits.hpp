#pragma once

#include <cstdint>

namespace image_processing::types
{
namespace detail
{

template <Pixelformat p> struct DataType_of;

template <> struct DataType_of<Pixelformat::Mono8>
{
    using type = uint8_t;
};
} // namespace detail

template <Pixelformat p>
using DataType_of_t = typename detail::DataType_of<p>::type;

template <Pixelformat p> struct PixelformatInfo;

template <> struct PixelformatInfo<Pixelformat::Mono8>
{
    static constexpr size_t BytesPerPixel = 1;
};
} // namespace image_processing::types