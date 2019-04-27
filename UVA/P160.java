import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P160 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        
        int[] primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
        int[] factors;
        int input = Integer.parseInt(br.readLine());
        while (input != 0) {
            factors = new int[25];
            for (int i = 0; i < 25; i++)
                factors[i] = 0;
            for (int i = 2; i <= input; i++) {
                int temp = i;
                for (int j = 0; temp != 1; j++) {
                    while (temp % primes[j] == 0) {
                        temp /= primes[j];
                        factors[j]++;
                    }
                }
            }
            System.out.printf("%3d! = ", input);
            for (int i = 0; i < 25; i++) {
                if (factors[i] == 0)
                    break;
                else
                    System.out.printf("%2d", factors[i]);
                if (i + 1 != 25)
                    if (factors[i + 1] != 0 && i != 14)
                        System.out.print(" ");
                if (i == 14) {
                    if (factors[i + 1] != 0) {
                        System.out.println("");
                        System.out.print("       ");
                    }
                }
            }
            System.out.println("");
            input = Integer.parseInt(br.readLine());
        }
    }
}