#!/usr/bin/env python

import sys

    
def main():
    if len(sys.argv) < 4:
        print "Usage:", sys.argv[0], "<mode> <key> <input>"
        print "      <mode> can be 'encrypt'/'e' or 'decrypt'/'d'"
        print "      <key> is the encryption/decryption key"
        print "      <input> plaintext/ciphertext"
        sys.exit()
    
    mode = sys.argv[1]
    key = sys.argv[2]
    intxt = sys.argv[3]
    
    if len(intxt) % len(key) != 0:
        print 'incorrect keylength'
        sys.exit(1)
    
    #TODO key checking
    
    if mode == 'e' or mode == 'encrypt':
        m = i = 0
        while True:
            j = 0
            while j < len(key):
                if i == len(intxt):
                    sys.exit(0)
                sys.stdout.write(intxt[int(key[j]) + m - 1])
                j += 1
                i += 1 
            m += len(key) 
            
    if mode == 'd' or mode == 'decrypt':
        m = i = 0
        outtxt = []
        while True:
            j = 0
            while j < len(key):
                if i == len(intxt):
                    print ''.join(outtxt)
                    sys.exit(0)
                outtxt.insert(int(key[j]) + m - 1, intxt[i])
                j += 1
                i += 1
            m += len(key) 
    
if __name__ == '__main__':
    main()