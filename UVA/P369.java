
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class P369 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String input = br.readLine().trim();
        String[] split = input.split("\\s+");
        BigInteger nf, mf;
        int m, n;
        int x;
        while (!(split[0].equals("0") && split[1].equals("0"))) {
            nf = new BigInteger("1");
            mf = new BigInteger("1");
            n = Integer.parseInt(split[0]);
            m = Integer.parseInt(split[1]);
            if (m >= n / 2) {
                x = m;
                for (int i = 2; i <= n - m; i++)
                    mf = mf.multiply(new BigInteger(Integer.toString(i)));
            } else {
                x = n - m;
                for (int i = 2; i <= m; i++)
                    mf = mf.multiply(new BigInteger(Integer.toString(i)));
            }
            for (int i = x + 1; i <= n; i++) {
                nf = nf.multiply(new BigInteger(Integer.toString(i)));
            }
            System.out.println(n + " things taken " + m + " at a time is " + nf.divide(mf) + " exactly.");
            input = br.readLine().trim();
            split = input.split("\\s+");
        }
    }
}
