#include <catch2/catch_test_macros.hpp>

#include <image_processing/image.hpp>

using namespace image_processing::types;

TEST_CASE("A size ", "[types]")
{
    SECTION("can calculate its area")
    {
        REQUIRE(Size{2,3}.area() == 6);
        REQUIRE(Size{0,0}.area() == 0);
        REQUIRE(Size{1,0}.area() == 0);
        REQUIRE(Size{0,1}.area() == 0);
    }
}