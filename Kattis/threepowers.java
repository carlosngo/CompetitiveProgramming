
import java.io.*;
import java.util.*;
import java.math.*;

public class threepowers {
    public static long pow2(int exp) {
        long prod = 1;
        for (int i = 0; i < exp; i++) {
            prod *= 2;
        }
        return prod;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter("out.txt", "UTF-8");
        PrintWriter out = new PrintWriter(System.out);
        String line;
        String[] split;
        BigInteger n;
        line = br.readLine();
        while (!line.equals("0")) {
            n = new BigInteger(line);
            n = n.subtract(new BigInteger("1"));
            int ctr = 0;
            out.print("{");
            for (int i = 0; i < 64; i++) {
                BigInteger pow2 = new BigInteger("0");
                pow2 = pow2.setBit(i);
                if (!(n.and(pow2).equals(new BigInteger("0")))) {
                    if (ctr > 0) out.print(",");
                    BigInteger pow3 = new BigInteger("3");
                    pow3 = pow3.pow(i);
                    out.print(" " + pow3.toString());
                    ctr++;
                }
            }
            out.println(" }");
            line = br.readLine();
        }
        pw.close();
        out.close();
        br.close();
    }
}
