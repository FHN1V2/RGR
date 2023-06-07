#include "VigenereCipher.h"

void encryptVigenere(std::string& message, const std::string& key) {
    int keyLength = key.length();
    int messageLength = message.length();

    for (int i = 0; i < messageLength; ++i) {
        char c = message[i];
        char keyChar = key[i % keyLength];

        if (std::isalpha(c)) {
            if (std::islower(c)) {
                c = 'a' + (c - 'a' + (keyChar - 'a')) % 26;
            } else {
                c = 'A' + (c - 'A' + (keyChar - 'A')) % 26;
            }
        }

        message[i] = c;
    }
}

void decryptVigenere(std::string& message, const std::string& key) {
    int keyLength = key.length();
    int messageLength = message.length();

    for (int i = 0; i < messageLength; ++i) {
        char c = message[i];
        char keyChar = key[i % keyLength];

        if (std::isalpha(c)) {
            if (std::islower(c)) {
                c = 'a' + (c - 'a' - (keyChar - 'a') + 26) % 26;
            } else {
                c = 'A' + (c - 'A' - (keyChar - 'A') + 26) % 26;
            }
        }

        message[i] = c;
    }
}
