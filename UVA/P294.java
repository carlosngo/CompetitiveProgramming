
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P294 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        int cases = Integer.parseInt(br.readLine());
        while (cases-- > 0) {
             String[] split = br.readLine().split("\\s+");
             int l = Integer.parseInt(split[0]);
             int u = Integer.parseInt(split[1]);
             int max = 0;
             int num = l;
             for (int i = l; i <= u; i++) {
                 int divisors = 1;
                 int exponent = 0;
                 int n = i;
                 while (n % 2 == 0 && n > 1) {
                     n /= 2;
                     exponent++;
                 }
                 divisors *= exponent + 1;
                 int sqrt = (int)Math.sqrt(n);
                 for (int j = 3; j <= sqrt; j += 2) {
                     exponent = 0;
                     while (n % j == 0 && n > 1) {
                         n /= j;
                         exponent++;
                     }
                     divisors *= exponent + 1;
                     sqrt = (int)Math.sqrt(n);
                 }
                 
                 if (n != 1) 
                     divisors *= 2;
                 
                 if (divisors > max) {
                     max = divisors;
                     num = i;
                 }
             }
             System.out.println("Between " + l + " and " + u + ", " + num + " has a maximum of " + max + " divisors.");
        }
       
    }
}
