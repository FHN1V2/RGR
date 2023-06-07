#include <iostream>
#include "vigener.h"
#include "AtbashCipher.h"

using namespace std;

void showEncryptionMethods() {
    cout << "=== Выберите метод шифрования ===" << endl;
    cout << "1. Шифр Виженера" << endl;
    cout << "2. Шифр Атбаш" << endl;
    cout << "0. Выход" << endl;
    cout << "Введите номер метода шифрования: ";
}

void showEncryptionActions() {
    cout << "=== Выберите действие ===" << endl;
    cout << "1. Зашифровать сообщение" << endl;
    cout << "2. Расшифровать сообщение" << endl;
    cout << "0. Вернуться к выбору метода шифрования" << endl;
    cout << "Введите номер действия: ";
}

int main() {
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
                        cout << "Введите сообщение для шифрования: ";
                        cin.ignore();
                        getline(cin, message);

                        cout << "Введите ключ: ";
                        cin >> key;

                        vigener_encryption(message, key);
                        cout << "Зашифрованное сообщение: " << message << endl;
                        break;

                    case 2:
                        cout << "Введите сообщение для расшифровки: ";
                        cin.ignore();
                        getline(cin, message);

                        cout << "Введите ключ: ";
                        cin >> key;

                        vigener_decryption(message, key);
                        cout << "Расшифрованное сообщение: " << message << endl;
                        break;

                    case 0:
                        break;

                    default:
                        cout << "Некорректный выбор. Попробуйте снова." << endl;
                }

                break;
            }

            case 2: {  // Шифр Атбаш
                showEncryptionActions();
                cin >> actionChoice;

                switch (actionChoice) {
                    case 1:
                        cout << "Введите сообщение для шифрования: ";
                        cin.ignore();
                        getline(cin, message);

                        atbashEncrypt(message);
                        cout << "Зашифрованное сообщение: " << message << endl;
                        break;

                    case 2:
                        cout << "Введите сообщение для расшифровки: ";
                        cin.ignore();
                        getline(cin, message);

                        atbashDecrypt(message);
                        cout << "Расшифрованное сообщение: " << message << endl;
                        break;

                    case 0:
                        break;

                    default:
                        cout << "Некорректный выбор. Попробуйте снова." << endl;
                }

                break;
            }

            case 0:
                cout << "Программа завершена." << endl;
                return 0;

            default:
                cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    }

    return 0;
}
