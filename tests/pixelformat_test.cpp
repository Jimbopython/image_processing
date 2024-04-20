#include <catch2/catch_test_macros.hpp>
#include <image_processing/pixelformat.hpp>

#include <image_processing/pixelformat_traits.hpp>

using namespace image_processing::types;

TEST_CASE("A Pixelformat ", "[pixelformat]")
{
    SECTION("with mono8 has correct pixelformat info")
    {
        STATIC_REQUIRE(PixelformatInfo<Pixelformat::Mono8>::BytesPerPixel == 1);
    }
}