
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P10340 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        boolean found;
        boolean yes;
        int prev;
        String[] split;
        String input;
        String s1, s2;
        while ((input = br.readLine()) != null) {
            split = input.split(" ");
            s1 = split[0];
            s2 = split[1];
            yes = true;
            prev = -1;
            for (int i = 0; i < s1.length() && yes; i++) {
                char ch = s1.charAt(i);
                found = false;
                for (int j = prev + 1; j < s2.length() && !found; j++) {
                    if (s2.charAt(j) == ch) {
                        found = true;
                        prev = j;
                    }
                }
                if (!found)
                    yes = false;
            }
            System.out.println(yes ? "Yes" : "No");
        }
    }
}
