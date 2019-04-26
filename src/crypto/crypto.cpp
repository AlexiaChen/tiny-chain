#include "crypto.h"
#include "sha256.h"

#include <algorithm>

namespace crypto{

void Crypto::CryptoHash(const std::vector<uint8_t>& source, std::vector<uint8_t>& hash)
{
    SHA256_CTX ctx = {0};
    sha256_init(&ctx);
    sha256_update(&ctx, source.data(), source.size());
    uint8_t buffer[SHA256_BLOCK_SIZE] = {0};
    sha256_final(&ctx, buffer);
    if(hash.size() > 0) hash.clear();
    std::copy_n(buffer, SHA256_BLOCK_SIZE, std::back_inserter(hash));
}

}