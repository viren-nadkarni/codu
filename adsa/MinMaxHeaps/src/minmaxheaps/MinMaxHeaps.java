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

public class MinMaxHeaps {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int choice, count, ch;
        MainMenu:
        do {
            System.out.println("---Menu---");
            System.out.println("(1) Min heap");
            System.out.println("(2) Max heap");
            System.out.println("(3) Min-max heap");
            System.out.println("(4) Exit");
            Scanner n2 = new Scanner(System.in);
            choice = n2.nextInt();
            switch (choice) {
                case 1:
                    System.out.println("Minheap");
                    MinHeap h1 = new MinHeap();
                    count = 0;
                    do {
                        System.out.println("--MinHeap--");
                        System.out.println(" (1) insert into minheap");
                        System.out.println(" (2) delete from minheap");
                        System.out.println(" (3) print minheap");
                        System.out.println(" (4) back");
                        ch = n2.nextInt();
                        switch (ch) {
                            case 1:
                                System.out.println("Number of elements: ");
                                int n = n2.nextInt();
                                System.out.println("Enter elements: ");
                                for (int i = 0; i < n; i++) {
                                    h1.insert(count);
                                    count++;
                                }
                                break;
                            case 2:
                                h1.delete(count);
                                count -= 1;
                                break;
                            case 3:
                                h1.display(count);
                                break;
                            case 4:
                                break;
                        }
                    } while (ch != 4);
                    break;

                case 2:
                    int chh;
                    System.out.println("Maxheap");
                    MaxHeap h2 = new MaxHeap();
                    count = 0;
                    do {
                        System.out.println("--MaxHeap--");
                        System.out.println(" (1) insert into maxheap");
                        System.out.println(" (2) delete from maxheap");
                        System.out.println(" (3) print maxheap");
                        System.out.println(" (4) back");
                        chh = n2.nextInt();
                        switch (chh) {
                            case 1:
                                System.out.println("Number of elements: ");
                                int n = n2.nextInt();
                                System.out.println("Enter elements: ");
                                for (int i = 0; i < n; i++) {
                                    h2.insert(count);
                                    count += 1;
                                }
                                break;
                            case 2:
                                h2.delete(count);
                                count -= 1;
                                break;
                            case 3:
                                h2.display(count);
                                break;
                            case 4:
                                break;
                        }
                    } while (chh != 4);
                    break;
                case 3:
                    MinMaxHeap obj = new MinMaxHeap();
                    int co = 0;
                    int choice1;
                    do {
                        System.out.println("--MinMaxHeap--");
                        System.out.println(" (1) insert");
                        System.out.println(" (2) delete min");
                        System.out.println(" (3) delete max");
                        System.out.println(" (4) print");
                        System.out.println(" (5) back");
                        choice1 = n2.nextInt();
                        switch (choice1) {
                            case 1:
                                System.out.println("Number of elements: ");
                                int n = n2.nextInt();
                                System.out.println("Enter elements: ");
                                for (int i = 0; i < n; i++) {
                                    obj.insert(co);
                                    co++;
                                }
                                break;
                            case 2:
                                obj.deletemin(co);
                                co -= 1;
                                break;
                            case 3:
                                obj.deletemax(co);
                                co -= 1;
                                break;
                            case 4:
                                obj.display(co);
                                break;
                        }
                    } while (choice1 != 5);
                    break;
                case 4:
                    break;
            }
        } while (choice != 4);
    }
}
