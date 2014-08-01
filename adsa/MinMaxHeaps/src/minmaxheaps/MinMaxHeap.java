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

public class MinMaxHeap {

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
        }
        //finding level
        int pos = cc + 1;
        int level = (int) (Math.floor(Math.log(pos) / Math.log(2)));
        if (level % 2 == 0 && (cc != 0)) {
            root = (cc - 1) / 2;
            if (element > heap[root]) {
                swap(root, element, cc);
            } else {
                if (root == 0) {
                    heap[cc] = element;
                }
                while (root != 0) {
                    root = (root - 1) / 2;
                    if (element < heap[root]) {
                        swap(root, element, cc);
                    } else if (root == 0) {
                        heap[cc] = element;
                    }
                    root = (root - 1) / 2;
                }
            }

        } else {
            root = (cc - 1) / 2;
            if (element < heap[root]) {
                swap(root, element, cc);
            } else {
                if (root == 0) {
                    heap[cc] = element;
                }
                while (root != 0) {
                    root = (root - 1) / 2;
                    if (element > heap[root]) {
                        swap(root, element, cc);
                    }
                    root = (root - 1) / 2;
                    if (root == 0) {
                        heap[cc] = element;
                    }
                }
            }
        }
    }

    void deletemax(int cc) {
        int root = 0, m = 1, i = 0, min = 0, pos = 3, temp;
        int level = (int) (Math.floor(Math.log((cc - 1)) / Math.log(2)));
        if ((cc - 1) == 7) {
            level = 3;
        }
        int numl = (int) Math.pow(2.0, level);
        int x = heap[cc - 1];
        int max1;
        int lft = 2 * root + 1;
        int rgt = 2 * root + 2;
        max1 = lft;

        if (heap[max1] < heap[rgt]) {
            max1 = rgt;
        }
        if (cc == 3) {
            if (heap[max1] < heap[rgt]) {
                max1 = rgt;
            }
        } else if (cc == 2) {
            max1 = lft;
        }
        int maxlft = 2 * max1 + 1;
        int maxrgt = 2 * max1 + 2;
        if ((cc - 1) == 6) {
            if (heap[maxlft] > heap[maxrgt]) {
                heap[max1] = heap[maxlft];
            } else {
                heap[max1] = heap[maxrgt];
            }
        } else if (maxrgt >= (cc - 1)) {
            if (maxlft == (cc - 1)) {
                heap[max1] = heap[cc - 1];
            } else {
                heap[max1] = Math.max(heap[2 * lft + 1], heap[2 * lft + 2]);
            }
        } else if (numl >= 8) {
            int tmp = 7;
            for (int k = 8; k <= cc - 1; k++) {
                if (heap[tmp] < heap[k]) {
                    tmp = k;
                }
            }
            if (heap[tmp] < x) {
                heap[max1] = x;
            } else {
                heap[max1] = heap[tmp];
                heap[tmp] = x;
                int t1;
                if (heap[tmp] < heap[((tmp + 1) / 2) - 1]) {
                    t1 = heap[tmp];
                    heap[tmp] = heap[((tmp + 1) / 2) - 1];
                    heap[((tmp + 1) / 2) - 1] = t1;
                }
            }
        }
    }

    void deletemin(int cc) {
        int root = 0, m = 1, i = 0, min = 0, pos = 3, temp;
        int level = (int) (Math.floor(Math.log((cc - 1)) / Math.log(2)));
        int x = heap[cc - 1];
        int min1;
        int lft = 2 * root + 1;
        int rgt = 2 * root + 2;
        min1 = lft;
        if (cc == 4) {
            if (heap[min1] > heap[rgt]) {
                min1 = rgt;
            }
        } else if (cc == 3) {
            min1 = lft;
        } else {
            int cpos = 2 * lft + 1;
            min = heap[cpos];
            int var;
            if (cc < 8) {
                var = cc - 1;
            } else {
                var = 7;
            }
            for (i = (cpos + 1); i < var; i++) {
                if (min > heap[i]) {
                    min = heap[i];
                    System.out.println(min);
                    pos = i;
                }

            }
            min1 = pos;
        }
        //swap
        if (x >= heap[min1]) {
            heap[root] = heap[min1];
            heap[min1] = x;
            int parent = (min1 / 2);
            if (heap[min1] > heap[parent]) {
                int tmp = heap[parent];
                heap[parent] = heap[min1];
                heap[min1] = tmp;
            }
        } else {
            heap[root] = x;
        }
    }

    void display(int cc) {
        System.out.println("MinMaxHeap contains: ");
        for (int i = 0; i < cc; i++) {
            System.out.print(heap[i] + " ");
        }
        System.out.println();
    }
}
