
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class P10929 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        int cases;
        BigInteger n;
        String input = br.readLine();
        input = input.trim();
        while (!input.equals("0")) {
            n = new BigInteger(input);
            BigInteger output = n.mod(new BigInteger("11"));
            if (output.compareTo(new BigInteger("0")) == 0)
                System.out.println(input + " is a multiple of 11.");
            else
                System.out.println(input + " is not a multiple of 11.");
            input = br.readLine();
            input = input.trim();
        }
    }
}
