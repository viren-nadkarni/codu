#!/usr/bin/env python

import sys

def main():
    ch = input('[1] MONKEY DONKEY\n[2] I1I2I5 I2I4\nChoose the dataset: ')
    if ch == 1:
        f = open('ap_dataset1.txt', 'r')
    elif ch == 2:
        f = open('ap_dataset2.txt', 'r')
    else:
        print 'unknown'
        sys.exit()
    ms = input('Minimum support: ')
    # ms = 3
    
    tid = []
    itemlist = []
    
    for line in f.readlines():
        a, b = line.split(' ')
        tid.append(a)
        itemlist.append( [a.strip() for a in b.split(',')] )

    c1 = []
    c2 = []
    c_count = 1
    
    while True:
        if c_count == 1:
            for i in itemlist:
                for j in i:
                    if [j] not in c1:
                        c1.append([j])
                        c2.append(0)
        else:
            for i in c1:
                c2.append(0)

        for i in c1:
            for j in itemlist:
                if set(i).issubset(set(j)):
                    c2[c1.index(i)] += 1
                
        print 'C' + str(c_count) + '\t\t\t\t\tL' + str(c_count)
        c1_tmp = []
        c2_tmp = []
        for i in range(len(c1)):
            print ' ', c1[i], c2[i],
            if c2[i] >= ms:
                print str(c1[i]).rjust(36), str(c2[i]).rjust(4),
                c1_tmp.append(c1[i])
                c2_tmp.append(c2[i])
            print
        print
        
        c_count += 1
        c1 = []
        c2 = []
        
        # do the permutation thing
        for i in range(len(c1_tmp)):
            for j in range(i + 1, len(c1_tmp)):
                t = list(set(c1_tmp[i]) | set(c1_tmp[j]))
                if not t in c1:
                    c1.append(t)
        
        if len(c1) < 2:
            # try:
                # print 'solution:', c1[0]
            # except:
                # print 'solution:', c1_tmp[0]
            break
        
if __name__ == '__main__':
    main()