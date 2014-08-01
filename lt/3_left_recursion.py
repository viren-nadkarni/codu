#!/usr/bin/env python
# left recursion

inp = 'A->Aa|Ab|Ac|g'
print 'if ', inp
print 'then'

lhs = (inp.split('->'))[0]
rhs = (inp.split('->'))[1]

lhsList = [lhs]
rhsList = rhs.split('|')

lhsAns = []
rhsAns = []

def main():
    lhsAns.append(lhsList[0])
    terminal = rhsList[-1]
    rhsAns.append(str(terminal + lhsList[0] + "'"))
    lhsAns.append(str(lhsList[0] + "'"))
    
    tmpStr = ''
    #print rhsList
    for j in rhsList:
        if j[0] == lhsList[0]:
            tmpStr += ( j[1:] + str(lhsList[0] + "'|"))
    
    tmpStr += 'e'
    rhsAns.append(tmpStr)
    

if __name__ == '__main__':
    #try:
        main()
    #except:
        for a in range(0, len(lhsAns)):
            print lhsAns[a], '->', rhsAns[a]