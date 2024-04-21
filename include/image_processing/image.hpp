#pragma once

#include <image_processing/detail/buffer.hpp>
#include <image_processing/pixelformat.hpp>
#include <image_processing/pixelformat_traits.hpp>
#include <image_processing/size.hpp>

namespace image_processing::types
{

template <Pixelformat p> class Image
{
  public:
    using Data = DataType_of_t<p> *;
    using cData = const DataType_of_t<p> *;

    Image() = default;
    explicit Image(Size size)
        : m_size{size}, m_buffer(detail::createBuffer<p>(size.area()))
    {
    }
    Image(Size size, Data data)
        : m_size{size}, m_buffer{detail::createBuffer<p>(data)}
    {
    }

    [[nodiscard]] Size size() const { return m_size; }
    [[nodiscard]] bool empty() const { return m_size.area() == 0; }

    Data data() const
    {
        if (!m_buffer)
        {
            return nullptr;
        }
        return m_buffer->data();
    }

    Data begin() const { return data(); }
    Data end() const { return data() + m_size.area().value; }

  private:
    Size m_size{};
    std::unique_ptr<detail::IBuffer> m_buffer{};
};
} // namespace image_processing::types