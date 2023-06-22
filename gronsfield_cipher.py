def gronfield_encryption(message, key):
    encrypted_message = ""
    key_length = len(key)
    key_index = 0

    for char in message:
        if char.isalpha():
            alphabet = 'абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФЧЦЧШЩЪЫЬЭЮЯabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
            alphabet_length = len(alphabet)
            char_index = alphabet.find(char)
            shifted_index = (char_index + int(key[key_index])) % alphabet_length
            encrypted_char = alphabet[shifted_index]
            encrypted_message += encrypted_char
            key_index = (key_index + 1) % key_length
        else:
            encrypted_message += char

    return encrypted_message


def gronsfield_decryption(encrypted_message, key):
    decrypted_message = ""
    key_length = len(key)
    key_index = 0

    for char in encrypted_message:
        if char.isalpha():
            alphabet = 'абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФЧЦЧШЩЪЫЬЭЮЯabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
            alphabet_length = len(alphabet)
            char_index = alphabet.find(char)
            shifted_index = (char_index - int(key[key_index])) % alphabet_length
            decrypted_char = alphabet[shifted_index]
            decrypted_message += decrypted_char
            key_index = (key_index + 1) % key_length
        else:
            decrypted_message += char

    return decrypted_message


