
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P694 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String input = br.readLine().trim();
        String[] split = input.split("\\s+");
        long a = Long.parseLong(split[0]);
        int l = Integer.parseInt(split[1]);
        int terms;
        int i = 1;
        while (!(a < 0 && l < 0)) {
            System.out.print("Case " + i + ": A = " + a);
            terms = 0;
            while (a <= l && a != 1) {
                if (a % 2 == 0) 
                    a /= 2;
                else
                    a = 3 * a + 1;
                terms++;
                if (a == 1)
                    terms++;
            }
            System.out.println(", limit = " + l + ", number of terms = " + terms);
            input = br.readLine().trim();
            split = input.split("\\s+");
            a = Long.parseLong(split[0]);
            l = Integer.parseInt(split[1]);
            i++;
        }
    }
}
