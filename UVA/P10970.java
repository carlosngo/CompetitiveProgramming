
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P10970 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        int cases;
        String[] split;
        int m, n;
        String input;
        while ((input = br.readLine()) != null) {
            split = input.split("\\s+");
            m = Integer.parseInt(split[0]);
            n = Integer.parseInt(split[1]);
            System.out.println((m - 1) + (n - 1) * m);
        }
    }
}
