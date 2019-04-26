#ifndef CRYPTO_H
#define CRYPTO_H

#include <vector>
#include <cstdint>

namespace crypto {

class Crypto
{
public:
    static void CryptoHash(const std::vector<uint8_t>& source, std::vector<uint8_t>& hash);
};

}
#endif