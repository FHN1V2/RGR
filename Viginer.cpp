#include <iostream>
#include <string>
#include <cctype>

std::string encryptVigenere(const std::string& message, const std::string& key) {
    std::string encryptedMessage;
    int keyLength = key.length();
    int messageLength = message.length();

    for (int i = 0, j = 0; i < messageLength; ++i) {
        char currentChar = message[i];

        if (isalpha(currentChar)) {
            bool isUpperCase = isupper(currentChar);
            char baseChar = isUpperCase ? 'A' : 'a';
            char encryptedChar = ((currentChar - baseChar) + (toupper(key[j % keyLength]) - 'A')) % 26 + baseChar;
            encryptedMessage.push_back(encryptedChar);
            ++j;
        } else {
            encryptedMessage.push_back(currentChar);
        }
    }

    return encryptedMessage;
}

std::string decryptVigenere(const std::string& message, const std::string& key) {
    std::string decryptedMessage;
    int keyLength = key.length();
    int messageLength = message.length();

    for (int i = 0, j = 0; i < messageLength; ++i) {
        char currentChar = message[i];

        if (isalpha(currentChar)) {
            bool isUpperCase = isupper(currentChar);
            char baseChar = isUpperCase ? 'A' : 'a';
            char decryptedChar = ((currentChar - baseChar) - (toupper(key[j % keyLength]) - 'A') + 26) % 26 + baseChar;
            decryptedMessage.push_back(decryptedChar);
            ++j;
        } else {
            decryptedMessage.push_back(currentChar);
        }
    }

    return decryptedMessage;
}

int main() {
    std::string message = "Hello world! Привет мир!";
    std::string key = "secretkey";

    std::string encryptedMessage = encryptVigenere(message, key);
    std::string decryptedMessage = decryptVigenere(encryptedMessage, key);

    std::cout << "Original message: " << message << std::endl;
    std::cout << "Encrypted message: " << encryptedMessage << std::endl;
    std::cout << "Decrypted message: " << decryptedMessage << std::endl;

    return 0;
}
