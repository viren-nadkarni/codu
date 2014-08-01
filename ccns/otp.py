#!/usr/bin/env python
import sys
import random

alphabet = 'abcdefghijklmnopqrstuvwxyz'


def main():
    inp = sys.argv[1]
    
    key = []
    for i in range(len(inp)):
        key.append(int(random.random() * 100) % 26)
    
    print 'out: ',
    for a in range(len(inp)):
        sys.stdout.write(alphabet[(key[a] + alphabet.index(inp[a])) % 26])
    
    print 
    print 'key: ',
    
    for b in key:
        sys.stdout.write(alphabet[b])

    
if __name__ == '__main__':
    main()

