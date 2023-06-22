from viginer_cipher import viginer_decryption,viginer_encryption
from atbash_cipher import atbash_cipher
from gronsfield_cipher import gronfield_encryption, gronsfield_decryption
from polybius_cipher import polibius_encryption, polybius_decryption
from vernam_cipher import vernam_cipher
from xor_cipher import xor_encription, xor_description

def write_output(message):
    #print (message)
    fileName = input("Enter output file name: ")
    with open(f"{fileName}.txt", "w",encoding='utf-8') as file:
        file.write(message)



def read_file_content():
    fileName = input("Enter file name: ")
    with open(f'{fileName}.txt', 'r',encoding='utf-8') as file:
        text = file.read()
    return text


def Method_input():
    print("1. from file ")
    print ("2. from keyboard ")
    make=int(input())
    if make ==1:
        return True
    else:
        return False
    

def Method_output():
    print ("1. To file")
    print ("2. To console")
    make=int(input())
    if make ==1:
        return True
    else:
        return False



def show_encryption_methods():
    print("=== Method ===")
    print("1. Viginer")
    print("2. Atbash")
    print("3. Gronsfield")
    print("4. Vernam")
    print("5. Polybius")
    print ("6. Xor")
    print("0. Exit")
    print("Enter the number of the encryption method: ")


def show_encryption_actions():
    print("=== Select an action ===")
    print("1. Encrypt the message")
    print("2. Decrypt the message")
    print("0. Go back to choosing the encryption method")
    print("Enter the action number: ")

UserPass=input("Enter you password(nstu): ")
if UserPass=="nstu":
    print("Welcome ")
    while True:
        
            
            show_encryption_methods()
            method_choice = int(input())

            if method_choice == 1:  # Viginer Cipher
                show_encryption_actions()
                action_choice = int(input())

                if action_choice == 1:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                        key = input("Enter the key: ")
                    else:
                        message =read_file_content()
                        key = input("Enter the key: ")
                    method=Method_output()
                    if method ==False:
                        print("Encrypted message:", viginer_encryption(message, key))
                    else:
                        write_output(viginer_encryption(message, key))

                elif action_choice == 2:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                        key = input("Enter the key: ")
                    else:
                        message =read_file_content()
                
                        key = input("Enter the key: ")
                    method=Method_output()
                    if method ==False:
                        print("Decrypteded message:", viginer_decryption(message, key))
                    else:
                        write_output(viginer_encryption(message, key))

                elif action_choice == 0:
                    pass

                else:
                    print("Incorrect choice. Try again.")

            elif method_choice == 2:  # Atbash Cipher
                show_encryption_actions()
                action_choice = int(input())

                if action_choice == 1:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                        #key = input("Enter the key: ")
                    else:
                        message =read_file_content()
                    method=Method_output()
                    if method ==False:
                        print("Encrypted message:", atbash_cipher(message))
                    else:
                        write_output(atbash_cipher(message))

                elif action_choice == 2:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                    else:
                        message =read_file_content()
                    method=Method_output()
                    if method ==False:
                        print("Decrypted message:", atbash_cipher(message))
                    else:
                        write_output(atbash_cipher(message))

                elif action_choice == 0:
                    pass
            elif method_choice == 3:  # Gronsfield Cipher
                show_encryption_actions()
                action_choice = int(input())

                if action_choice == 1:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                        key = input("Enter the key: ")
                    else:
                        message =read_file_content()
                    #message = input("Enter the encryption message: ")
                        key = input("Enter the key: ")
                    method=Method_output()
                    if method ==False:
                        print("Encrypted message:", gronfield_encryption(message, key))
                    else:
                        write_output(gronfield_encryption(message, key))

                elif action_choice == 2:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                        key = input("Enter the key: ")
                    else:
                        message =read_file_content()
                    #message = input("Enter the decryption message: ")
                        key = input("Enter the key: ")
                    method=Method_output()
                    if method ==False:
                        print("Decrypted message:", gronsfield_decryption(message, key))
                    else:
                        write_output(gronsfield_decryption(message, key))


            elif method_choice == 4:  # Vernam Cipher
                show_encryption_actions()
                action_choice = int(input())
                if action_choice == 1:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                        key = input("Enter the key: ")
                    else:
                        message =read_file_content()
                # message = input("Enter the encryption message: ")
                        key = input("Enter the key: ")
                    method=Method_output()
                    if method ==False:
                        print("Encrypted message:", vernam_cipher(message, key))
                    else:
                        write_output(vernam_cipher(message, key))

                elif action_choice == 2:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                        key = input("Enter the key: ")
                    else:
                        message =read_file_content()
                    #message = input("Enter the decryption message: ")
                        key = input("Enter the key: ")
                    method=Method_output()
                    if method ==False:
                        print("Decrypted message:", vernam_cipher(message, key))
                    else:
                        write_output(vernam_cipher(message, key))


                elif action_choice == 0:
                    pass
                else:
                    print("Incorrect choice. Try again.")
            elif method_choice == 5:  # Polybius Cipher
                show_encryption_actions()
                action_choice = int(input())
                if action_choice == 1:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                        #key = input("Enter the key: ")
                    else:
                        message =read_file_content()
                    method=Method_output()
                    if method ==False:
                        print("Encrypted message:", polibius_encryption(message))
                    else:
                        write_output(polibius_encryption(message))

                elif action_choice == 2:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                        #key = input("Enter the key: ")
                    else:
                        message =read_file_content()
                # message = input("Enter the decryption message: ")
                    method=Method_output()
                    if method ==False:
                        print("Decrypted message:", polybius_decryption(message))
                    else:
                        write_output(polybius_decryption(message))

                elif action_choice == 0:
                    pass
            elif method_choice == 6:  # Xor Cipher
                show_encryption_actions()
                action_choice = int(input())
                if action_choice == 1:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                        key = input("Enter the key: ")
                    else:
                        message =read_file_content()
                #message = input("Enter the encryption message: ")
                        key = input("Enter the key: ")
                    method=Method_output()
                    if method ==False:
                        print("Encrypted message:", xor_encription(message, key))
                    else:
                        write_output(xor_encription(message, key))

                elif action_choice == 2:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                        key = input("Enter the key: ")
                    else:
                        message =read_file_content()
                    #message = input("Enter the decryption message: ")
                        key = input("Enter the key: ")
                    method=Method_output()
                    if method ==False:
                        print("Decrypted message:", xor_description(message, key))
                    else:
                        write_output(xor_description(message, key))

            elif method_choice == 0:
                print("The program is completed.")
                break

            else:
                print("Incorrect choice. Try again.")
else:
    print("Wrong password")
