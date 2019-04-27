
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P445 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String input;
        int times;
        int[] stack;
        while ((input = br.readLine()) != null) {
            if (!input.isEmpty()) {
                stack = new int[input.length()];
                int top = -1;
                for (int i = 0; i < input.length(); i++) {
                    times = 0;
                    char ch = input.charAt(i);
                    if (Character.isDigit(ch)) 
                        stack[++top] = ch;
                    else {
                        if (ch == '!')
                            System.out.println();
                        while (top != -1) 
                            times += Character.getNumericValue(stack[top--]);
                        while (times-- > 0) {
                            if (ch == 'b')
                                System.out.print(" ");
                            else 
                                System.out.print(ch);
                        }
                    }
                }
                System.out.println("");
            } else 
                System.out.println("");
        }
    }
}
