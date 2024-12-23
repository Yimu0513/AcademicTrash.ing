def xor_encrypt(input_text, key):
    result = []  

    for i, char in enumerate(input_text):
        key_char = key[i % len(key)]

        modified_ascii = ord(char) + 13
        xor_value = modified_ascii ^ ord(key_char)
        result.append(xor_value)

    return result


flag = ""
key = "CuzCTF"


ciphertexti = xor_encrypt(flag, key)
#ciphertext=[19, 247, 253, 19, 53, 21, 203, 21, 6, 47, 213, 51, 53, 245, 22, 53, 212, 42, 38, 41, 37, 201]
