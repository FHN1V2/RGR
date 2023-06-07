
#include "viginer.h"

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

string viginer_encryption(string &message,string key)
{   string shifr = "";
    for (int i = 0; i < message.length(); i++)
    {
        shifr += message[i] + key[i%(key.length())] - 'a';
    }
    return shifr;
}

string viginer_decryption(const string& shifr,string key)
{
    string message = "";
    for (int i = 0; i < shifr.length(); i++)
    {
        message += shifr[i] - key[i%(key.length())] + 'a';
    }
    return message;
}
