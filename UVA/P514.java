
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;


public class P514 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        Stack<Integer> stack = new Stack<>();
        int n = Integer.parseInt(br.readLine());
        while (n != 0) {
            String input = br.readLine();
            while (!input.equals("0")) {
                boolean yes = true;
                stack.clear();
                String[] split = input.split("\\s+");
                int[] arr = new int[split.length];
                for (int i = 0; i < arr.length; i++)
                    arr[i] = Integer.parseInt(split[i]);
                int j = 0;
                for (int i = 1; i <= n && yes; i++) {
                    if (i <= arr[j]) {
                        stack.push(i);
                        if (i == arr[j]) {
                            stack.pop();
                            if (j < arr.length - 1) {
                                if (i > arr[j + 1]) {
                                    int k = arr[j];
                                    while (k > arr[j + 1] && yes) {
                                        if (stack.isEmpty())
                                            yes = false;
                                        else 
                                            if (stack.pop() != arr[j + 1])
                                                yes = false;
                                        k--;
                                        if (j != arr.length - 2)
                                            j++;
                                        else
                                            break;
                                    }
                                }
                            }
                            j++;
                        }
                    }
                }
                if (!stack.isEmpty() || j < arr.length - 1)
                    yes = false;
                System.out.println(yes ? "Yes" : "No");
                input = br.readLine();
            }
            System.out.println("");
            n = Integer.parseInt(br.readLine());
        }
    }
}
