#-------------------------------------------------------------------------------
# Name:        semantic net
# Purpose:
#
# Author:      viren
#
# Created:     15/05/2013
# Copyright:   (c) viren 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------

import networkx as nx
import matplotlib.pyplot as mpl

def main():
#           0               1               2      3      4
    n = ['GECStudent', 'CompStudent', 'Student', 'Bag', 'Bus',
#           5               6           7           8
        'CollegeBus', 'LunchBox', 'Internet', 'Programming',
        'Cursor', 'Raj']
#           9       10

    G = nx.DiGraph()

    G.add_edge(n[0], n[2], a = 'isa')
    G.add_edge(n[1], n[0], a = 'isa')
    G.add_edge(n[2], n[3], a = 'carry')
    G.add_edge(n[2], n[4], a = 'travelby')
    G.add_edge(n[0], n[5], a = 'travelby')
    G.add_edge(n[0], n[6], a = 'carry')
    G.add_edge(n[1], n[7], a = 'knows')
    G.add_edge(n[1], n[8], a = 'knows')
    G.add_edge(n[1], n[9], a = 'memberof')
#    G.add_edge(n[10], n[1], a = 'instance')

    pos = nx.spring_layout(G)

    nx.draw_networkx_nodes(G, pos, node_color='w', node_size=2500)
    nx.draw_networkx_labels(G, pos, font_size=10)

    nx.draw_networkx_edges(G, pos)
    nx.draw_networkx_edge_labels(G, pos, alpha=0.8, font_size=10)

    mpl.axis('off')
    mpl.savefig("semantic_net.png")
    mpl.show()


if __name__ == '__main__':
    main()
