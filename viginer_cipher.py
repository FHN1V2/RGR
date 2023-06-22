def viginer_encryption(message, key):
    shifr = ""
    for i in range(len(message)):
        shifr += chr(ord(message[i]) + ord(key[i % len(key)]) - ord('a'))
    return shifr

def viginer_decryption(shifr, key):
    message = ""
    for i in range(len(shifr)):
        message += chr(ord(shifr[i]) - ord(key[i % len(key)]) + ord('a'))
    return message
