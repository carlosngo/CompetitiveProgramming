
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class P495 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        BigInteger[] fibonacci = new BigInteger[5001];
        fibonacci[0] = new BigInteger("0");
        fibonacci[1] = new BigInteger("1");
        for (int i = 2; i < 5001; i++)
            fibonacci[i] = fibonacci[i - 1].add(fibonacci[i - 2]);
        String input;
        while ((input = br.readLine()) != null) {
            int n = Integer.parseInt(input);
            System.out.println("The Fibonacci number for " + n + " is " + fibonacci[n]);
        }
    }
}
