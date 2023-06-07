#include "AtbashCipher.h"

void atbashEncrypt(string& message) {
    for (char& c : message) {
        if (isalpha(c)) {
            if (islower(c)) {
                c = 'a' + ('z' - c);
            } else {
                c = 'A' + ('Z' - c);
            }
        }
    }
}

void atbashDecrypt(string& encryptedMessage) {
    for (char& c : encryptedMessage) {
        if (isalpha(c)) {
            if (islower(c)) {
                c = 'a' + ('z' - c);
            } else {
                c = 'A' + ('Z' - c);
            }
        }
    }
}
