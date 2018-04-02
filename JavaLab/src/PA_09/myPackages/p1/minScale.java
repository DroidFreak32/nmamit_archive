package PA_09.myPackages.p1;

import java.util.Scanner;

public class minScale {
    int a[], size;

    public minScale(int size) {
        a = new int[size];
    }

    public void getarray(int n) {
        int i;
        for (i = 0; i < n; i++) {
            Scanner s = new Scanner(System.in);
            a[i] = s.nextInt();
        }
    }

    public int min(int n) {
        int small, i;
        small = a[0];
        for (i = 1; i < n; i++) {
            if (a[i] < small) {
                small = a[i];
            }
        }
        return (small);
    }

    public int max(int n) {
        int max, i;
        max = a[0];
        for (i = 1; i < n; i++) {
            if (a[i] > max) {
                max = a[i];
            }
        }
        return (max);
    }

    public void scale(int n, int x) {
        int i;
        for (i = 0; i < n; i++)
            a[i] = a[i] * x;
        System.out.println("Multiplied array");
        for (i = 0; i < n; i++) {
            System.out.println(a[i]);
        }
    }
}