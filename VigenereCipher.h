#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include <string>

void encryptVigenere(std::string& message, const std::string& key);
void decryptVigenere(std::string& message, const std::string& key);

#endif  // VIGENERECIPHER_H
