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

import java.util.Scanner;

public class LeftistTree {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        LeftistHeap lheap = new LeftistHeap();

        char ch;
        boolean quit = false;
        do {
            System.out.println("---Menu---");
            System.out.println("(1) insert ");
            System.out.println("(2) delete min");
            System.out.println("(3) display");
            System.out.println("(4) quit");

            int choice = scan.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Number of elements: ");
                    int t = scan.nextInt();
                    System.out.print("Enter " + t + " elements: ");
                    for(int m = 0; m < t; ++m)
                        lheap.insert(scan.nextInt());
                    break;
                case 2:
                    lheap.delete();
                    break;
                case 3:
                    lheap.display();
                    break;
                case 4:
                    quit = true;
                    break;
            }
        } while (!quit);
    }
}
