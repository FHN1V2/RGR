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
