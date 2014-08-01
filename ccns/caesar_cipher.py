#!/usr/bin/env python
import sys

alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'


def main():
    if len(sys.argv) < 4:
        print "Usage:", sys.argv[0], "<mode> <key> <message>"
        print "  <mode> can be 'encrypt'/'e' or 'decrypt'/'d'"
        print "  <key> is the encryption/decryption key"
        print "  <message> consisting of 26 alphabets. Case sensitive"
        sys.exit()
        
    key = int(sys.argv[2])
    mode = sys.argv[1]
    message = sys.argv[3]


    if mode == 'encrypt' or mode == 'e':
        for a in message:
            if a in alphabet:
                index = alphabet.index(a)
                index += key
                
                if index >= len(alphabet):
                    index -= len(alphabet)
                
                output = alphabet[index%26]
                sys.stdout.write(output)
                
    elif mode == 'decrypt' or mode == 'd':
        for a in message:
            if a in alphabet:
                index = alphabet.index(a)
                index -= key

                if index <= 0:
                    index += len(alphabet)
                
                output = alphabet[index%26]
                sys.stdout.write(output)
                
if __name__ == '__main__':
    main()
