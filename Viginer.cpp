#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

//Функция для шифрования текста методом Виженера
string encryptVigenere(const string& plaintext, const string& keyword) {
    string ciphertext;
    int keyLength = keyword.length();
    int textLength = plaintext.length();

    for (int i = 0; i < textLength; i++) {
        char plainChar = plaintext[i];
        char keyChar = keyword[i % keyLength];
        char encryptedChar = ' ';

        if (isalpha(plainChar)) { //проверка, является ли символ буквой
            if (islower(plainChar)) //если буква в нижнем регистре
                encryptedChar = ((plainChar - 'a') + (tolower(keyChar) - 'a')) % 26 + 'a'; //шифрование с учётом ключевого символа
            else if (isupper(plainChar)) //если буква в верхнем регистре
                encryptedChar = ((plainChar - 'A') + (toupper(keyChar) - 'A')) % 26 + 'A'; //шифрование с учётом ключевого символа
        } else {
            encryptedChar = plainChar; //если символ не является буквой, оставляем его без изменений
        }

        ciphertext.push_back(encryptedChar); //добавление зашифрованного символа в строку шифротекста
    }

    return ciphertext; //возвращает зашифрованный текст
}
//Функция для дешифрования текста методом Виженера 
string decryptVigenere(const string& ciphertext, const string& keyword) {
    string plaintext;
    int keyLength = keyword.length();//длинна ключа
    int textLength = ciphertext.length();//длинна сообщения

    for (int i = 0; i < textLength; i++) {
        char cipherChar = ciphertext[i];
        char keyChar = keyword[i % keyLength];
        char decryptedChar = ' ';

        if (isalpha(cipherChar)) { //проверка, является ли символ буквой
            if (islower(cipherChar)) //если буква в нижнем регистре 
                decryptedChar = ((cipherChar - 'a') - (tolower(keyChar) - 'a') + 26) % 26 + 'a'; //дешифрование с учётом ключевого символа
            else if (isupper(cipherChar)) //если буква в верхнем регистре
                decryptedChar = ((cipherChar - 'A') - (toupper(keyChar) - 'A') + 26) % 26 + 'A'; //дешифрование с учётом ключевого символа
        } else {
            decryptedChar = cipherChar; //если символ не является буквой, оставляем его без изменений
        }

        plaintext.push_back(decryptedChar); //добавление расшифрованного символа в строку исходного текста
    }

    return plaintext; //возвращает расшифрованный текст
}
//Функция для получения результатов шифрования и дешифрования 
vector<string> getResults(const string& plaintext, const string& keyword) {
    vector<string> results; //создание вектора строк
    string encryptedText = encryptVigenere(plaintext, keyword);
    string decryptedText = decryptVigenere(encryptedText, keyword);

    results.push_back("Plaintext: " + plaintext);
    results.push_back("Keyword: " + keyword);
    results.push_back("Encrypted Text: " + encryptedText);
    results.push_back("Decrypted Text: " + decryptedText);

    return results;
}

int main() {
    string plaintext = "";
    string keyword = "";
    cout<<"Введите ключ состоящий только из символов: "<<endl;
    cin>>keyword;
    cout<<"Введите сообщение:"<<endl;
    //cin>>plaintext;
    cin.ignore();
    getline(cin, plaintext);
    vector<string> results = getResults(plaintext, keyword); //получение результатов шифрования и дешифрования 

    for (const string& result : results) {
        cout << result << endl;
    }
    return 0;
}
