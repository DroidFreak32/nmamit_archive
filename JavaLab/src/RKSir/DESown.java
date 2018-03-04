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
    private long k_plus[] = new long[17];
    private long l[] = new long[17];
    private long r[] = new long[17];
    private  String msg,key;
    private String cipherText = "";
    private long msgLong,keyLong,ipmsg,cipherTextLong;


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

    /**
     * PC2 Permutation.  The subkey generation process applies this
     * permutation to transform its running 56-bit keystuff value into
     * the final set of 16 48-bit subkeys.
     */
    private static final byte[] PC2 = {
            14, 17, 11, 24, 1,  5,
            3,  28, 15, 6,  21, 10,
            23, 19, 12, 4,  26, 8,
            16, 7,  27, 20, 13, 2,
            41, 52, 31, 37, 47, 55,
            30, 40, 51, 45, 33, 48,
            44, 49, 39, 56, 34, 53,
            46, 42, 50, 36, 29, 32
    };

    /**
     * Input Permutation.  The message block is permuted by this
     * permutation at the beginning of the algorithm.
     */
    private static final byte[] IP = {
            58, 50, 42, 34, 26, 18, 10, 2,
            60, 52, 44, 36, 28, 20, 12, 4,
            62, 54, 46, 38, 30, 22, 14, 6,
            64, 56, 48, 40, 32, 24, 16, 8,
            57, 49, 41, 33, 25, 17, 9,  1,
            59, 51, 43, 35, 27, 19, 11, 3,
            61, 53, 45, 37, 29, 21, 13, 5,
            63, 55, 47, 39, 31, 23, 15, 7
    };

    public long binStringToLong (String binString){
        // Replace the spaces
        binString = binString.replace(" ","");
        return Long.parseLong(binString,2);
    }

    public long hexStringToLong (String binString){
        // Replace the spaces
        binString = binString.replace(" ","");
        BigInteger bigInteger = new BigInteger(binString,16);
        return bigInteger.longValue();
    }

    public String toHex(String s){
        return String.format("%x", new BigInteger(1, s.getBytes(Charset.defaultCharset())));
    }

    public String padZeroes(String partMsg) {
        int len = partMsg.length();
        if(len < 16)
            for (int j = 0; j < (16-len); j++)
               partMsg = partMsg + "0";
        return partMsg;
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
            dst = (dst<<1) | (src>>>srcPos & 0x01);
        }
        return dst;
    }

    /**
     * c[i] and d[i] are 28 bits instead of long's 64 bit.
     * So C leftshifted by 28 bits, keeping first 8 bits of a long intact.
     * Since C is 28 bit long the first 4bits are always 0,
     * these get added to the leftshift and hence there are 8 0's int he beginning.
     * D's first bit is at the same position as the first 0 of C. (ie 33rd bit of long)
     * Now we can perform OR to get the final key again.
     */
    private long getKPlus(long c, long d) {
        long joined = (c&0xFFFFFFFFL)<<28 | (d&0xFFFFFFFFL);
        return joined;
    }


    /**
     * This function generates 16 subkeys from the initial provided keys.
     * Based on the current iteration number, the previous keys are either LShift'd 1 or 2 times.
     * The new subkey is generated from the above operation.
     */
    private void generateSubkeys(long c0, long d0) {
        for (int i = 1; i <= 16; i++) {
            if ((i == 1) || (i == 2) || (i == 9) || (i == 16) ){
                // rotate by 1 bit
                c[i] = ((c[i-1]<<1) & 0x0FFFFFFF) | (c[i-1]>>>27);
                d[i] = ((d[i-1]<<1) & 0x0FFFFFFF) | (d[i-1]>>>27);
            }
            else {
                // rotate by 2 bits
                c[i] = ((c[i-1]<<2) & 0x0FFFFFFF) | (c[i-1]>>>26);
                d[i] = ((d[i-1]<<2) & 0x0FFFFFFF) | (d[i-1]>>>26);
            }
            // join the two keystuff halves together.
            long cd = (c[i]&0xFFFFFFFFL)<<28 | (d[i]&0xFFFFFFFFL);
//            System.out.println("\n\nGenSubkeys: "+i);
//            displayLongValues(cd);

            k_plus[i] = permute(PC2,56,cd);
//            System.out.println("Subkeys: "+i);
//            displayLongValues(k_plus[i]); // Should display 48-Bit numbers

        }
    }



    private void generateEncryptedSubkeys() {
        for (int i = 1; i <= 16; i++) {
            l[i] = r[i-1];
            r[i] = l[i-1] ^ feistel(r[i-1],k_plus[i]);
        }

    }


    /**
     * Expansion Permutation.  The Feistel function begins by applying
     * this permutation to its 32-bit input half-block to create an
     * "expanded" 48-bit value.
     */
    private static final byte[] E = {
            32, 1,  2,  3,  4,  5,
            4,  5,  6,  7,  8,  9,
            8,  9,  10, 11, 12, 13,
            12, 13, 14, 15, 16, 17,
            16, 17, 18, 19, 20, 21,
            20, 21, 22, 23, 24, 25,
            24, 25, 26, 27, 28, 29,
            28, 29, 30, 31, 32, 1
    };

    /**
     * Substitution Boxes.  A crucial step in the Feistel function is
     * to perform bit substitutions according to this table.  A 48-bit
     * value is split into 6-bit sections, and each section is permuted
     * into a different 6-bit value according to these eight tables.
     * (One table for each section.)
     *
     *  According to Wikipedia:
     *  "The S-boxes provide the core of the security of DES - without
     *  them, the cipher would be linear, and trivially breakable."
     */
    private static final byte[][] SBox = { {
            14, 4,  13, 1,  2,  15, 11, 8,  3,  10, 6,  12, 5,  9,  0,  7,
            0,  15, 7,  4,  14, 2,  13, 1,  10, 6,  12, 11, 9,  5,  3,  8,
            4,  1,  14, 8,  13, 6,  2,  11, 15, 12, 9,  7,  3,  10, 5,  0,
            15, 12, 8,  2,  4,  9,  1,  7,  5,  11, 3,  14, 10, 0,  6,  13
    }, {
            15, 1,  8,  14, 6,  11, 3,  4,  9,  7,  2,  13, 12, 0,  5,  10,
            3,  13, 4,  7,  15, 2,  8,  14, 12, 0,  1,  10, 6,  9,  11, 5,
            0,  14, 7,  11, 10, 4,  13, 1,  5,  8,  12, 6,  9,  3,  2,  15,
            13, 8,  10, 1,  3,  15, 4,  2,  11, 6,  7,  12, 0,  5,  14, 9
    }, {
            10, 0,  9,  14, 6,  3,  15, 5,  1,  13, 12, 7,  11, 4,  2,  8,
            13, 7,  0,  9,  3,  4,  6,  10, 2,  8,  5,  14, 12, 11, 15, 1,
            13, 6,  4,  9,  8,  15, 3,  0,  11, 1,  2,  12, 5,  10, 14, 7,
            1,  10, 13, 0,  6,  9,  8,  7,  4,  15, 14, 3,  11, 5,  2,  12
    }, {
            7,  13, 14, 3,  0,  6,  9,  10, 1,  2,  8,  5,  11, 12, 4,  15,
            13, 8,  11, 5,  6,  15, 0,  3,  4,  7,  2,  12, 1,  10, 14, 9,
            10, 6,  9,  0,  12, 11, 7,  13, 15, 1,  3,  14, 5,  2,  8,  4,
            3,  15, 0,  6,  10, 1,  13, 8,  9,  4,  5,  11, 12, 7,  2,  14
    }, {
            2,  12, 4,  1,  7,  10, 11, 6,  8,  5,  3,  15, 13, 0,  14, 9,
            14, 11, 2,  12, 4,  7,  13, 1,  5,  0,  15, 10, 3,  9,  8,  6,
            4,  2,  1,  11, 10, 13, 7,  8,  15, 9,  12, 5,  6,  3,  0,  14,
            11, 8,  12, 7,  1,  14, 2,  13, 6,  15, 0,  9,  10, 4,  5,  3
    }, {
            12, 1,  10, 15, 9,  2,  6,  8,  0,  13, 3,  4,  14, 7,  5,  11,
            10, 15, 4,  2,  7,  12, 9,  5,  6,  1,  13, 14, 0,  11, 3,  8,
            9,  14, 15, 5,  2,  8,  12, 3,  7,  0,  4,  10, 1,  13, 11, 6,
            4,  3,  2,  12, 9,  5,  15, 10, 11, 14, 1,  7,  6,  0,  8,  13
    }, {
            4,  11, 2,  14, 15, 0,  8,  13, 3,  12, 9,  7,  5,  10, 6,  1,
            13, 0,  11, 7,  4,  9,  1,  10, 14, 3,  5,  12, 2,  15, 8,  6,
            1,  4,  11, 13, 12, 3,  7,  14, 10, 15, 6,  8,  0,  5,  9,  2,
            6,  11, 13, 8,  1,  4,  10, 7,  9,  5,  0,  15, 14, 2,  3,  12
    }, {
            13, 2,  8,  4,  6,  15, 11, 1,  10, 9,  3,  14, 5,  0,  12, 7,
            1,  15, 13, 8,  10, 3,  7,  4,  12, 5,  6,  11, 0,  14, 9,  2,
            7,  11, 4,  1,  9,  12, 14, 2,  0,  6,  10, 13, 15, 3,  5,  8,
            2,  1,  14, 7,  4,  10, 8,  13, 15, 12, 9,  0,  3,  5,  6,  11
    } };

    private long getS(int boxNumber, byte src) {
        // abcdef => afbcde
        // row = af, col = bcde;
        byte newsrc;
        newsrc = (byte) (src&0x20); // Get the first bit and make it newsrc's first
        newsrc = (byte) (newsrc | ((src&0x01)<<4)); // get the 6th bit, leftshift it by 4 bits to make it newsrc's 2nd char
        newsrc = (byte) (newsrc | ((src&0x1E)>>1)); // get the 2-5 bits, shift them all 1 bit to the right to make it newsrc's 3-6 bit resp.
//        System.out.println("BoxNo = "+boxNumber);
        return SBox[boxNumber-1][newsrc];
    }


    private long getSBoxOutput(long k_xor_e) {
        long src,dst;
        byte k_byte;
        dst = 0;
        for (int i = 0; i < 8; i++) {
            dst>>>=4;
            // Convert to byte so we just have to handle 8bits instead of 64.
            k_byte = (byte) (k_xor_e&0x3F); // Get the last 6 chars
            long s = getS(8-i, k_byte);
            dst |= s << 28;
            k_xor_e>>=6;
        }
        return permute(P,32,dst);
    }


    /**
     * "P" Permutation.  The Feistel function concludes by applying this
     * 32-bit permutation to the result of the S-box substitution, in
     * order to spread the output bits across 6 different S-boxes in
     * the next round.
     */
    private static final byte[] P = {
            16, 7,  20, 21,
            29, 12, 28, 17,
            1,  15, 23, 26,
            5,  18, 31, 10,
            2,  8,  24, 14,
            32, 27, 3,  9,
            19, 13, 30, 6,
            22, 11, 4,  25
    };

    private long feistel(long r__n_minus_1, long k_plus_n) {
        long e,k_xor_e,sBoxOutPut;

        e = permute(E,32,r__n_minus_1);
//        System.out.println("\nXOR OPERATION: "+Long.toString(e)+" XOR "+Long.toString(k_plus_n));
        k_xor_e = k_plus_n ^ e;

        sBoxOutPut = getSBoxOutput(k_xor_e);
        return sBoxOutPut;

    }

    /**
     * Final Permutation.  The final result is permuted by this
     * permutation to generate the final ciphertext block.
     */
    private static final byte[] FP = {
            40, 8, 48, 16, 56, 24, 64, 32,
            39, 7, 47, 15, 55, 23, 63, 31,
            38, 6, 46, 14, 54, 22, 62, 30,
            37, 5, 45, 13, 53, 21, 61, 29,
            36, 4, 44, 12, 52, 20, 60, 28,
            35, 3, 43, 11, 51, 19, 59, 27,
            34, 2, 42, 10, 50, 18, 58, 26,
            33, 1, 41, 9, 49, 17, 57, 25
    };

    private Long des(String msg){


        msgLong = hexStringToLong(msg);
//        displayLongValues(msgLong);
        // Now to get the remaining 16 subkeys
        generateSubkeys(c[0],d[0]);

        // Step 2: Encode each 64-bit block of data.
        ipmsg = permute(IP,64, msgLong);
//        System.out.println("\n\nIP message:");
//        displayLongValues(ipmsg);

        // Split IPmsg to 2 halves
        l[0] = (long) (ipmsg>>>32);
        r[0] =  (ipmsg&0xFFFFFFFFL);
//        System.out.println("\nTwoHalves ");
//        displayLongValues(l[0]);
//        displayLongValues(r[0]);

        generateEncryptedSubkeys();

        // reverse the two 32-bit segments (left to right; right to left)
        long rl = (r[16]&0xFFFFFFFFL)<<32 | (l[16]&0xFFFFFFFFL);

//        System.out.println("\n\n\n\nR16,l16");
//        displayLongValues(r[16]);
//        displayLongValues(l[16]);


        // apply the final permutation
        long fp = permute(FP,64,rl);

        System.out.println("\n\n\nFINAL: ");
        displayLongValues(fp);

        return fp;

    }
    private void start() {
        String partMsg;
        int strlength = msg.length();
        if (strlength > 16 ){

            int chunksRequired = (int) Math.ceil(strlength / (float)16);
            String[] stringArray = new String[chunksRequired];
            int lengthRemaining = strlength;
            for (int i = 0; i < chunksRequired; i++)
            {

                int lengthToUse = min(lengthRemaining, 16);
                int startIndex = 16 * i;

                stringArray[i] = msg.substring(startIndex, startIndex+lengthToUse);

                lengthRemaining = lengthRemaining - lengthToUse;

            }
            for (int i = 0; i < stringArray.length; i++) {
                partMsg = stringArray[i];
                partMsg = padZeroes(partMsg);
                cipherTextLong = des(partMsg);
                cipherText += Long.toHexString(cipherTextLong);
            }
        }
        else {
            msg = padZeroes(msg);
            System.out.println("Message: "+msg);
            cipherTextLong = des(msg);
            cipherText = Long.toHexString(cipherTextLong);
        }
        System.out.println("\n\n\n\nCipherText: "+cipherText);

    }

    private void getData() {

        Scanner scanner = new Scanner(System.in);

// Step 1: Create 16 subkeys, each of which is 48-bits long.
        System.out.println("Enter equiv hex");
        msg = scanner.nextLine();
//        msg = "0123456789ABCDEF";
        System.out.println("OrigMsg: "+msg);
        msg = toHex(msg);
        System.out.println("Now: "+msg);

        System.out.println("Enter key hex");
//        key = scanner.nextLine();
        key = "133457799BBCDFF1";
        keyLong = hexStringToLong(key);
//        displayLongValues(keyLong);

        k_plus[0] = permute(PC1,64,keyLong);
//        System.out.println("\nk_plus:");
//        displayLongValues(k_plus[0]);

//        System.out.println("Splitting keys: ");
        // First half
        c[0] = k_plus[0]>>>28;
        // Second half, only final 7 bits are identical (7*f).
        d[0] = (k_plus[0]&0x0FFFFFFF);
        k_plus[0] = getKPlus(c[0],d[0]);
//        System.out.println("c: ");
//        displayLongValues(c[0]);
//        System.out.println("d: ");
//        displayLongValues(d[0]);
//        displayLongValues(k_plus[0]);
        start();
    }


    public static void main(String[] args) {
        DESown obj1 = new DESown();
        obj1.getData();
    }

    public int min (int n1, int n2){
        if (n1 < n2)
            return n1;
        else
            return n2;
    }

}
