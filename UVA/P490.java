
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P490 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String[] sentences = new String[100];
        String input;
        int elem = 0;
        int max = 0;
        while ((input = br.readLine()) != null) {
            sentences[elem++] = input;
            if (input.length() > max)
                max = input.length();
        }
        for (int i = 0; i < max; i++) {
            for (int j = elem - 1; j >= 0; j--) {
                if (i < sentences[j].length() && sentences[j].charAt(i) != '\t')
                    System.out.print(sentences[j].charAt(i));
                else
                    System.out.print(" ");
            }
            System.out.println("");
        }
    }
}
