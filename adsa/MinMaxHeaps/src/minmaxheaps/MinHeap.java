/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package minmaxheaps;

/**
 *
 * @author viren
 */
import java.util.Scanner;

public class MinHeap {
    Scanner n1 = new Scanner(System.in);
    int heap[] = new int[20];
    int root = 0;

    void swap(int root, int element, int count1) {
        int temp;
        temp = heap[root];
        heap[root] = element;
        heap[count1] = temp;
    }

    void insert(int cc) {
        int element = n1.nextInt();
        if (cc == 0) {
            heap[cc] = element;
        } else {
            do {
                root = (cc - 1) / 2;
                if (element < heap[root]) {
                    swap(root, element, cc);
                } else {
                    heap[cc] = element;
                    root = 0;
                }
                cc = root;
            } while (root != 0);
        }
    }

    void delete(int cd) {
        int i = 1, j = 0;
        System.out.println("Deleted " + heap[0]);
        heap[j] = heap[cd - 1];
        cd = cd - 1;
        do {
            if (heap[i] < heap[i + 1]) {
                swap(j, heap[i], i);
                j = 2 * j + 1;
                i = 2 * j + 1;
            } else {
                swap(j, heap[i + 1], i + 1);
                j = 2 * j + 2;
                i = 2 * j + 2;
            }
        } while (i < cd);
    }

    void display(int c) {
        System.out.println("Minheap contains: ");
        for (int i = 0; i < c; i++) {
            System.out.print(heap[i] + " ");
        }
        System.out.println();
    }
}
