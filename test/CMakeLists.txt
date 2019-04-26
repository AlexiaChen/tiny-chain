set(dep_src
../src/crypto/crypto.h ../src/crypto/crypto.cpp
../src/crypto/sha256.h ../src/crypto/sha256.cpp
)

set(sources
tinychain_test.cpp
)

add_executable(tinychain_test ${sources} ${dep_src})

target_link_libraries(tinychain_test
    Boost::unit_test_framework
)