def atbash_cipher(text):
    result = ""
    alphabet_ru = 'абвгдежзийклмнопрстуфхцчшщъыьэюяАБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ'
    alphabet_en = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
    
    for char in text:
        if char.isalpha():
            if char in alphabet_ru:
                char = alphabet_ru[::-1][alphabet_ru.index(char)]
            elif char in alphabet_en:
                char = alphabet_en[::-1][alphabet_en.index(char)]
        result += char
    return result

# Пример использования
text = "Пример текста Example Text"
text =str(input())
encrypted_text = atbash_cipher(text)
decrypted_text = atbash_cipher(encrypted_text)

print("Исходный текст:", text)
print("Зашифрованный текст:", encrypted_text)
print("Расшифрованный текст:", decrypted_text)

