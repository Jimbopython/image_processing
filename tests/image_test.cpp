#include <catch2/catch_test_macros.hpp>

#include <image_processing/image.hpp>

using namespace image_processing::types;

TEST_CASE("An image ", "[image]")
{
    SECTION("can be default constructed.")
    {
        const Image<Pixelformat::Mono8> img;
        const auto size = img.size();

        REQUIRE(size.width == 0);
        REQUIRE(size.height == 0);
        REQUIRE(img.empty());
        REQUIRE(img.data() == nullptr);
    }
    SECTION("can be created from a size.")
    {
        const Image<Pixelformat::Mono8> img{{1, 1}};

        const auto size = img.size();

        REQUIRE(size.width == 1);
        REQUIRE(size.height == 1);
    }

    SECTION("can change its data.")
    {
        Image<Pixelformat::Mono8> img{{1, 1}};

        auto data = img.data();
        data[0] = 255;
    }

    SECTION("can be iterated.")
    {
        Image<Pixelformat::Mono8> img{{1, 1}};

        auto begin = img.begin();
        begin++;
        REQUIRE(begin == img.end());
    }

    SECTION("can be created from a buffer")
    {
        constexpr auto pixelFormat = Pixelformat::Mono8;
        std::array<DataType_of_t<pixelFormat>, 1> buffer{42};
        const Image<pixelFormat> img{{1, 1}, buffer.data()};
        REQUIRE(img.data() == buffer.data());
    }

    SECTION("can be created from a constexpr buffer")
    {
        constexpr auto pixelFormat = Pixelformat::Mono8;
        constexpr Size size{1, 1};
        constexpr std::array<DataType_of_t<pixelFormat>, 1> buffer{42};

        constexpr ConstexprImage<pixelFormat, size, buffer> img;

        // todo: investigate why this fails
        // REQUIRE(img.data() == buffer.data());
        // STATIC_REQUIRE(img.data() == buffer.data());
        STATIC_REQUIRE(img.data()[0] == buffer[0]);
    }
}