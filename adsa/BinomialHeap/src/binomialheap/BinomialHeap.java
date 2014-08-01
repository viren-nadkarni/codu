/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package binomialheap;

import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

/**
 *
 * @author viren
 */
public class BinomialHeap {

    /**
     * @param args the command line arguments
     */
        //Node min=new Node();
    Node min = null;
    int ch = 1;

    public void input() {
        int i = 1, h[] = {6, 7, 10, 11, 14, 15, 2, 3, 30}, n = h.length;
        
        System.out.print("Inserting: ");
        for (i = 0; i < n; i++) {
            System.out.print(h[i] + " ");
        }
        System.out.println();

        for (i = 0; i < n; i++) {
            insert(h[i]);
        }
        
        min = minimum(min);
        
        System.out.println("After insertion: ");
        dtree(min);
        
        System.out.println("Delete min: " + min.data);
        min = delete(min);
        dtree(min);
    }

    public Node minimum(Node m) {
        Node t = m;
        Node tt = m;
        do {
            if (tt.data <= t.data) {
                t = tt;
            }
            tt = tt.next;

        } while (tt != m);
        m = t;
        return m;
    }

    public void insert(int x) {
        Node q = new Node();

        q.data = x;
        min = insertlist(min, q);
        
        do {
            min = CheckAndCombine(min);
        } while (ch != 0);
        min = CheckAndCombine(min);
    }

    public Node insertlist(Node p, Node q) {
        if (p == null) {
            p = q;
            p.next = p;
        } else {
            Node t = p;
            while (p.next != t) {
                p = p.next;
            }
            q.next = p.next;
            p.next = q;
            p = q.next;
            p = t;
            do {
                p = p.next;
            } while (p.next != t);
        }
        return p;
    }

    public void Combine() {
        int h1[] = {51, 34, 1, 52, 44, 47, 49, 43, 20, 18, 8, 15, 32};
        int h2[] = {6, 7, 10, 11, 14, 15, 2, 3, 30};

        System.out.println("Combining: ");
        System.out.print("Inserting h1: ");
        for (int i = 0; i < h1.length; i++) {
            System.out.print(h1[i] + " ");
        }
        System.out.println();
        System.out.print("Inserting h2: ");
        for (int i = 0; i < h2.length; i++) {
            System.out.print(h2[i] + " ");
        }
        System.out.println("\n");

        System.out.println("h1: ");
        Node p = null;

        for (int i = 0; i < h1.length; i++) {
            Node q = new Node();
            q.data = h1[i];
            p = insertlist(p, q);

            do {
                p = CheckAndCombine(p);
            } while (ch != 0);
            p = CheckAndCombine(p);
        }
        dtree(p);

        System.out.println("h2: ");
        Node t = null;

        for (int i = 0; i < h2.length; i++) {
            Node q = new Node();
            q.data = h2[i];
            t = insertlist(t, q);

            do {
                t = CheckAndCombine(t);
            } while (ch != 0);
            t = CheckAndCombine(t);
        }
        dtree(t);

        System.out.println("h1 + h2: ");

        Node r = p;
        do {
            r = r.next;
        } while (r.next != p);

        r.next = t;
        do {
            r = r.next;
        } while (r.next != t);
        r.next = p;
        do {
            r = CheckAndCombine(r);
        } while (ch != 0);
        r = CheckAndCombine(r);
        dtree(r);
    }

    public Node CheckAndCombine(Node m) {
        Node t = m;
        Node l1 = new Node();
        Node l2 = new Node();
        int flag = 0;
        do {
            Node tt = t.next;
            do {
                if (t.degree == tt.degree) {
                    l1 = t;
                    l2 = tt;
                    flag = 1;
                    break;
                }
                tt = tt.next;
            } while (tt != t);
            if (flag == 1) {
                break;
            }
            t = t.next;
        } while (t.next != m);
        if (flag == 1 && l1 != l2) {
            if (l1.data < l2.data) {
                Node t1 = new Node();
                Node t2 = new Node();
                l1.degree += 1;
                t1.data = l1.data;
                t1.child = l1.child;
                t1.degree = l1.degree;
                t2.data = l2.data;
                t2.child = l2.child;
                t2.degree = l2.degree;

                Node tchild = new Node();
                tchild = t1.child;
                t1.child = insertlist(tchild, t2);
                m = remove(m, l1, l2);
                m = insertlist(m, t1);
            } else {
                Node t1 = new Node();
                Node t2 = new Node();
                l2.degree += 1;
                t1.data = l2.data;
                t1.child = l2.child;
                t1.degree = l2.degree;
                t2.data = l1.data;
                t2.child = l1.child;
                t2.degree = l1.degree;
                t1.child = insertlist(t1.child, t2);
                m = remove(m, l2, l1);
                m = insertlist(m, t1);
            }
            ch = 1;
        }
        ch = 0;
        return m;
    }

    public Node remove(Node m, Node t1, Node t2) {
        Node f = new Node();
        f = null;

        Node t = m;

        do {
            if (t != t1 && t != t2) {
                Node q = new Node();
                q.data = t.data;
                q.degree = t.degree;
                q.child = t.child;
                f = insertlist(f, q);
            }
            t = t.next;
        } while (t != m);
        if (f == null) {
            return null;
        }
        return f;
    }

    public void displaylist(Node m) {
        Node t = m;

        if (m != null) {
            do {
                System.out.print(t.data);
                if (t.next != m) {
                    System.out.print("--");
                }
                t = t.next;
            } while (t != m);
        }
    }

    public void dtree(Node m) {
        Node t = m;
        int count = 0;
        int ch = 0;
        Node r;
        Queue q = new LinkedList();
        do {
            q.add(t);
            System.out.println(t.data + " ");
            Node f = (Node) q.poll();

            do {
                Node c = f.child;
                if (c != null) {

                    do {
                        System.out.print(c.data + " ");
                        q.add(c);
                        count++;
                        r = c;
                        c = c.next;
                    } while (c != f.child);
                    if (count == f.degree) {
                        System.out.println("");
                        count = 0;
                    }
                }

                f = (Node) q.poll();

            } while (f != null);
            t = t.next;
            System.out.println("");
        } while (t != m);
    }

    public Node delete(Node m) {
        Node t = new Node();
        t = m.next;
        do {
            t = t.next;
        } while (t.next != m);
        t.next = m.next;

        t.next = m.child;

        do {
            t = t.next;
        } while (t.next != m.child);

        t.next = m.next;

        m = t;

        do {
            m = CheckAndCombine(m);
        } while (ch != 0);

        m = CheckAndCombine(m);
        m = CheckAndCombine(m);

        return m;
    }

    public static void main(String args[]) {
        BinomialHeap bh = new BinomialHeap();
        bh.input();
        bh.Combine();
    }
}
