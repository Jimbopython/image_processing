#pragma once

#include <image_processing/pixelformat.hpp>
#include <image_processing/pixelformat_traits.hpp>

namespace image_processing::types
{

template <Pixelformat p> class Image
{

  public:
    using Data = DataType_of_t<p> *;
    using cData = const DataType_of_t<p> *;

    Image() = default;
    Image(size_t width, size_t height) : m_width{width}, m_height{height}
    {
        if (width != 0 && height != 0)
        {
            m_data = std::make_unique<DataType_of_t<p>[]>(
                width * height * PixelformatInfo<p>::BytesPerPixel);
        }
    }

    [[nodiscard]] size_t width() const { return m_width; }
    [[nodiscard]] size_t height() const { return m_height; }
    [[nodiscard]] bool empty() const { return m_height == 0 || m_width == 0; }
    Data data() const { return m_data.get(); }

  private:
    size_t m_width{};
    size_t m_height{};
    std::unique_ptr<DataType_of_t<p>[]> m_data{};
};
} // namespace image_processing::types