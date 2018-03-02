package RKSir;

import com.sun.org.apache.xerces.internal.impl.dv.util.HexBin;

import javax.xml.bind.DatatypeConverter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.nio.*;
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

        testfuncs obj1 = new testfuncs();
        obj1.startMain();

    }

}
