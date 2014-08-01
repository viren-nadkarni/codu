#!/usr/bin/python
#-------------------------------------------------------------------------------
# Name:        8puzzle
# Purpose:
#
# Author:      viren
#
# Created:     26 04 2013
# Copyright:   (c) viren 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------

starting_state = [0, 1, 3,
                  5, 2, 6,
                  4, 7, 8]

goal_state = [1, 2, 3,
              4, 5, 6,
              7, 8, 0]


class Node:
    def __init__( self, state, parent, operator, depth, cost ):
        self.state = state
        self.parent = parent
        self.operator = operator
        self.depth = depth
        self.cost = cost


def createNode( state, parent, operator, depth, cost ):
    return Node( state, parent, operator, depth, cost )


def expandNode( node, nodes ):
    expanded_nodes = []
    expanded_nodes.append( createNode( move( node.state, 'up' ), node, "l", node.depth + 1, 0 ) )
    expanded_nodes.append( createNode( move( node.state, 'down' ), node, "r", node.depth + 1, 0 ) )
    expanded_nodes.append( createNode( move( node.state, 'left' ), node, "u", node.depth + 1, 0 ) )
    expanded_nodes.append( createNode( move( node.state, 'right' ), node, "d", node.depth + 1, 0 ) )
    expanded_nodes = [node for node in expanded_nodes if node.state != None]
    return expanded_nodes


def depthFirstSearch( start, goal, depth=10 ):
    depth_limit = depth
    nodes = []
    nodes.append( createNode( start, None, None, 0, 0 ) )
    while True:
        if len( nodes ) == 0:
            return None
        node = nodes.pop(0)
        if node.state == goal:
            moves = []
            temp = node
            while True:
                moves.insert(0, temp.operator)
                if temp.depth <= 1:
                    break
                temp = temp.parent
            return moves
        if node.depth < depth_limit:
            expanded_nodes = expandNode( node, nodes )
            expanded_nodes.extend( nodes )
            nodes = expanded_nodes


def iterDepthSearch( start, goal, depth=50 ):
    for i in range( depth ):
        result = depthFirstSearch( start, goal, i )
        if result != None:
            return result


def move(state, direction):
    new_state = state[:]
    index = new_state.index( 0 )
    if direction == 'up':
        if index not in [0, 3, 6]:
            temp = new_state[index - 1]
            new_state[index - 1], new_state[index] = new_state[index], temp
            return new_state
    elif direction == 'down':
        if index not in [2, 5, 8]:
            temp = new_state[index + 1]
            new_state[index + 1], new_state[index] = new_state[index], temp
            return new_state
    elif direction == 'left':
        if index not in [0, 1, 2]:
            temp = new_state[index - 3]
            new_state[index - 3], new_state[index] = new_state[index], temp
            return new_state
    elif direction == 'right':
        if index not in [6, 7, 8]:
            temp = new_state[index + 3]
            new_state[index + 3], new_state[index] = new_state[index], temp
            return new_state
    return None


def main():
    result = iterDepthSearch( starting_state, goal_state )
    if result == None:
        print "No solution found"
    elif result == [None]:
        print "Puzzle already solved"
    else:
        print result
        print len(result), " moves"


if __name__ == "__main__":
    main()