
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem10035 {
    public static void main(String[] args) {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        long num1, num2;
        int carry;
        int ops;
        String[] nums;
        try {
            while ((nums = br.readLine().split(" ")) != null) {
                ops = 0;
                carry = 0;
                num1 = Integer.valueOf(nums[0]);
                num2 = Integer.valueOf(nums[1]);
                if (num1 == 0 && num2 == 0)
                    break;
                while (num1 > 0 || num2 > 0) {
                    if (num1 % 10 + num2 % 10 + carry > 9) {
                        ops++;
                        carry = 1;
                    } else
                        carry = 0;
                    num1 /= 10;
                    num2 /= 10;
                }
                if (ops == 0)
                    System.out.println("No carry operation.");
                else if (ops == 1)
                    System.out.println("1 carry operation.");
                else
                    System.out.println(ops + " carry operations.");
            }
        } catch (IOException ioe) {
            
        }
    }
}
