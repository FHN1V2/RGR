/*
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string generateKey(int length) {
    string key;
    srand(time(0));

    for (int i = 0; i < length; i++) {
        char randomChar = rand() % 128;  // Генерируем случайный символ (от 0 до 127)
        key += randomChar;
    }

    return key;
}

string encrypt(string plaintext, string key) {
    string ciphertext;

    for (int i = 0; i < plaintext.length(); i++) {
        char encryptedChar = plaintext[i] ^ key[i];  // Применяем операцию XOR между символами текста и ключа
        ciphertext += encryptedChar;
    }

    return ciphertext;
}

string decrypt(string ciphertext, string key) {
    string plaintext;

    for (int i = 0; i < ciphertext.length(); i++) {
        char decryptedChar = ciphertext[i] ^ key[i];  // Применяем операцию XOR между символами шифротекста и ключа
        plaintext += decryptedChar;
    }

    return plaintext;
}

int main() {
    string plaintext;
    cout << "Введите текст для шифрования: ";
    getline(cin, plaintext);

    int length = plaintext.length();
    string key = generateKey(length);  // Генерируем ключ той же длины, что и входной текст

    string ciphertext = encrypt(plaintext, key);  // Шифруем текст
    cout << "Зашифрованный текст: " << ciphertext << endl;

    string decryptedText = decrypt(ciphertext, key);  // Дешифруем текст
    cout << "Расшифрованный текст: " << decryptedText << endl;

    return 0;
}
*/

/*
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string generateKey(int length) {
    string key;
    srand(time(0));

    for (int i = 0; i < length; i++) {
        char randomChar = rand() % 128;  // Генерируем случайный символ (от 0 до 127)
        key += randomChar;
    }

    return key;
}

string encrypt(const string& plaintext, const string& key) {
    string ciphertext;
    vector<char> encryptedChars;

    for (int i = 0; i < plaintext.length(); i++) {
        char encryptedChar = plaintext[i] ^ key[i];  // Применяем операцию XOR между символами текста и ключа
        encryptedChars.push_back(encryptedChar);
    }

    ciphertext.assign(encryptedChars.begin(), encryptedChars.end());
    return ciphertext;
}

string decrypt(const string& ciphertext, const string& key) {
    string plaintext;
    vector<char> decryptedChars;

    for (int i = 0; i < ciphertext.length(); i++) {
        char decryptedChar = ciphertext[i] ^ key[i];  // Применяем операцию XOR между символами шифротекста и ключа
        decryptedChars.push_back(decryptedChar);
    }

    plaintext.assign(decryptedChars.begin(), decryptedChars.end());
    return plaintext;
}

int main() {
    string plaintext;
    setlocale (LC_ALL, "Rus");
    cout << "Введите текст для шифрования: ";
    getline(cin, plaintext);

    int length = plaintext.length();
    string key = generateKey(length);  // Генерируем ключ той же длины, что и входной текст

    string ciphertext = encrypt(plaintext, key);  // Шифруем текст
    cout << "Зашифрованный текст: " << ciphertext << endl;

    string decryptedText = decrypt(ciphertext, key);  // Дешифруем текст
    cout << "Расшифрованный текст: " << decryptedText << endl;

    return 0;
}
*/


//Шифр Вермана 

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
//#include <locale>
//#include <clocale> //setlocale()
//#include <Windows.h>
//#include <conio.h>
//#include <CTYPE.H>
//#include <stdio.h>

using namespace std;

//генерация случайного ключа заданной длины
string generateKey(int lenght) 
{
    string key; //инциализация строки, которая будет представлять собой ключ
    srand(time(0));

    for(int i=0; i<lenght; i++)
    {
        char randomChar = rand()%128; //генерация случайного символа
        key+=randomChar; //добавление сгенирированного сивола к ключу
    }
    return key; //возвращает сгенерированный ключ
}

//шифрование переданного текста при помощи ключа
string encrypt(const string& originalText, const string& key)
{
    string cipherText; //иициализация строки, которая будет представлять зашифрованный текст
    vector<char> encryptedChars; //инициализация вектора, содержащего символы зашифрованного текста

    for(int i=0; i<originalText.length(); i++) //цикл для шифрования символов текста
    {
        char encryptedChars = originalText[i]^key[i]; //шифрование текущего символа текста с помощью соответствующего символа из ключа
        encryptedChars.push_back(encryptedChar); //добавление зашифрованного символа в вектор
    }
    cipherText.assign(encryptedChars.begin(), encryptedChars.end()); //преобразование вектора символов зашифрованного текста в строку
    return cipherText; 
}

