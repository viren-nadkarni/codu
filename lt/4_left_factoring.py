#!/usr/bin/env python
# left factoring

inp = 'A->Ma|Mb|Mcd|g'
print 'if ', inp
print 'then'

lhs = (inp.split('->'))[0]
rhs = (inp.split('->'))[1]

lhsList = [lhs]
rhsList = rhs.split('|')

lhsAns = []
rhsAns = []

def longestSubstr(str1, str2):
    ans = ''
    len1, len2 = len(str1), len(str2)
    for i in range(len1):
        match = ''
        for j in range(len2):
            if (i + j < len1 and str1[i + j] == str2[j]):
                match += str2[j]
            else:
                if len(match) > len(ans):
                    ans = match
                match = ''
    return ans

def main():
    common = longestSubstr(rhsList[0], rhsList[1])
    for i in range(2, len(rhsList)):
        common = longestSubstr(common, rhsList[i])
    
    lhsAns.append(lhsList[0])
    lhsAns.append(lhsList[0] + "'")
    
    rhsAns.append(common + lhsList[0] + "'")
    
    tmpStr = ''
    tmpStr += rhsList[0][len(common):]
    for j in rhsList[1:]:
        tmpStr += '|'
        tmpStr += j[len(common):]       
        
    rhsAns.append(tmpStr)
    
if __name__ == '__main__':
    #try:
        main()
    #except:
        for a in range(0, len(lhsAns)):
            print lhsAns[a], '->', rhsAns[a]