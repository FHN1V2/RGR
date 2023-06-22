from viginer_cipher import viginer_encryption, viginer_decryption
from atbash_cipher import atbash_cipher
from gronsfield_cipher import gronfield_encryption, gronsfield_decryption
from polybius_cipher import polibius_encryption, polybius_decryption
from vernam_cipher import vernam_cipher
from xor_cipher import xor_encription, xor_description

def write_file_content(message):
    fileName=input("Enter file name ")
    f=open(f"{fileName}.txt",'w')
    for index in message:
        f.write(index)



def read_file_content():
        fileName=input("Enter file name ")
        with open(f'{fileName}.txt', 'r') as file:
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
                    print("Encrypted message:", viginer_encryption(message, key))

                elif action_choice == 2:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                        key = input("Enter the key: ")
                    else:
                        message =read_file_content()
                
                        key = input("Enter the key: ")
                    print("Decrypted message:", viginer_decryption(message, key))

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
                    print("Encrypted message:", atbash_cipher(message))

                elif action_choice == 2:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                    # key = input("Enter the key: ")
                    else:
                        message =read_file_content()
                    #message = input("Enter the decryption message: ")
                    print("Decrypted message:", atbash_cipher(message))

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
                    print("Encrypted message:", gronfield_encryption(message, key))

                elif action_choice == 2:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                        key = input("Enter the key: ")
                    else:
                        message =read_file_content()
                    #message = input("Enter the decryption message: ")
                        key = input("Enter the key: ")
                    print("Decrypted message:", gronsfield_decryption(message, key))
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
                    print("Encrypted message:", vernam_cipher(message,key))

                elif action_choice == 2:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                        key = input("Enter the key: ")
                    else:
                        message =read_file_content()
                    #message = input("Enter the decryption message: ")
                        key = input("Enter the key: ")
                    print("Decrypted message:", vernam_cipher(message,key))


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
                    #message = input("Enter the encryption message: ")
                        #key = input("Enter the key: ")
                    print("Encrypted message:", polibius_encryption(message))
                elif action_choice == 2:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                        #key = input("Enter the key: ")
                    else:
                        message =read_file_content()
                # message = input("Enter the decryption message: ")
                    print("Decrypted message:", polybius_decryption(message))

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
                    print("Encrypted message:", xor_encription(message,key))

                elif action_choice == 2:
                    method=Method_input()
                    if method==False:
                        message = input("Enter the encryption message: ")
                        key = input("Enter the key: ")
                    else:
                        message =read_file_content()
                    #message = input("Enter the decryption message: ")
                        key = input("Enter the key: ")
                    print("Decrypted message:", xor_description(message,key))

            elif method_choice == 0:
                print("The program is completed.")
                break

            else:
                print("Incorrect choice. Try again.")
else:
    print("Wrong password")
