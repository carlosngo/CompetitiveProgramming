
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P572 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        int cases;
        int m, n;
        int[][] arr;
        m = Integer.parseInt(br.readLine());
        n = Integer.parseInt(br.readLine());
        String input;
        ArrayList<Oil> deposit;
        while (!(m == 0 && n == 0)) {
            arr = new int[m][n];
            deposit = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                input = br.readLine();
                for (int j = 0; j < n; j++) 
                    arr[i][j] = input.charAt(j);
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (arr[i][j] == '@') {
                        Oil o = new Oil(i, j);
                        if (i - 1 < 0 && arr[i - 1][j] == '@') {
                            int index = deposit.indexOf(new Oil(i-1, j));
                            if (index != -1)
                                o.adjacent.add(deposit.get(index));
                        }
                    }
                }
            }
            m = Integer.parseInt(br.readLine());
            n = Integer.parseInt(br.readLine());
        }
    }
    
    static class Oil {
        int row, col;
        boolean visited;
        ArrayList<Oil> adjacent;
        
        public boolean equals(Object obj) {
            Oil o = (Oil)obj;
            return row == o.row && col == o.col;
        }
        
        public Oil(int row, int col) {
            this.row = row;
            this.col = col;
        }
    }
}
