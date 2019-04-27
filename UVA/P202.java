
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P202 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        
        String input;
        String[] split;
        while ((input = br.readLine()) != null) {
            split = input.split("\\s+");
            int a = Integer.parseInt(split[0]);
            int b = Integer.parseInt(split[1]);
            boolean found = false;
            int cLength = 0;
            Stack<IntObj> stack = new Stack<>();
            StringBuilder output = new StringBuilder();
            int difference, x, y;
            x = a;
            y = b;
            if (a > b) {
                x = x - b * (a / b);
                output.append(a / b + ".");
            } else
                output.append(0 + ".");
            while (!found) {
                // if divisible, break
                if (x % y == 0) {
                    output.append("(0)");
                    cLength = 1;
                    break;
                }
                // add zeroes to x while it's less than y
                while (x < y) {
                    x *= 10;
                    if (x / y == 0) {
                        
                        IntObj i = new IntObj(x);
                        if (!stack.contains(i)) {
                            output.append("0");
                            stack.add(new IntObj(x));
                        } else {                    
                            found = true;
                            output.append(")");
                            while (!stack.pop().equals(i)) 
                                cLength++;
                            break;
                        }
                    }
                }
                if (!found) {
                    IntObj i = new IntObj(x);
                    if (!stack.contains(i))
                        stack.add(new IntObj(x));
                    else {                    
                        found = true;
                        output.append(")");
                        while (!stack.pop().equals(i)) 
                            cLength++;
                    }
                }
                if (!found) {
                    output.append(x / y + "");
                    x = x - y * (x / y);
                } else {
                    cLength++;
                    String subs1 = output.substring(0, output.length() - 1 - cLength);
                    String subs2 = output.substring(output.length() - 1 - cLength, output.length());
                    output = new StringBuilder(subs1 + "(" + subs2);
                    
                }
            }
            if (output.length() > 54) {
                int index = output.indexOf(".");
                String subs1 = output.substring(0, index);
                String subs2 = output.substring(index + 1, index + 52);
                if (output.substring(index + 1, index + 53).charAt(51) == ')')
                    System.out.println(a + "/" + b + " = " + subs1 + "." + subs2 + ")");
                else if (subs2.length() == 51)
                    System.out.println(a + "/" + b + " = " + subs1 + "." + subs2 + "...)");
                else
                    System.out.println(a + "/" + b + " = " + subs1 + "." + subs2 + ")");
            } else
                System.out.println(a + "/" + b + " = " + output);
            System.out.println("   " + cLength + " = number of digits in repeating cycle");
            System.out.println("");
        }
    }
    
    static class IntObj {
        int val;
        
        public IntObj(int val) {
            this.val = val;
        }
        
        @Override
        public boolean equals(Object o) {
            IntObj i = (IntObj)o;
            return i.val == this.val;
        }
    }
}
