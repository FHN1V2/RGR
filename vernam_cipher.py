def vernam_cipher(message, key):
    # Преобразование сообщения и ключа в числовой формат
    message_nums = [ord(char) for char in message]
    key_nums = [ord(char) for char in key]

    # Проверка, что длина ключа соответствует длине сообщения
    if len(message_nums) != len(key_nums):
        raise ValueError("Длины сообщения и ключа должны быть одинаковыми.")

    # Шифрование или расшифрование сообщения с использованием шифра Вернама
    result_nums = []
    for i in range(len(message_nums)):
        # Операция XOR между символами сообщения и ключа
        result_nums.append(message_nums[i] ^ key_nums[i])

    # Преобразование числового результата обратно в символы
    result = ''.join(chr(num) for num in result_nums)

    return result
