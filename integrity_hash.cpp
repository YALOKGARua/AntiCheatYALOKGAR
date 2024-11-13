#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

bool check_file_hash() {
    std::ifstream file("important_file.dat", std::ios::binary);
    if (!file.is_open()) {
        return false;
    }

    SHA256_CTX sha256_ctx;
    SHA256_Init(&sha256_ctx);

    char buffer[1024];
    while (file.read(buffer, sizeof(buffer))) {
        SHA256_Update(&sha256_ctx, buffer, sizeof(buffer));
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_Final(hash, &sha256_ctx);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }

    std::string file_hash = ss.str();
    std::string expected_hash = "your_expected_hash_here";

    return file_hash == expected_hash;
}