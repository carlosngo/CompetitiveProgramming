
import java.io.*;
import java.util.*;
import java.math.*;

public class FUN2_B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter("out.txt", "UTF-8");
        PrintWriter out = new PrintWriter(System.out);
        String line;
        String[] split;
        int p = Integer.parseInt(br.readLine());
        while (p-- > 0) {
            split = br.readLine().split(" ");
            int ctr = Integer.parseInt(split[0]);
            int base = Integer.parseInt(split[1]);
            int n = Integer.parseInt(split[2]);
            BigInteger bigInt = new BigInteger(split[2], 10);
            int ans = 0;
            String s = bigInt.toString(base);
            for (int i = s.length() - 1; i >= 0; i--) {
                int digit = Character.getNumericValue(s.charAt(i));
                ans += digit * digit;
            }
            out.println(ctr + " " + ans);
        }
        pw.close();
        out.close();
        br.close();
    }
}
