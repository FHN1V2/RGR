
#include "vigener.h"


using namespace std;

void KeyIsWord(const string& key)
{
    for (char elem : key)
    {
        if (elem >= '1' && elem <= '9')
        {
            std::cerr << "Incorrect password, expected word, but entered: " << key <<std::endl;
            throw elem;

        }
    }
}

string vigener_encryption()
{
    setlocale(LC_ALL, "ru");
    string message;
    cout << "Enter massage: " << endl;
    cin.ignore();
    getline(cin, message);
    string key;
    cout << "Enter word key: ";
    cin >> key;
    try{
        KeyIsWord(key);
    }
    catch (char x){
        std::cout << "Enter word key for file: " ;
        std::cin >> key;
    }
    string shifr = "";
    for (int i = 0; i < message.length(); i++)
    {
        shifr += message[i] + key[i%(key.length())] - 'a';
    }
    return shifr;
}

string vigener_decryption(const string& shifr)
{
    string key;
    cout << "Enter word key: ";
    cin >> key;
    try{
        KeyIsWord(key);
    }
    catch (char x){
        std::cout << "Enter word key for file: " ;
        std::cin >> key;
    }
    string message = "";
    for (int i = 0; i < shifr.length(); i++)
    {
        message += shifr[i] - key[i%(key.length())] + 'a';
    }
    return message;
}