//расшифровывание переданного зашифрованного текста при помощи ключа
string decrypt(const string& cipherText, const string& key)
{
    string originalText;
    vector<char> decryptedChars; //инициализация вектора, содержащего символы расшифрованного текста

    for(int i=0; i<cipherText.length(); i++) //цикл для расшифровки символов текста
    {
        char decryptedChar = cipherText[i]^key[i]; //расшифрование текущего символа текста с помощью соответствующего символа из ключа
        decryptedChars.push_back(decryptedChar); //добавление расшифрованного символа в вектор
    }
    originalText.assign(decryptedChars.begin(), decryptedChars.end());  //преобразование вектора символов расшифрованного текста в строку
    return originalText; //возвращаем расшифрованный текст
}

int main()
{
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    string originalText;
    cout<<"Введите текст для шифрования: ";
    getline(cin, originalText); //ввод текста для шифрования

    int lenght = originalText.length(); //длина введённого текста
    string key = generateKey(lenght); //генерация ключа такой же длины, что и введённый текст

    string cipherText = encrypt(originalText, key); //шифрование текста
    cout<<"Зашифрованный текст: "<<cipherText<<endl; //вывод зашифрованного текста

    string decryptedText = decrypt(cipherText, key); //расшифрование текста
    cout<<"Расшифрованный текст: "<<decryptedText<<endl;

    return 0;
}


/*
#include <iostream>
#include <vector>
#include <string>

std::wstring Vigenere(const std::wstring &text, const std::wstring &key, bool encrypt)
{
    std::wstring result;
    int keyIndex = 0;

    for (size_t i = 0; i < text.length(); i++)
    {
        wchar_t letter = text[i];

        if (letter >= L'A' && letter <= L'Z')
        {
            letter += L'a' - L'A';
        }
        else if (letter < L'А' || letter > L'Я')
        {
            continue;
        }

        wchar_t keyLetter = key[keyIndex];
        if (keyLetter >= L'A' && keyLetter <= L'Z')
        {
            keyLetter += L'a' - L'A';
        }
        else if (keyLetter < L'А' || keyLetter > L'Я')
        {
            continue;
        }

        wchar_t newLetter;
        if (encrypt)
        {
            newLetter = (letter + keyLetter) % 32;
        }
        else
        {
            newLetter = (letter - keyLetter + 32) % 32;
        }

        if (letter >= L'a' && letter <= L'z')
        {
            newLetter += L'A' - L'a';
        }
        else
        {
            newLetter += L'А';
        }
        result += newLetter;

        keyIndex++;
        if (keyIndex == key.length())
        {
            keyIndex = 0;
        }
    }
    return result;
}

int main()
{
    std::wstring text = L"Вернам"; // текст для шифрования
    std::wstring key = L"Ключ"; // ключ шифрования

    std::cout << "Исходный текст: " << text << std::endl;

    std::wstring encryptedText = Vigenere(text, key, true);
    std::cout << "Зашифрованный текст: " << encryptedText << std::endl;

    std::wstring decryptedText = Vigenere(encryptedText, key, false);
    std::cout << "Расшифрованный текст: " << decryptedText << std::endl;

    return 0;
}
*/




















/*
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

string generateKey(int length)
{
    string key;
    srand(time(0));

    for(int i = 0; i < length; i++)
    {
        char randomChar = rand() % 128;
        key += randomChar;
    }
    return key;
}

string encrypt(const string& originalText, const string& key)
{
    string cipherText;
    vector<char> encryptedChars;

    for(int i = 0; i < originalText.length(); i++)
    {
        char encryptedChar = originalText[i] ^ key[i];
        encryptedChars.push_back(encryptedChar);
    }
    cipherText.assign(encryptedChars.begin(), encryptedChars.end());
    return cipherText;
}

string decrypt(const string& cipherText, const string& key)
{
    string originalText;
    vector<char> decryptedChars;

    for(int i = 0; i < cipherText.length(); i++)
    {
        char decryptedChar = cipherText[i] ^ key[i];
        decryptedChars.push_back(decryptedChar);
    }
    originalText.assign(decryptedChars.begin(), decryptedChars.end());
    return originalText;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    string originalText;
    cout << "Введите текст для шифрования: ";
    getline(cin, originalText);

    int length = originalText.length();
    string key = generateKey(length);

    string cipherText = encrypt(originalText, key);
    cout << "Зашифрованный текст: " << cipherText << endl;

    string decryptedText = decrypt(cipherText, key);
    cout << "Расшифрованный текст: " << decryptedText << endl;

    return 0;
}
*/










