def xor_encription(message, key):
    encrypted_message = ""
    key_length = len(key)
    
    for i, char in enumerate(message):
        key_char = key[i % key_length]  # Получаем символ ключа для текущего символа сообщения
        encrypted_char = chr(ord(char) ^ ord(key_char))  # XOR-шифрование символа
        
        encrypted_message += encrypted_char
    
    return encrypted_message


def xor_description(encrypted_message, key):
    decrypted_message = xor_encription(encrypted_message, key)  # Дешифруем зашифрованное сообщение, используя XOR-шифр
    
    return decrypted_message



