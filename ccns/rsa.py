#!/usr/bin/python

def main():
    choice = 0
    while choice != 4:
        choice = \
            input("<1> key generation\n<2> encryption\n<3> decryption\n<4> exit\n: """)
        if choice == 1:
            (n, e, d, wn) = keys()
            print 'public key: (%d,%d)' % (e, n)
            print 'private key: (%d,%d)' % (d, n)

        if choice == 2:
            M = input('M: ')
            c = pow(M, e) % n
            print 'cipher: %d' % c

        if choice == 3:
            Ms = pow(c, d) % n
            print 'message(M): %d' % M
        if choice == 4:
            return

def keys():
    p = input('Enter primes: ')
    q = input()
    print 'Enter e: '
    e = input()
    n = p * q
    wn = (p - 1) * (q - 1)
    d = calc(wn, e)
    return [n, e, d, wn]

def calc(phn, e):
    r1 = phn
    r2 = e
    t1 = 0
    t2 = 1
    while r2 > 0:
        q = r1 / r2
        r = r1 - q * r2
        r1 = r2
        r2 = r
        t = t1 - q * t2
        t1 = t2
        t2 = t
    if r1 == 1:
        d = t1
    return d

if __name__ == '__main__':
    main()
