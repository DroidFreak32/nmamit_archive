package RKSir;
/*
 * Copyright 2011 David Simmons
 * http://cafbit.com/entry/implementing_des
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import java.math.BigInteger;
import java.nio.charset.Charset;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Super-slow DES implementation for the overly patient.
 *
 * The following resources proved valuable in developing and testing
 * this code:
 *
 * "Data Encryption Standard" from Wikipedia, the free encyclopedia
 * http://en.wikipedia.org/wiki/Data_Encryption_Standard
 *
 * "The DES Algorithm Illustrated" by J. Orlin Grabbe
 * http://orlingrabbe.com/des.htm
 *
 * "DES Calculator" by Lawrie Brown
 * http://www.unsw.adfa.edu.au/~lpb/src/DEScalc/DEScalc.html
 *
 * April 6, 2011
 *
 * @author David Simmons - http://cafbit.com/
 *
 */
public class DESown {

    private long c[] = new long[17];
    private long d[] = new long[17];

    /**
     * PC1 Permutation.  The supplied 64-bit key is permuted according
     * to this table into a 56-bit key.  (This is why DES is only a
     * 56-bit algorithm, even though you provide 64 bits of key
     * material.)
     */
    private static final byte[] PC1 = {
            57, 49, 41, 33, 25, 17, 9,
            1,  58, 50, 42, 34, 26, 18,
            10, 2,  59, 51, 43, 35, 27,
            19, 11, 3,  60, 52, 44, 36,
            63, 55, 47, 39, 31, 23, 15,
            7,  62, 54, 46, 38, 30, 22,
            14, 6,  61, 53, 45, 37, 29,
            21, 13, 5,  28, 20, 12, 4
    };

    public long binStringToLong (String binString){
        // Replace the spaces
        binString = binString.replace(" ","");
        return Long.parseLong(binString,2);
    }

    public long hexStringToLong (String binString){
        // Replace the spaces
        binString = binString.replace(" ","");
        return Long.parseLong(binString,16);
    }


    private void displayLongValues(long disp){
        System.out.println("Long value: "+disp);
        System.out.println("Hex value: "+Long.toHexString(disp));
    }

    /**
     * Permute an input value "src" of srcWidth bits according to the
     * supplied permutation table.  (Note that our permutation tables,
     * supplied by Wikipedia, start counting with the left-most bit as
     * "1".)
     */
    private static long permute(byte[] table, int srcWidth, long src) {
        long dst = 0;
        for (int i=0; i<table.length; i++) {
            int srcPos = srcWidth - table[i];
            dst = (dst<<1) | (src>>srcPos & 0x01);
        }
        return dst;
    }

    /**
     * Since c[i] and d[i] are 28 bits instead of long's 64 bit.
     * So C leftshifted by 28 bits.
     * D is rightshifted by 36 bits so that the first bit of D
     * is at the same position as the first 0 of C.
     * Now we can perform OR to get the final key again.
     */
    private long getKPlus(long c, long d) {
        return (c<<28 | d>>36);
    }

    private void start() {
        String msg,key;
        long m,disp,l,r,k;

        Scanner scanner = new Scanner(System.in);


        System.out.println("Enter equiv hex");
//        msg = scanner.nextLine();
        msg = "0123456789ABCDEF";
        m = hexStringToLong(msg);
        displayLongValues(m);

        l = m>>32;
        displayLongValues(l);

        r = m<<32;
        displayLongValues(r);


        System.out.println("Enter key hex");
//        key = scanner.nextLine();
        key = "133457799BBCDFF1";
        k = hexStringToLong(key);
        displayLongValues(k);

        long k_plus = permute(PC1,64,k);
        System.out.println("\nk_plus:");
        displayLongValues(k_plus);

        System.out.println("Splitting keys: ");
        c[0] = k_plus>>28;
        d[0] = k_plus<<36;
        k_plus = getKPlus(c[0],d[0]);
        System.out.println("c: ");
        displayLongValues(c[0]);
        System.out.println("d: ");
        displayLongValues(d[0]);
        displayLongValues(k_plus);

    }


    public static void main(String[] args) {
        DESown obj1 = new DESown();
        obj1.start();
    }


}
