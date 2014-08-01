#!/usr/bin/env python

import sys
import pygame

pygame.init()

def crypt(key1,data):
    encryp = []
    key = ''
    for i in range(len(key1)):
        for j in range(len(key1)):
            key += key1[i]
        
    for i in range(len(data)):
        en = int(key[i]) ^ int(data[i])
        encryp.append(en)
    return encryp   

window = pygame.display.set_mode((640, 480))

def display(t, key, data):
    window = pygame.display.set_mode((640, 480))
    draw(key, 20, 40, 20, 20)
    draw(data, 20, 90, 20, 70)
    draw(t, 20,140,20,120)
     
def draw(t, x, y, x1, y1):
    tmp = 0
    pygame.draw.line(window, (255, 255, 255), (x1, y), (x1 + 400, y))
    pygame.display.flip()
    pygame.draw.line(window, (255, 255, 255), (x1, y), (x1, y1 - 10))
    pygame.display.flip()
              
    for i in range(len(t)):
        if t[i] == '1':
            tmp = x1 + 30
            if i != 0 and t[i-1] != '1':
                pygame.draw.line(window, (255, 255, 255), (x1, y), (x1, y1))
                pygame.display.flip()
            pygame.draw.line(window, (255, 255, 255), (x1, y1), (tmp, y1))
            pygame.display.flip()
            x1 += 30
        else:
            tmp = x1 + 30
            if i != 0 and t[i-1] != '0':
                pygame.draw.line(window, (255, 255, 255), (x1, y), (x1, y1))
                pygame.display.flip()
            pygame.draw.line(window, (255, 255, 255), (x1, y), (tmp, y))
            x1 += 30
            pygame.display.flip()

choice = 0;

while choice != 3:
    print
    print '[1] Sender'
    print '[2] Receiver'
    print '[3] Exit'
    choice = input('> ')
    if choice == 1:
        key = raw_input('Key: ')
        l = len(key) * len(key)
        d = 0

        while l != d:
            data = raw_input('Data: ')
            d = len(data)
        encryp = []
        key22 = ''
        for i in range(len(key)):
            for j in range(len(key)):
                key22 += key[i]
        print 'Spreading Sequence <key>: ',
        for i in range(len(key)):
            if (key[i] == '0'):
                print '-1',
            else:
                print key[i],
        print
        print 'Spreading Sequence <data>: ',
        for i in range(len(data)):
            if (data[i] == '0'):
                print '-1',
            else:
                print data[i],
        print
        encryp = crypt(key, data)

        print 'Encrypted data', encryp
        qw = ''.join(map(str, encryp))
        display(qw, key22, data)
        
    elif choice == 2:
        key1 = raw_input('Key: ')
        data1 = raw_input('Encrypted data: ')
        key22 = ''
        for i in range(len(key1)):
            for j in range(len(key1)):
                key22 += key1[i]
        decr = []
        decr = crypt(key1, data1)
        
        t = ''.join(map(str, decr))
        print 'Encrypted data:', t
        display(t, key22, data1)
    