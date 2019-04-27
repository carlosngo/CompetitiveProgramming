
import java.io.*;
import java.util.*;
import java.math.*;


public class primes {
    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter("out.txt", "UTF-8");
        PrintWriter out = new PrintWriter(System.out);
        String line;
        String[] split;
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String input = br.readLine();
            int ans = 0;
            int poss = 0;
            try {
                BigInteger bin = new BigInteger(input, 2);
                poss++;
                if (bin.isProbablePrime(10)) ans++;
            } catch (NumberFormatException e) {}
            try {
                BigInteger oct = new BigInteger(input, 8);
                poss++;
                if (oct.isProbablePrime(10)) ans++;
            } catch (NumberFormatException e) {}
            try {
                BigInteger dec = new BigInteger(input);
                poss++;
                if (dec.isProbablePrime(10)) ans++;
            } catch (NumberFormatException e) {}
            try {
                BigInteger hex = new BigInteger(input, 16);
                poss++;
                if (hex.isProbablePrime(10)) ans++;
            } catch (NumberFormatException e) {}
            if (ans == 0) poss = 1;
            int gcd = gcd(ans, poss);
            out.println(ans / gcd + "/" + poss / gcd);
        }
        pw.close();
        out.close();
        br.close();
    }
}
