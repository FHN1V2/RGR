#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string encryptMessage(const std::string& message, const std::string& codeword)
{
    std::string alphabet = "abcdefghjklmnoprstuvwxyz";
    std::string encryptedMessage = message;

    std::string uniqueCodeword = codeword;
    uniqueCodeword.erase(std::unique(uniqueCodeword.begin(), uniqueCodeword.end()), uniqueCodeword.end());

    std::transform(uniqueCodeword.begin(), uniqueCodeword.end(), uniqueCodeword.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    std::transform(encryptedMessage.begin(), encryptedMessage.end(), encryptedMessage.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    std::string shiftedAlphabet = uniqueCodeword + alphabet;
    shiftedAlphabet.erase(std::remove_if(shiftedAlphabet.begin(), shiftedAlphabet.end(), [&uniqueCodeword](char c) {
        return uniqueCodeword.find(std::tolower(c)) != std::string::npos;
    }), shiftedAlphabet.end());

    for (char& c : encryptedMessage)
    {
        if (isalpha(c))
        {
            if (islower(c))
            {
                c = shiftedAlphabet[c - 'a'];
            }
            else if (isupper(c))
            {
                c = shiftedAlphabet[c - 'A'];
            }
        }
    }

    return encryptedMessage;
}

std::string decryptMessage(const std::string& encryptedMessage, const std::string& codeword)
{
    std::string alphabet = "abcdefghjklmnoprstuvwxyz";
    std::string decryptedMessage = encryptedMessage;

    std::string uniqueCodeword = codeword;
    uniqueCodeword.erase(std::unique(uniqueCodeword.begin(), uniqueCodeword.end()), uniqueCodeword.end());

    std::transform(uniqueCodeword.begin(), uniqueCodeword.end(), uniqueCodeword.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    std::string shiftedAlphabet = uniqueCodeword + alphabet;
    shiftedAlphabet.erase(std::remove_if(shiftedAlphabet.begin(), shiftedAlphabet.end(), [&uniqueCodeword](char c) {
        return uniqueCodeword.find(std::tolower(c)) != std::string::npos;
    }), shiftedAlphabet.end());

    for (char& c : decryptedMessage)
    {
        if (isalpha(c))
        {
            if (islower(c))
            {
                c = alphabet[shiftedAlphabet.find(c)];
            }
            else if (isupper(c))
            {
                c = std::toupper(alphabet[shiftedAlphabet.find(std::tolower(c))]);
            }
        }
    }

    return decryptedMessage;
}


int main()
{
    std::string message = "Nastya Jopka";
    std::string codeword = "Pipka";

    std::string encryptedMessage = encryptMessage(message, codeword);
    std::string decryptedMessage = decryptMessage(encryptedMessage, codeword);

    std::cout << "Зашифрованное сообщение: " << encryptedMessage << std::endl;
    std::cout << "Дешифрованное сообщение: " << decryptedMessage << std::endl;

    return 0;
}
