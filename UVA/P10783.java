
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


class Main {
    public static void main(String[] args) {
        int cases;
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String input;
        int min, max;
        long sum;
        try {
            cases = Integer.parseInt(br.readLine());
            for (int i = 1; i <= cases; i++) {
                sum = 0;
                min = Integer.parseInt(br.readLine());
                max = Integer.parseInt(br.readLine());
                if (min % 2 == 0)
                    min++;
                for (int j = min; j <= max; j += 2)
                    sum += j;
                System.out.println("Case " + i + ": " + sum);
            }
        } catch (IOException ioe) {
            System.out.println("Input Error.");
        }     
    }
    
}
