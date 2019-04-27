
import java.io.*;
import java.util.*;
import java.math.*;

public class integerlists {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter("out.txt", "UTF-8");
        PrintWriter out = new PrintWriter(System.out);
        String line;
        String[] split;
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String prg = br.readLine();
            int n = Integer.parseInt(br.readLine());
            line = br.readLine();
            line = line.substring(1, line.length() - 1);
            split = line.split(",");
            
            LinkedList<Integer> dq = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                // out.println(split[i]);
                dq.add(Integer.parseInt(split[i]));
                // out.println("Pushed " + dq.peekLast());
            }
            boolean isReversed = false;
            boolean error = false;
            for (int i = 0; i < prg.length() && !error; i++) {
                if (prg.charAt(i) == 'R') isReversed = !isReversed;
                else {
                    if (dq.isEmpty()) {
                        out.println("error");
                        error = true;
                        break;
                    }
                    if (isReversed) dq.pollLast();
                    else dq.pollFirst();
                }
            }
            if (!error) {
                out.print("[");
                int ctr = 0;
                while (!dq.isEmpty()) {
                    int elem;
                    if (isReversed) elem = dq.pollLast();
                    else elem = dq.pollFirst();
                    if (ctr > 0) out.print(",");
                    out.print(elem);
                    ctr++;
                }
                out.println("]");
            }
        }
        pw.close();
        out.close();
        br.close();
    }
}
