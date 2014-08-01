/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package obst;

import java.util.Scanner;

/**
 *
 * @author viren
 */
public class OBST {

    /**
     * @param args the command line arguments
     */
    int n;
    String a[];
    int p[], q[], w[][], c[][], r[][], t[][];

    public void input() {
        Scanner s = new Scanner(System.in);
        System.out.print("n = ");
        n = s.nextInt();

        p = new int[5];
        System.out.print("p = ");
        for (int i = 1; i <= n; i++) {
            p[i] = s.nextInt();
        }

        q = new int[5];
        System.out.print("q = ");
        for (int i = 0; i < n + 1; i++) {
            q[i] = s.nextInt();
        }
        
        a = new String[5];
        System.out.println("Enter the keywords:");
        for (int i = 0; i <= n; i++) {
            a[i] = s.nextLine();
        }
        System.out.println();
    }

    public void calculate() {
        w = new int[5][5];
        c = new int[5][5];
        r = new int[5][5];
        t = new int[5][5];
        
        int cnt = 0;

        for (int i = 0; i < 5; i++) {
            w[i][i] = q[i];
            c[i][i] = 0;
            r[i][i] = 0;
            t[i][i] = 0;
        }

        cnt = 1;
        int i = 0, j = 0;
        while (cnt <= n) {
            i = j = 0;
            while (j <= n) {
                j = cnt + i;
                int min = 99, h = 33, k = j;
                if (j <= n) {
                    while (k > i) {
                        w[i][j] = p[k] + w[i][k - 1] + w[k][j];
                        c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];

                        if (c[i][j] <= min) {
                            min = c[i][j];
                            h = k;
                        }
                        c[i][j] = min;
                        r[i][j] = h;
                        k--;
                    }
                }
                i++;
            }
            cnt++;
        }
        display();
        tree();
    }

    public void display() {
        for (int i = 0; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                System.out.print(" w[" + i + "]" + "[" + j + "]: " + w[i][j]);
                System.out.print("\tc: " + c[i][j]);
                System.out.println("\tr: " + r[i][j]);
            }
            System.out.println();
        }

    }

    public void tree() {
        t[0][n] = r[0][n];
        int i = 0;
        int j = n;
        int k = r[0][n];
        System.out.println("\t\t" + a[r[0][n]] + "\n\t");
        left(i, k - 1);
        System.out.print("\t\t");
        right(k, j);
    }

    public void right(int i, int j) {
        if (r[i][j] == 0)
            return;

        System.out.print(a[r[i][j]]);
        int k = r[i][j];
        
        System.out.print("\t\t");
        left(i, k - 1);
        
        System.out.print("\t\t");
        right(k, j);
    }

    public void left(int i, int j) {
        if (r[i][j] == 0)
            return;

        System.out.println(a[r[i][j]]);
        int k = r[i][j];
        
        left(i, k - 1);
        right(k, j);
    }

    public static void main(String args[]) {
        OBST o = new OBST();
        o.input();
        o.calculate();
    }
}
