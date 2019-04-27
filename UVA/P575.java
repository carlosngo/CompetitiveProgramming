
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P575 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        int cases;
        String input = br.readLine();
        long sum;
        while (!input.equals("0")) {
            sum = 0;
            int i = 0;
            for (int k = input.length() - 1; k >= 0; k--) {
                sum += Character.getNumericValue(input.charAt(i)) * (Math.pow(2, k + 1) - 1);
                i++;
            }
            System.out.println(sum);
            input = br.readLine();
        }
    }
}
