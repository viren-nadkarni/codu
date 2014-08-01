#!/usr/bin/env python

import numpy

data = [(0, 2), 
        (2, 0),
        (3, 1),
        (5, 1)]


def minkouski(x, y, r):
    sum = 0.0
    for a in zip(x, y):
        sum += abs(a[0] - a[1]) ** r
    return numpy.power(sum, 1/float(r))
    
    
def main():
    for z in range(1, 4):
        print 'L' + str(z), '\t',
        for i in range(len(data)):
            print 'P' + str(i + 1), '\t',
        print 
        
        for i in range(len(data)):
            print 'P' + str(i + 1), '\t',
            for j in range(len(data)):
                print '%5.3f\t' % minkouski(data[i], data[j], z),
            print
        print
    
if __name__ == '__main__':
    main()
