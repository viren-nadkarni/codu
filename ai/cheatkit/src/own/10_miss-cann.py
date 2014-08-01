#!/usr/bin/python
#-------------------------------------------------------------------------------
# Name:        miss-cann
# Purpose:     
#
# Author:      viren
#
# Created:     30 01 2013
# Copyright:   (c) viren 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------

stack = []

def boat(a_miss, a_cann, b_miss, b_cann, direction, last_move = 0):
    if a_miss < 0 or a_cann < 0 or b_cann < 0 or b_miss < 0  or (a_miss == 3 and a_cann == 3 and last_move != 0):
        return False

    if (a_miss == 0 and a_cann == 0):
#        print "solution is in reverse order"
        tmp = "final" + str(6 * "\t") + "(0,0)(3,3)"
        stack.append(tmp)
        return True

    if (a_miss >= a_cann and b_miss >= b_cann) or (a_miss == 0 and a_cann !=0 and b_miss >= b_cann) or (b_miss == 0 and b_cann !=0 and a_miss >= a_cann):
        if direction == True:
            if last_move != 1 and boat(a_miss - 1, a_cann, b_miss + 1, b_cann, not direction, 1):
                tmp = "1 miss goes from A to B", "\t\t(" + str(a_miss) + "," + str(a_cann) + ")(" + str(b_miss) + "," + str(b_cann) + ")"
                stack.append(tmp)
                return True
            elif last_move != 2 and boat(a_miss, a_cann - 1, b_miss, b_cann + 1, not direction, 2):
                tmp = "1 cann goes from A to B" + "\t\t(" + str(a_miss) + "," + str(a_cann) + ")(" + str(b_miss) + "," + str(b_cann) + ")"
                stack.append(tmp)
                return True
            elif last_move != 3 and boat(a_miss - 2, a_cann, b_miss + 2, b_cann, not direction, 3):
                tmp = "2 miss goes from A to B" + "\t\t(" + str(a_miss) + "," + str(a_cann) + ")(" + str(b_miss) + "," + str(b_cann) + ")"
                stack.append(tmp)
                return True
            elif last_move != 4 and boat(a_miss, a_cann - 2, b_miss, b_cann + 2, not direction, 4):
                tmp = "2 cann goes from A to B" + "\t\t(" + str(a_miss) + "," + str(a_cann) + ")(" + str(b_miss) + "," + str(b_cann) + ")"
                stack.append(tmp)
                return True
            elif last_move != 5 and boat(a_miss - 1, a_cann - 1, b_miss + 1, b_cann + 1, not direction, 5):
                tmp = "1 miss & 1 cann goes to B" + "\t(" + str(a_miss) + "," + str(a_cann) + ")(" + str(b_miss) + "," + str(b_cann) + ")"
                stack.append(tmp)
                return True
        elif direction == False:
            if last_move != 1 and boat(a_miss + 1, a_cann, b_miss - 1, b_cann, not direction, 1):
                tmp = "1 miss comes back" + "\t\t\t(" + str(a_miss) + "," + str(a_cann) + ")(" + str(b_miss) + "," + str(b_cann) + ")"
                stack.append(tmp)
                return True
            elif last_move != 2 and boat(a_miss, a_cann + 1, b_miss, b_cann - 1, not direction, 2):
                tmp = "1 cann comes back" + "\t\t\t(" + str(a_miss) + "," + str(a_cann) + ")(" + str(b_miss) + "," + str(b_cann) + ")"
                stack.append(tmp)
                return True
            elif last_move != 3 and boat(a_miss + 2, a_cann, b_miss - 2, b_cann, not direction, 3):
                tmp = "2 miss comes back" + "\t\t\t(" + str(a_miss) + "," + str(a_cann) + ")(" + str(b_miss) + "," + str(b_cann) + ")"
                stack.append(tmp)
                return True
            elif last_move != 4 and boat(a_miss, a_cann + 2, b_miss, b_cann - 2, not direction, 4):
                tmp = "2 cann comes back" + "\t\t\t(" + str(a_miss) + "," + str(a_cann) + ")(" + str(b_miss) + "," + str(b_cann) + ")"
                stack.append(tmp)
                return True
            elif last_move != 5 and boat(a_miss + 1, a_cann + 1, b_miss - 1, b_cann - 1, not direction, 5):
                tmp = "1 miss & 1 cann comes back" + "\t(" + str(a_miss) + "," + str(a_cann) + ")(" + str(b_miss) + "," + str(b_cann) + ")"
                stack.append(tmp)
                return True
    return False

def main():
    if boat(3,3,0,0,True):
        print "solution found"
        while stack:
            print stack.pop()
    else:
        print "_ oops, no solution"

if __name__ == '__main__':
    main()