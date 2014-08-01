/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package deap;

/**
 *
 * @author viren
 */

import java.util.Scanner;

public class Deap {

    /**
     * @param args the command line arguments
     */
    int[] deap = new int[512];
    int n = 1;

    private int max_subtree(int pos) {
        int offset = 1;
        int i = pos;
        while (i > 3) {
            i /= 2;
            offset *= 2;
        }
        if ((pos + offset) > n) {
            return (pos + offset) / 2;
        }
        return pos + offset;
    }

    private int min_subtree(int pos) {
        int offset = 1;
        int i = pos;
        while (i > 3) {
            i /= 2;
            offset *= 2;
        }
        return pos - offset;
    }

    private void min_insert(int at, int key) {
        int parent;
        for(;(parent = at / 2) != 1 && key < deap[parent];) {
            deap[at] = deap[parent]; 
            at = parent;
        }
        deap[at] = key;
    }

    private void max_insert(int at, int key) {
        int parent;
        for(;(parent = at / 2) != 1 && key > deap[parent];) {
            deap[at] = deap[parent];
            at = parent;
        }
        deap[at] = key;
    }

    public int delete_max() {
        int i, j;
        int key;
        if (n >= 3)
            key = deap[3];
        else {
            n--;
            return deap[2];
        }
        int x = deap[n--];
        for (i = 3; 2 * i <= n; deap[i] = deap[j], i = j) {
            j = i * 2;
            if (j + 1 <= n) {
                if (deap[j] < deap[j + 1]) {
                    j++;
                }
            }
        }
        j = min_subtree(i);
        int biggest = j;
        if (2 * j <= n) {
            biggest = 2 * j;
            if (((2 * j + 1) <= n) && (deap[2 * j] < deap[2 * j + 1])) {
                biggest++;
            }
        }
        if (x < deap[biggest]) {
            deap[i] = deap[biggest];
            min_insert(biggest, x);
        } else
            max_insert(i, x);
        return key;
    }

    public int delete_min() {
        int i, j, key = deap[2], x = deap[n--];
        for (i = 2; 2 * i <= n; deap[i] = deap[j], i = j) {
            j = i * 2;
            if (j + 1 <= n && deap[j] > deap[j + 1]) {
                j++;
            }
        }
        j = max_subtree(i);
        if (x > deap[j]) {
            deap[i] = deap[j];
            max_insert(j, x);
        } else {
            min_insert(i, x);
        }
        return key;
    }

    public void insert(int x) {
        n++;
        if (n == deap.length) {
            System.out.println("Overflow");
            System.exit(1);
        }
        if (n == 2) {
            deap[2] = x;
            return;
        }
        if (is_present(n)) {
            int i = min_subtree(n);
            if (x < deap[i]) {
                deap[n] = deap[i];
                min_insert(i, x);
            } else {
                max_insert(n, x);
            }
        } else {
            int i = max_subtree(n);
            if (x > deap[i]) {
                deap[n] = deap[i];
                max_insert(i, x);
            } else {
                min_insert(n, x);
            }
        }
    }

    private boolean is_present(int i) {
        while (i > 3) {
            i /= 2;
        }
        if (i == 2)
            return false;
        return true;
    }

    public void display() {
        for (int i = 2; i <= n; i++)
            System.out.print(deap[i] + " ");
        System.out.println();
    }

    public static void main(String[] argv) {
        Deap d = new Deap();
        Scanner scan = new Scanner(System.in);
        
        int choice;
        boolean quit = false;
        
        do {
            System.out.println("---Menu---");
            System.out.println("(1) insert ");
            System.out.println("(2) delete min");
            System.out.println("(3) delete max");
            System.out.println("(4) display");
            System.out.println("(5) quit");
            
            choice = scan.nextInt();
            switch(choice) {
                case 1:
                    System.out.print("Number of elements: ");
                    int t = scan.nextInt();
                    System.out.print("Enter " + t + " elements: ");
                    for(int m = 0; m < t; ++m)
                        d.insert(scan.nextInt());
                    break;
                case 2:
                    System.out.println("Deleted " + d.delete_min());
                    break;
                case 3:
                    System.out.println("Deleted " + d.delete_max());
                    break;
                case 4:
                    d.display();
                    break;
                case 5:
                    quit = true;
                    break;
            }            
        } while(!quit);
    }
}
