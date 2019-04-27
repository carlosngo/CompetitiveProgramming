
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P374 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        long b, p, m;
        String input;
        String[] split;
        while ((input = br.readLine()) != null) {
            if (input.equals(""))
                input = br.readLine();
            b = Integer.parseInt(input);
            p = Integer.parseInt(br.readLine());
            m = Integer.parseInt(br.readLine());
            long x = b;
            while (b < m)
                b *= x;
            System.out.println(b);
            if (p % 2 == 1)
                System.out.println(b % m);
            else
                System.out.println(b * x % m);
        }
        
    }
}
