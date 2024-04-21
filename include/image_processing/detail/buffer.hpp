#pragma once

#include <cstdint>
#include <memory>

#include <image_processing/pixelformat.hpp>
#include <image_processing/pixelformat_traits.hpp>
#include <image_processing/size.hpp>

namespace image_processing::types::detail
{
class IBuffer
{
  public:
    virtual ~IBuffer() = default;
    [[nodiscard]] virtual uint8_t *data() const = 0;
};

template <Pixelformat p> class UniquePtrBuffer : public IBuffer
{
  public:
    explicit UniquePtrBuffer(Area area)
    {
        if (area != 0)
        {
            m_data = std::make_unique<uint8_t[]>(
                area * PixelformatInfo<p>::BytesPerPixel);
        }
    }
    [[nodiscard]] uint8_t *data() const override { return m_data.get(); }

  private:
    std::unique_ptr<uint8_t[]> m_data{};
};

class RawPointerBuffer : public IBuffer
{
  public:
    explicit RawPointerBuffer(uint8_t *data) : m_data{data} {}
    [[nodiscard]] uint8_t *data() const override { return m_data; }

  private:
    uint8_t *m_data{};
};

template <Pixelformat p> std::unique_ptr<IBuffer> createBuffer(Area area)
{
    return std::make_unique<UniquePtrBuffer<p>>(area);
}

template <Pixelformat> std::unique_ptr<IBuffer> createBuffer(uint8_t *data)
{
    return std::make_unique<RawPointerBuffer>(data);
}
} // namespace image_processing::types::detail