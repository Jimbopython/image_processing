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
}