#pragma once

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
    explicit Image(Size size) : m_size{size}
    {
        if (size.area().value != 0)
        {
            const auto area = m_size.area();
            m_data = std::make_unique<DataType_of_t<p>[]>(area.value);
        }
    }

    [[nodiscard]] Size size() const { return m_size; }
    [[nodiscard]] bool empty() const { return m_size.area() == 0; }

    Data data() const { return m_data.get(); }

    Data begin() const { return data(); }
    Data end() const { return data() + m_size.area().value; }

  private:
    Size m_size{};
    std::unique_ptr<DataType_of_t<p>[]> m_data{};
};
} // namespace image_processing::types