#ifndef CRYPTO_H
#define CRYPTO_H

#include <vector>
#include <cstdint>
#include <string>

namespace crypto {

class Crypto
{
public:
    static void CryptoHash(const std::vector<uint8_t>& source, std::vector<uint8_t>& hash);
    static void CryptoHash(const std::string& source, std::vector<uint8_t>& hash);
};

class uint256
{
public:
    explicit uint256(const std::vector<uint8_t>& hash) 
    : hash_(hash)
    {}
    uint256(){}
    ~uint256(){}
    std::string ToString() const
    {
        static const char *hexmap = "0123456789abcdef";
        std::string s(hash_.size() * 2, ' ');
        for (std::size_t i = 0; i < hash_.size(); ++i) 
        {
            s[2 * i]     = hexmap[(hash_[i] & 0xF0) >> 4];
            s[2 * i + 1] = hexmap[hash_[i] & 0x0F];
        } 
        return s;
    }
    std::vector<uint8_t> data() const
    {
        return hash_;
    }
private:
    std::vector<uint8_t> hash_;
};

}
#endif