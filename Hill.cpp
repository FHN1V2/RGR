#include <iostream>
#include <vector>

using namespace std;

//Функция для выполнения модулярной арифметики (обрабатывает отрицательные числа корректно)
int mod(int a, int b) {
    return (a % b + b) % b;
}

//Функция для умножения матрицы на вектор
vector<int> multiplyMatrixVector(const vector<vector<int>>& matrix, const vector<int>& inputVector) {
    int n = matrix.size();
    vector<int> result(n, 0);

//Выполнение умножение матрицы на вектор
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i] += matrix[i][j] * inputVector[j];
        }
        result[i] = mod(result[i], 256);
    }

    return result; 
}

//Функция для шифрования блока текста (шифрует блок текста block с использованием матрицы ключа keyMatrix и возвращает зашифрованный результат в виде строки)
string encryptBlock(const vector<vector<int>>& keyMatrix, const string& block) {
    int n = keyMatrix.size();
    vector<int> inputVector(n);

//Преобразования каждого символа в блоке в числовое значение (ASCII-код)
    for (int i = 0; i < n; i++) {
        inputVector[i] = static_cast<int>(block[i]); //преобразования типа символов в блоке текста в числовые значения (ASCII-коды) и наоборот
    }

    vector<int> encrypted = multiplyMatrixVector(keyMatrix, inputVector);

    string result;
    for (int i = 0; i < n; i++) {
        result += static_cast<char>(encrypted[i]);
    }

    return result;
}

//Функция для дешифрования блока текста (дешифрует блок текста block, используя матрицу ключа keyMatrix, и возвращает результат дешифрации в виде строки)
string decryptBlock(const vector<vector<int>>& keyMatrix, const string& block) {
    int n = keyMatrix.size();
    vector<int> inputVector(n);

//Преобразуем каждый символ в блоке в числовое значение (ASCII-код)
    for (int i = 0; i < n; i++) {
        inputVector[i] = static_cast<int>(block[i]);
    }

    //Вычисляем обратную матрицу ключа
    int determinant = (keyMatrix[0][0] * keyMatrix[1][1]) - (keyMatrix[0][1] * keyMatrix[1][0]);
    int multiplicativeInverse = 0;

    for (int i = 0; i < 256; i++) {
        int temp = (determinant * i) % 256;
        if (temp == 1) {
            multiplicativeInverse = i;
            break;
        }
    }

    vector<vector<int>> inverseMatrix(n, vector<int>(n));

    inverseMatrix[0][0] = mod((keyMatrix[1][1] * multiplicativeInverse), 256);
    inverseMatrix[0][1] = mod((-keyMatrix[0][1] * multiplicativeInverse), 256);
    inverseMatrix[1][0] = mod((-keyMatrix[1][0] * multiplicativeInverse), 256);
    inverseMatrix[1][1] = mod((keyMatrix[0][0] * multiplicativeInverse), 256);

    vector<int> decryptedVector = multiplyMatrixVector(inverseMatrix, inputVector);

    string result;
    for (int i = 0; i < n; i++) {
        result += static_cast<char>(mod(decryptedVector[i], 256));
    }

    return result;
}

int main() {
    string originalText = "HELLO";
    vector<vector<int>> keyMatrix = { { 3, 2 }, { 1, 4 } };

    //Шифрование
    string encrypted = encryptBlock(keyMatrix, originalText);
    cout << "Encrypted message: " << encrypted << endl;

    //Дешифрование
    string decrypted = decryptBlock(keyMatrix, encrypted);
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
