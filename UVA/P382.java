
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;

public class P382 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        Scanner sc = new Scanner(System.in);
        int cases;
        int sum;
        ArrayList<Integer> nums = new ArrayList<>();
        int m = sc.nextInt();
        while (m != 0) {
            nums.add(m);
            m = sc.nextInt();
        }
        System.out.println("PERFECTION OUTPUT");
        for (int i = 0; i < nums.size(); i++) {
            int n = nums.get(i);
            if (n != 1)
                sum = 1;
            else
                sum = 0;
            for (int j = 2; j <= Math.sqrt(n); j++) {
                if (n % j == 0) {
                    sum += j;
                    if (n / j != j)
                        sum += n / j;
                }
            }
            if (sum == n)
                System.out.printf("%5d  PERFECT\n", n);
            else if (sum > n)
                System.out.printf("%5d  ABUNDANT\n", n);
            else
                System.out.printf("%5d  DEFICIENT\n", n);
        }
        System.out.println("END OF OUTPUT");
    }
}
