
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class P10110 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        double n = Double.parseDouble(br.readLine());
        while (n != 0) {
            System.out.println(Math.ceil(Math.sqrt(n)) == Math.sqrt(n) ? "yes" : "no");
            n = Long.parseLong(br.readLine());
        }
    }
}
