package PA_09.myPackages;

import PA_09.myPackages.p1.minScale;

import java.util.Scanner;

public class IntegerArrayMethods {
    public static void main(String args[]) {
        int n, i, x;
        minScale a1 = new minScale(50);
        System.out.println("Enter the size of the array");
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        System.out.println("Enter the array");
        a1.getarray(n);
        System.out.println("Minimum element in the array is:");
        int small = a1.min(n);
        System.out.println(small);
        System.out.println("Maximum element in the array is:");
        int large = a1.max(n);
        System.out.println(large);
        System.out.println("Enter the scalar to multiply: ");
        Scanner s3 = new Scanner(System.in);
        x = s3.nextInt();
        a1.scale(n, x);
    }
}