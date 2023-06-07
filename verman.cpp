
//Шифр Вермана 

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

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
        encryptedChars.push_back(encryptedChars); //добавление зашифрованного символа в вектор
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






