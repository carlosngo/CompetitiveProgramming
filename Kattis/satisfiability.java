import java.io.*;
import java.util.*;
import java.math.*;

public class satisfiability {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String line;
        String[] split;
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            boolean ans = false;
            split = br.readLine().split("\\s+");
            int n = Integer.parseInt(split[0]);
            int m = Integer.parseInt(split[1]);
            int[][] conjunctions = new int[m][n];
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    conjunctions[j][k] = -1;
                }
            }
            for (int j = 0; j < m; j++) {
                split = br.readLine().split(" v ");
                for (int k = 0; k < split.length; k++) {
                    String[] literal = split[k].split("X");
                    if (literal[0].equals("")) {
                        int index = Integer.parseInt(literal[1]) - 1;
                        if (conjunctions[j][index] == -1) conjunctions[j][index] = 1;
                        else if (conjunctions[j][index] == 0) conjunctions[j][index] = 2;
                        
                    } else {
                        int index = Integer.parseInt(literal[1]) - 1;
                        if (conjunctions[j][index] == -1) conjunctions[j][index] = 0;
                        else if (conjunctions[j][index] == 1) conjunctions[j][index] = 2;
                    }
                }
            }
            for (int mask = 0; mask < (1 << n) && !ans; mask++) {
                boolean isSatisfiable = true;
                for (int j = 0; j < m && isSatisfiable; j++) {
                    boolean isTrue = false;
                    for (int k = 0; k < n && !isTrue; k++) {
                        if (conjunctions[j][k] == -1) continue;
                        if ((mask & (1 << k)) != 0 && conjunctions[j][k] == 1) isTrue = true;
                        else if ((mask & (1 << k)) == 0 && conjunctions[j][k] == 0) isTrue = true;
                        else if (conjunctions[j][k] == 2) isTrue = true;
                    }
                    if (!isTrue) {
                       isSatisfiable = false;
                    }
                }

                if (isSatisfiable) {
                    ans = true;
                }
            }
            out.println(ans ? "satisfiable" : "unsatisfiable");
        }
        // pw.close();
        out.close();
        br.close();
    }
}
