#include <iostream>
#include <fstream>
#include <windows.h>
#include <wincrypt.h>
#include <openssl/sha.h>


void encryptFile(const std::string& filename)
{
    std::ifstream inputFile(filename, std::ios::binary);
    if (!inputFile)
    {
        std::cerr << "Failed to open File" << std::endl;
        return;
    }


    SHA_CTX ctx;
    SHA1_Init(&ctx);

    char buffer[4096];
    while (inputFile.read(buffer, sizeof(buffer)))
    {
        SHA1_Update(&ctx, buffer, inputFile.gcount());
    }

    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1_Final(hash, &ctx);

    inputFile.close();

    std::string encryptedFilename = filename + ".encrypted";

    std::ofstream outputFile(encryptedFilename, std::ios::binary);
    if (!outputFile)
    {
    
        return;
    }

    outputFile.write(reinterpret_cast<const char*>(hash), SHA_DIGEST_LENGTH);

    outputFile.close();
}



int main()
{

    encryptFile("test.txt");

    return 0;
}
