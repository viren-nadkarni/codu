#!/usr/bin/env python
import sys

ALPHABET = 'abcdefghijklmnopqrstuvwxyz'


def main():
    if len(sys.argv) < 2:
        print "Usage:", sys.argv[0], "<mode> <key> <text>"
        print "      <mode> can be 'encrypt'/'e' or 'decrypt'/'d'"
        print "      <key> is the encryption/decryption key"
        print "      <text> text to be processed"
        sys.exit()

    mode = sys.argv[1]
    key = sys.argv[2]
    input = sys.argv[3]
       
    output = ''
    s = 0
    if mode == 'encrypt' or mode == 'e':
        for a in input:
            output += ALPHABET[(ALPHABET.index(a) + key.index(key[s % len(key)])) % 26]
            s += 1
    elif mode == 'decrypt' or mode == 'd':
        for a in input:
            output += ALPHABET[(ALPHABET.index(a) - key.index(key[s % len(key)])) % 26]
            s += 1

    print output


if __name__ == '__main__':
    main()