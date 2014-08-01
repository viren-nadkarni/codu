/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package leftisttree;

/**
 *
 * @author viren
 */
public class LeftHeapNode {

    int element, sValue;
    LeftHeapNode left, right;

    public LeftHeapNode(int ele) {
        this(ele, null, null);
    }

    public LeftHeapNode(int ele, LeftHeapNode left, LeftHeapNode right) {
        this.element = ele;
        this.left = left;
        this.right = right;
        this.sValue = 0;
    }
}
