
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P10924 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        int cases;
        
        String input;
        while ((input = br.readLine()) != null) {
            if (!input.isEmpty()) {
                int sum = 0;
                for (int i = 0; i < input.length(); i++) {
                    char ch = input.charAt(i);
                    if (Character.isUpperCase(ch)) 
                        sum += ch - 38;
                    else
                        sum += ch - 96;
                }
                boolean prime = true;
                int n = sum;
                if (n % 2 == 0) 
                    prime = false;
                for (int i = 3; i <= (int)Math.sqrt(n) + 1; i+= 2) 
                    if (n % i == 0) 
                        prime = false;
                System.out.println(prime ? "It is a prime word." : "It is not a prime word.");
            }
        }
    }
}
