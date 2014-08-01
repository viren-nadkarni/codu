#!/usr/bin/env python
import sys
import numpy

# KEY = [[ 7,  8],
       # [11, 11]]

KEY = [[17, 17,  5],
       [21, 18, 21],
       [ 2,  2, 19]]

# KEY = [[2, 4, 5],
       # [9, 2, 1],
       # [3, 17, 7]]

CLUMP = len(KEY[0])
ALPHABET = 'abcdefghijklmnopqrstuvwxyz'


def index(char):
    return ALPHABET.index(char)
    
    
def numberize(text):
    return [index(text[i]) for i in range(len(text))]
    
    
def parse_text(text):
    if len(text) % CLUMP != 0:
        print 'assertion: text length should be factor of', CLUMP
        sys.exit()
    numb = numberize(text)
    lst = []
    for i in range(0, len(numb), CLUMP):
        tmp = []
        j = 0
        for j in range(CLUMP):
            tmp.append([numb[i + j]])
            #lst.append(numb[i : i + CLUMP])
        lst.append(tmp)
    return lst

    
def main():
    if len(sys.argv) < 2:
        print "Usage:", sys.argv[0], "<mode> <text>"
        print "      <mode> can be 'encrypt'/'e' or 'decrypt'/'d'"
        print "      <text> plain-text to be encrypted"
        sys.exit()

    leest = parse_text(sys.argv[2])
    mode = sys.argv[1]
    
    res = []
    
    if mode == 'encrypt' or mode == 'e':
        for i in leest:
            res.append(numpy.array(KEY).dot(numpy.array(i)))
        result = [i.tolist() for i in res]
        
    elif mode == 'decrypt' or mode == 'd':
        # broken
        print 'broken'
        sys.exit()
        
        for i in leest:
            res.append(numpy.linalg.inv(numpy.array(KEY)).dot(numpy.array(i)))
            
        result = [i.tolist() for i in res]
    
    for i in result:
        for j in i:
            for k in j:
                sys.stdout.write(ALPHABET[int(round(k)) % 26])

if __name__ == '__main__':
    main()