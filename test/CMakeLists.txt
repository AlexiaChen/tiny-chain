set(sources
tinychain_test.cpp
)

add_executable(tinychain_test ${sources})

target_link_libraries(tinychain_test
    Boost::unit_test_framework
)