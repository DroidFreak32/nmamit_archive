package RKSir;

import com.sun.org.apache.xerces.internal.impl.dv.util.HexBin;

import javax.xml.bind.DatatypeConverter;
import java.io.*;
import java.math.BigInteger;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Scanner;
import java.nio.*;
import java.time.*;
class testfuncs {


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





    private static void dump1() {
        Scanner scanner = new Scanner(System.in);
        testfuncs obj1 = new testfuncs();
//        obj1.startMain();
        String str;
        str = scanner.nextLine();
        int strlength = str.length();
        System.out.println(str.length());
        if (strlength >16 ){

            int chunksRequired = (int) Math.ceil(strlength / (float)16);
            String[] stringArray = new String[chunksRequired];
            int lengthRemaining = strlength;
            for (int i = 0; i < chunksRequired; i++)
            {

                int lengthToUse = min(lengthRemaining, 16);
                int startIndex = 16 * i;

                stringArray[i] = str.substring(startIndex, startIndex+lengthToUse);

                lengthRemaining = lengthRemaining - lengthToUse;

            }
            for (int i = 0; i < stringArray.length; i++) {
                System.out.println("SubString: "+(i+1)+" Length :"+stringArray.length);
                System.out.println(stringArray[i]);

            }
        }


    }

    private static int min(int a, int b) {
        if (a<b)
            return a;
        else
            return b;
    }

    private void startMain() {
        Scanner scanner = new Scanner(System.in);
//        System.out.println("ENter message");
//        String str = scanner.next();
//        byte[] buf = DatatypeConverter.parseHexBinary(str);
//        System.out.println("Length of byte array: "+buf.length);
//        long l=0;
//        for (int i = 0; i < 8; i++) {
//            byte value;
//            if ((i) < buf.length) {
//                value = buf[i];
//            } else {
//                value = 0;
//            }
//            l = l<<8;
//            l = l | (value & 0xFFL);
//        }
//        System.out.println("Long value: "+l);
//        BigInteger bi = new BigInteger(str, 16);
//        System.out.println(bi);
//        byte newByte[] = ByteBuffer.allocate(8).putLong(bi.longValueExact()).array();
//        System.out.println("\n\nCompare:\n");
//        System.out.println(Arrays.toString(buf));
//        System.out.println(Arrays.toString(newByte));
        System.out.println("Enter 64bit binary");
        String bin = scanner.nextLine();
        long binLong = binStringToLong(bin);
        long disp = binLong;
        System.out.println("Long value: "+disp);
        System.out.println("Hex value: "+Long.toHexString(disp));

        System.out.println("Enter equiv hex");
        bin = scanner.nextLine();
        binLong = hexStringToLong(bin);
        disp = binLong;
        System.out.println("Long value: "+disp);
        System.out.println("Hex value: "+Long.toHexString(disp));

        disp = binLong>>32;
        System.out.println("Long value: "+disp);
        System.out.println("Hex value: "+Long.toHexString(disp));

        disp = binLong<<32;
        System.out.println("Long value: "+disp);
        System.out.println("Hex value: "+Long.toHexString(disp));
    }









    public static void main(String[] args) {
//        dump1();
//        dump2();
        int a = 0x0;
        int b = 0x0;
        long XOR[][] = new long[256][256];

        while (a <= 255) {
            while (b <= 255) {
//                System.out.println(Integer.toHexString(a) + " (" + Integer.toBinaryString(a) + ") XOR "
//                        + Integer.toHexString(b) + " (" + Integer.toBinaryString(b) + ")");
//                System.out.println(Integer.toHexString(a ^ b) + " (" + Integer.toBinaryString(a ^ b) + ")\n\n");
                XOR[a][b] = (a^b);
                b++;
            }
            System.out.println("increment a");
            a++;
            b = 0x0;

        }
        System.out.println("TABLE: ");
        for (int i = 0x0; i < XOR.length; i++) {
            System.out.println();
            for (int j = 0; j < XOR.length; j++) {
                System.out.print(Long.toHexString(XOR[i][j])+"\t");
            }

        }
        long x,y,ANS=0,temp;
        long startTime = System.nanoTime();
        long temp1 = Long.parseLong("01110010",2);
        long temp2 = Long.parseLong("01010101",2);
        System.out.println("Initial: ");
        System.out.println(Long.toHexString(temp1));
        System.out.println(Long.toHexString(temp2));
        long tmp = temp1>>(4);
        long tmp2 = temp2>>(4);
        ANS |= XOR[(int)tmp][(int)tmp2];
        ANS <<=8;
        tmp = temp1;
        tmp2 = temp2;
        tmp2 = tmp2 & 0x0FFL;
        tmp = tmp & 0x0FFL;
        ANS |= XOR[(int)tmp][(int)tmp2];
//        System.out.println(Long.toHexString(ANS));
//        ANS <<=8;
//        tmp = temp1>>(4*6);
//        tmp2 = temp2>>(4*6);
//        tmp2 = tmp2 & 0x0FFL;
//        tmp = tmp & 0x0FFL;
//        ANS |= XOR[(int)tmp][(int)tmp2];
//        ANS <<=8;
//        tmp = temp1>>(4*4);
//        tmp2 = temp2>>(4*4);
//        tmp2 = tmp2 & 0x0FFL;
//        tmp = tmp & 0x0FFL;
//        ANS |= XOR[(int)tmp][(int)tmp2];
//        ANS <<=8;
//        tmp = temp1>>(4*2);
//        tmp2 = temp2>>(4*2);
//        tmp2 = tmp2 & 0x0FFL;
//        tmp = tmp & 0x0FFL;
//        ANS |= XOR[(int)tmp][(int)tmp2];
//        ANS <<=8;
//        tmp2 = tmp2 & 0x0FFL;
//        tmp = tmp & 0x0FFL;
        ANS |= XOR[(int)tmp][(int)tmp2];
        long endTime = System.nanoTime();
        ANS <<=8;
        System.out.println("Manual Time = "+(endTime-startTime));


        startTime = System.nanoTime();
        long ans2 = temp1^temp2;
        endTime = System.nanoTime();
        System.out.println("Actual Time = "+(endTime-startTime));


        long x1 = temp1%256;
        long y1 = temp2%256;
        System.out.println(Long.toHexString(ANS));
        System.out.println(Long.toHexString(temp1^temp2));
    }

    public static void dump2() {
            int i;
            Path currentRelativePath = Paths.get("");
            String s = currentRelativePath.toAbsolutePath().toString();
            System.out.println("Current path is: " + s);
            BufferedReader reader = null;
            try {
                reader = new BufferedReader(new FileReader("../../../test.cpp"));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
            try {
                s = reader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            while (s != null) {
                System.out.println(s);
                try {
                    s = reader.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

}
