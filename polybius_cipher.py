def create_polybius_square():
    alphabet = 'фбвгдежзийклмнопрстуфхцчшщъыьэюяabcdefghiklmnoprstuvwxyz.,:;!?@#$%^&*()_+0123456789'
    square_size = int(len(alphabet) ** 0.5) + 1
    square = []
    row = []
    for char in alphabet:
        row.append(char)
        if len(row) == square_size:
            square.append(row)
            row = []
    return square


def polibius_encryption(message):
    message = message.lower()
    square = create_polybius_square()
    encrypted_message = ''
    for char in message:
        if char == ' ':
            encrypted_message += ' '
            continue
        for i in range(len(square)):
            for j in range(len(square[i])):
                if char == square[i][j]:
                    encrypted_message += str(i) + str(j)
                    break

    return encrypted_message


def polybius_decryption(encrypted_message):
    square = create_polybius_square()
    decrypted_message = ''
    i = 0
    while i < len(encrypted_message):
        if encrypted_message[i] == ' ':
            decrypted_message += ' '
            i += 1
            continue
        row = int(encrypted_message[i])
        col = int(encrypted_message[i + 1])
        if row < 0 or col < 0 or row >= len(square) or col >= len(square[row]):
            decrypted_message += ' '
        else:
            decrypted_message += square[row][col]
        i += 2
    return decrypted_message


