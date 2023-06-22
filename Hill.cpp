#include <iostream>
#include <vector>

// Функция для преобразования символа в его числовое значение
int charToNum(char c) {
    if (isalpha(c)) {
        if (islower(c))
            return c - 'a';
        else
            return c - 'A';
    } else {
        return -1; // Возвращаем -1, если символ не является буквой
    }
}

// Функция для преобразования числового значения в символ
char numToChar(int n) {
    if (n >= 0 && n < 26)
        return 'a' + n;
    else if (n >= 26 && n < 52)
        return 'A' + (n - 26);
    else
        return ' '; // Возвращаем пробел, если значение не попадает в диапазон
}

// Функция для шифрования текста с помощью шифра Хилла
std::string encryptHill(const std::string& plaintext, const std::vector<std::vector<int>>& key) {
    std::string ciphertext = "";
    int keySize = key.size();

    for (int i = 0; i < plaintext.length(); i += keySize) {
        std::vector<int> block;
        for (int j = 0; j < keySize; j++) {
            int num = charToNum(plaintext[i + j]);
            if (num != -1)
                block.push_back(num);
        }

        if (block.size() == keySize) {
            for (int j = 0; j < keySize; j++) {
                int sum = 0;
                for (int k = 0; k < keySize; k++) {
                    sum += key[j][k] * block[k];
                }
                sum %= 26;
                ciphertext += numToChar(sum);
            }
        }
    }

    return ciphertext;
}

// Функция для расшифрования текста с помощью шифра Хилла
std::string decryptHill(const std::string& ciphertext, const std::vector<std::vector<int>>& key) {
    std::string plaintext = "";
    int keySize = key.size();
    int determinant = key[0][0] * key[1][1] - key[0][1] * key[1][0];

    // Вычисление обратного определителя по модулю 26
    int inverseDet = -1;
    for (int i = 0; i < 26; i++) {
        if ((determinant * i) % 26 == 1) {
            inverseDet = i;
            break;
        }
    }

    //if (inverseDet == -1) {
       // std::cout << "It is impossible to decrypt the text, the key determinant has no inverse modulo 26." << std::endl;
        //return plaintext;
    //}

    // Вычисление обратной матрицы
    std::vector<std::vector<int>> inverseKey(keySize, std::vector<int>(keySize));
    inverseKey[0][0] = (inverseDet * key[1][1]) % 26;
    inverseKey[0][1] = (inverseDet * -key[0][1] + 26) % 26;
    inverseKey[1][0] = (inverseDet * -key[1][0] + 26) % 26;
    inverseKey[1][1] = (inverseDet * key[0][0]) % 26;

    for (int i = 0; i < ciphertext.length(); i += keySize) {
        std::vector<int> block;
        for (int j = 0; j < keySize; j++) {
            int num = charToNum(ciphertext[i + j]);
            if (num != -1)
                block.push_back(num);
        }

        if (block.size() == keySize) {
            for (int j = 0; j < keySize; j++) {
                int sum = 0;
                for (int k = 0; k < keySize; k++) {
                    sum += inverseKey[j][k] * block[k];
                }
                sum %= 26;
                plaintext += numToChar(sum);
            }
        }
    }

    return plaintext;
}

int main() {
    std::vector<std::vector<int>> key = {{6, 24}, {13, 16}}; // Пример ключа размером 2x2

    std::string plaintext = "Hello, World!"; // Пример исходного текста
    std::string ciphertext = encryptHill(plaintext, key);
    std::cout << "Encrypted text: " << ciphertext << std::endl;

    std::string decryptedText = decryptHill(ciphertext, key);
    std::cout << "Decrypted text: " << decryptedText << std::endl;

    return 0;
}
