import java.io.*;
import java.util.*;
import java.math.*;

public class CF571C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String a = br.readLine();
        String b = br.readLine();
        BigInteger y = new BigInteger(b, 2);
        long ans = 0;
        
        for (int i = 0; i < a.length(); i++) {
            if (i + b.length() > a.length()) break;
            BigInteger x = new BigInteger(a.substring(i, (i + b.length())), 2);
            if (x.xor(y).bitCount() % 2 == 0) ans++;
        }
        out.print(ans);
        out.close();
        br.close();
    }
}
