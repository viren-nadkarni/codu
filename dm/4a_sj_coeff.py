#!/usr/bin/env python

import re

# a = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0]
# b = [0, 0, 0, 0, 0, 0, 0, 1, 0, 1]

def main():    
    f = open('4_dataset.txt', 'r')
    x = f.readlines()
    
    for line in x:
        if re.match('a={(.*)}', line):
            a = re.match('a={(.*)}', line).group(1).split(',')
        elif re.match('b={(.*)}', line):
            b = re.match('b={(.*)}', line).group(1).split(',')
    
    f00 = f01 = f10 = f11 = 0
    print 'a =', [ int(i) for i in a ]
    print 'b =', [ int(i) for i in b ]
    
    for i in zip(a, b):
        if i == ('0', '0'):
            f00 += 1
        if i == ('0', '1'):
            f01 += 1
        if i == ('1', '0'):
            f10 += 1
        if i == ('1', '1'):
            f11 += 1
    
    print 'Similarity Coeff =', float(f00 + f11)/(f00 + f01 + f10 + f11)
    print 'Jaccard Coeff =', f11/float(f01 + f10 + f11)

    
if __name__ == '__main__':
    main()
