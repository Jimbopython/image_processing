Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.5.4
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests
        image_test.cpp
        pixelformat_test.cpp
        size_test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain image_processing)