
// Шифр Вернама

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <windows.h>

using namespace std;

// генерация случайного ключа заданной длины
string generateKey(int lenght)
{
    string key; // инциализация строки, которая будет представлять собой ключ
    srand(time(0));

    for (int i = 0; i < lenght; i++)
    {
        char randomChar = rand() % 128; // генерация случайного символа
        key += randomChar;              // добавление сгенирированного сивола к ключу
    }
    return key; // возвращает сгенерированный ключ
}

// шифрование переданного текста при помощи ключа
string encrypt( string &originalText, const string &key)
{
    string cipherText;           // иициализация строки, которая будет представлять зашифрованный текст
    vector<char> encryptedChars; // инициализация вектора, содержащего символы зашифрованного текста

    for (int i = 0; i < originalText.length(); i++) // цикл для шифрования символов текста
    {
        char encryptedChar = originalText[i] ^ key[i]; // шифрование текущего символа текста с помощью соответствующего символа из ключа

        encryptedChars.push_back(encryptedChar); // добавление зашифрованного символа в вектор
    }
    cipherText.assign(encryptedChars.begin(), encryptedChars.end()); // преобразование вектора символов зашифрованного текста в строку
    return cipherText;
}

// расшифровывание переданного зашифрованного текста при помощи ключа
string decrypt( string &cipherText, const string &key)
{
    string originalText;
    vector<char> decryptedChars; // инициализация вектора, содержащего символы расшифрованного текста

    for (int i = 0; i < cipherText.length(); i++) // цикл для расшифровки символов текста
    {
        char decryptedChar = cipherText[i] ^ key[i]; // расшифрование текущего символа текста с помощью соответствующего символа из ключа
        decryptedChars.push_back(decryptedChar);     // добавление расшифрованного символа в вектор
    }
    originalText.assign(decryptedChars.begin(), decryptedChars.end()); // преобразование вектора символов расшифрованного текста в строку
    return originalText;                                               // возвращаем расшифрованный текст
}
