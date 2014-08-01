#!/usr/bin/env python
import sys

DUMMY = 'x'
ALPHABET = 'abcdefghiklmnopqrstuvwxyz'


def eliminate_duplicates(keyword):
    flags = [0 for i in range(26)]

    for i in ALPHABET:
        if i in keyword:
            c = keyword.count(i)
            flags[ALPHABET.index(i)] = 1

    _keyword = ''

    for j in keyword:
        if flags[ALPHABET.index(j)] == 1:
            flags[ALPHABET.index(j)] = 0
            _keyword += j

    return _keyword


def index(matrix, letter):
    for i in range(5):
        for j in range(5):
            if matrix[i][j] == letter:
                return i, j
    print '\ncannot find \'' + letter + '\' in matrix'
    for i in range(5):
        print matrix[i]
    print 'exiting'
    sys.exit()


def gen_matrix(keyword):
    matrix = [['' for j in range(5)] for i in range(5)]
    _keyword = eliminate_duplicates(keyword)

    k = 0
    l = 0

    for i in range(5):
        for j in range(5):
            if k < len(_keyword):
                matrix[i][j] = _keyword[k]
                k += 1
            else:
                while ALPHABET[l] in _keyword:
                    l += 1
                matrix[i][j] = ALPHABET[l]
                l += 1

    return matrix


def parse_plaintext(plaintext):
    for i in range(1, len(plaintext)):
        if plaintext[i - 1] == plaintext[i]:
            plaintext = plaintext[:i] + DUMMY + plaintext[i:]

    if len(plaintext) % 2 == 1:
        plaintext += DUMMY

    return plaintext
    

def main():
    if len(sys.argv) < 4:
        print "Usage:", sys.argv[0], "<mode> <key> <text>"
        print "      <mode> can be 'encrypt'/'e' or 'decrypt'/'d'"
        print "      <key> is the encryption/decryption key"
        print "      <text> is the plain-text/cipher-text"
        sys.exit()

    mode = sys.argv[1]
    key = sys.argv[2]
    plaintext = parse_plaintext(sys.argv[3])
    ciphertext = sys.argv[3]

    matrix = gen_matrix(key)

    if mode == 'encrypt' or mode == 'e':
        ciphertext = ''
        
        for i in range(0, len(plaintext), 2):
            a, b = index(matrix, plaintext[i])
            c, d = index(matrix, plaintext[i + 1])
            
            if a == c:                    # in same row
                if b + 1 > 4:
                    b = -1
                ciphertext += matrix[a][b + 1]
                if c + 1 > 4:
                    c = -1
                ciphertext += matrix[c][d + 1]
                
            elif b == d:                  # in same column
                if a + 1 > 4:
                    a = -1
                ciphertext += matrix[a + 1][a]
                if c + 1 > 4:
                    c = -1
                ciphertext += matrix[c + 1][d]
            else:
                ciphertext += matrix[a][d]
                ciphertext += matrix[c][b]
        print ciphertext

    elif mode == 'decrypt' or mode == 'd':
        # TODO
        # broken
        #print 'broken'
        #sys.exit()
        
        plaintext = ''
        
        for i in range(0, len(ciphertext), 2):
            a, b = index(matrix, ciphertext[i])
            c, d = index(matrix, ciphertext[i + 1])
            
            if a == c:
                if b - 1 < 0:
                    b = 4
                plaintext += matrix[a][b - 1]
                if c - 1 < 0:
                    c = 4
                plaintext += matrix[c][d - 1]
                
            elif b == d:
                if a - 1 < 0:
                    a = 4
                plaintext += matrix[a - 1][a]
                if c - 1 < 0:
                    c = 4
                plaintext += matrix[c - 1][d]
            else:
                plaintext += matrix[a][d]
                plaintext += matrix[c][b]
        print plaintext


if __name__ == '__main__':
    main()
