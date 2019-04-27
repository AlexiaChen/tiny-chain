#include "crypto.h"
#include "sha256.h"
#include "base58.h"

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

void Crypto::CryptoHash(const std::string& source, std::vector<uint8_t>& hash)
{
    Crypto::CryptoHash(std::vector<uint8_t>(source.begin(), source.end()), hash);
}


void Crypto::CryptoEncodeBase58(const std::vector<uint8_t>& source, std::string& base58)
{
    base58 = EncodeBase58(std::vector<unsigned char>(source.begin(), source.end()));
}

bool Crypto::CryptoDecodeBase58(const std::string& base58, std::vector<uint8_t>& source)
{
    return DecodeBase58(base58, source);
}

}