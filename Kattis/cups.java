
import java.io.*;
import java.util.*;
import java.math.*;

public class cups {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter("out.txt", "UTF-8");
        PrintWriter out = new PrintWriter(System.out);
        String line;
        String[] split;
        int n = Integer.parseInt(br.readLine());
        String[] ans = new String[1000];
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            split = br.readLine().split("\\s+");
            try {
                int rad = Integer.parseInt(split[0]);
                arr[i] = rad / 2;
                ans[rad / 2] = split[1];
            } catch (NumberFormatException e) {
                int rad = Integer.parseInt(split[1]);
                arr[i] = rad;
                ans[rad] = split[0];
            }
        }
        Arrays.sort(arr);
        for (int i = 0; i < arr.length; i++) {
            // out.println(arr[i]);
            out.println(ans[arr[i]]);
        }
        pw.close();
        out.close();
        br.close();
    }
}
