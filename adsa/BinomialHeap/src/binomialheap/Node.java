/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package binomialheap;

/**
 *
 * @author viren
 */
public class Node {
    int data, degree;
    Node child, next;

    Node() {
        child = null;
        next = null;
        data = -1;
        degree = 0;
    }
}
