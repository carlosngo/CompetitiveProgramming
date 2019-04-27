
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class P10696 {
    public static long f91(long n) {
        if (n <= 100)
            return f91(f91(n + 11));
        else
            return n - 10;
    }
    
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        long n = Long.parseLong(br.readLine());
        while (n != 0) {
            System.out.println("f91(" + n + ") = " + f91(n));
            n = Long.parseLong(br.readLine());
        }
    }
}