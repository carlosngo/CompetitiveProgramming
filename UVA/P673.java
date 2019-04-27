
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P673 {
    public static void main(String[] args) throws IOException {
        char[] stack;
        String input;
        int top;
        boolean yes;
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        int cases = Integer.parseInt(br.readLine());
        while (cases-- > 0) {
            yes = true;
            top = -1;
            input = br.readLine();
            stack = new char[input.length()];
            for (int i = 0; i < input.length() && yes; i++) {
                if (input.charAt(i) == '(' || input.charAt(i) == '[') 
                    stack[++top] = input.charAt(i);
                else if (top == -1)
                    yes = false;
                else if (input.charAt(i) == ')') {
                    if (stack[top] != '(')
                        yes = false;
                    top--;
                } else if (input.charAt(i) == ']') {
                    if (stack[top] != '[')
                        yes = false;
                    top--;
                }
            }
            if (top != -1)
                yes = false;
            System.out.println(yes ? "Yes" : "No");  
        }
    }
}
