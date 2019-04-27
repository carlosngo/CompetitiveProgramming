
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P488 {
    public static void main(String[] args) throws IOException {
        int a, f;
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        int cases = Integer.parseInt(br.readLine());
        while (cases-- > 0) {
            br.readLine();
            a = Integer.parseInt(br.readLine());
            f = Integer.parseInt(br.readLine());
            while (f-- > 0) {
                for (int i = 1; i <= a; i++) {
                    for (int j = 0; j < i; j++) 
                        System.out.print(i);
                    System.out.println("");
                }
                for (int i = a - 1; i >= 1; i--) {
                    for (int j = 0; j < i; j++)
                        System.out.print(i);
                    System.out.println("");
                }
                if (f > 0)
                    System.out.println("");
            }
            if (cases > 0)
                System.out.println("");
        }
    }
}
