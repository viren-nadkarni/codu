#!/usr/bin/env python

import math

x = [-3,  6,  0,  3, -6]
y = [ 1, -2,  0, -1,  2]

def mean(x):
    m = 0
    for i in x:
        m += i
    return m/float(len(x))

def covar(x, y):
    if len(x) != len(y): 
        raise AssertionError
    
    mx = mean(x)
    my = mean(y)
    
    print 'mean(x) =', mx
    print 'mean(y) =', my
    
    o = 0
    for i in zip(x, y):
        o += (i[0] - mx) * (i[1] - my)
    return o / (float(len(x)) - 1)

def std_dev(x):
    mx = mean(x)
    o = 0
    for i in x:
        o += (i - mx) ** 2
    return math.sqrt(o / (float(len(x)) - 1))

def main():
    cv = covar(x, y)
    print 'covariance(x, y) =', cv
    print 'correlation(x, y) =', cv / (std_dev(x) * std_dev(y))
    

if __name__ == '__main__':
    main()
