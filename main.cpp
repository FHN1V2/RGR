#include <iostream>
#include <windows.h>
#include "viginer.h"
#include "AtbashCipher.h"
using namespace std;

void showEncryptionMethods() {
    cout << "=== Method ===" << endl;
    cout << "1. Viginer" << endl;
    cout << "2. Atbash" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter the number of the encryption method: ";
}

void showEncryptionActions() {
    cout << "=== Select an action ===" << endl;
    cout << "1. Encrypt the message" << endl;
    cout << "2. Decrypt the message" << endl;
    cout << "0. Go back to choosing the encryption method" << endl;
    cout << "Enter the action number: ";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int methodChoice;
    int actionChoice;
    string message;
    string key;
    int shift;

    while (true) {
        showEncryptionMethods();
        cin >> methodChoice;

        switch (methodChoice) {
            
            case 1: {  // Шифр Виженера
                showEncryptionActions();
                cin >> actionChoice;

                switch (actionChoice) {
                    case 1:
                        cout << "Enter the encryption message: ";
                        cin.ignore();
                        getline(cin, message);

                        cout << "Enter the key: ";
                        cin >> key;

                        
                        cout << "Encrypted message: " << viginer_encryption(message,key) << endl;
                        break;

                    case 2:
                        cout << "Enter the decryption message: ";
                        cin.ignore();
                        getline(cin, message);

                        cout << "Enter the key: ";
                        cin >> key;

                       
                        cout << "Decrypted message: " <<  viginer_decryption(message,key) << endl;
                        break;

                    case 0:
                        break;

                    default:
                        cout << "Incorrect choice. Try again." << endl;
                }

                break;
            }

            case 2: {  // Шифр Атбаш
                showEncryptionActions();
                cin >> actionChoice;

                switch (actionChoice) {
                    case 1:
                        cout << "Enter the encryption message: ";
                        cin.ignore();
                        getline(cin, message);

                        atbashEncrypt(message);
                        cout << "Encrypted message: "<<message  << endl;
                        break;

                    case 2:
                        cout << "Enter the decryption message: ";
                        cin.ignore();
                        getline(cin, message);

                        atbashDecrypt(message);
                        cout << "Decrypted message: " << message << endl;
                        break;

                    case 0:
                        break;

                    default:
                        cout << "Incorrect choice. Try again." << endl;
                }

                break;
            }

            case 0:
                cout << "The program is completed." << endl;
                return 0;

            default:
                cout << "Incorrect choice. Try again." << endl;
        }
    }

    return 0;
}
