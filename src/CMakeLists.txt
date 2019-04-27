set(sources
main.cpp
)

set(crypto_src
crypto/sha256.h
crypto/sha256.cpp
crypto/base58.h
crypto/base58.cpp
crypto/crypto.h
crypto/crypto.cpp
)

add_executable(tinychain ${sources} ${crypto_src})