#!/usr/bin/env python

vect1 = input('Vector 1 = ')
vect2 = input('Vector 2 = ')

orth1 = []
orth2 = []

for a in vect1:
    if a == 0:
        orth1.append(-1)
    else:
        orth1.append(1)
        
for a in vect2:
    if a == 0:
        orth2.append(-1)
    else:
        orth2.append(1)

result = []

print 'Bipolar Matrix 1:', orth1
print 'Bipolar Matrix 2:', orth2

for a in zip(orth1, orth2):
    result.append(a[0] + a[1])

flag = True
for a in result:
    if a == 0:
        continue
    else:
        flag = False
        
if not flag:
    print 'Matrix is not orthogonal'
else:
    print 'Matrix is orthogonal'
    
    
