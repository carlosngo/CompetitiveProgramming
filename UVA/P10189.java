
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class P10189 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        int r, c;
        int count = 0;
        char[] input;
        String[] nums = br.readLine().split(" ");
        r = Integer.valueOf(nums[0]);
        c = Integer.valueOf(nums[1]);
        char[][] grid;
        while (r != 0 && c != 0) {
                grid = new char[r][c];
                for (int i = 0; i < r; i++) 
                    for (int j = 0; j < c; j++)
                        grid[i][j] = '0';
                for (int i = 0; i < r; i++) {
                    input = br.readLine().toCharArray();
                    for (int j = 0; j < c; j++) {
                        if (input[j] == '*') {
                            grid[i][j] = '*';
                            if (i > 0) {
                                grid[i - 1][j]++;
                                if (j > 0)
                                    grid[i - 1][j - 1]++;
                                if (j < c - 1)
                                    grid[i - 1][j + 1]++;
                            } 
                            if (i < r - 1) {
                                grid[i + 1][j]++;
                                if (j > 0)
                                    grid[i + 1][j - 1]++;
                                if (j < c - 1)
                                    grid[i + 1][j + 1]++;
                            }
                            if (j > 0)
                                grid[i][j - 1]++;
                            if (j < c - 1)
                                grid[i][j + 1]++;
                        }
                    }
                     
                }
                System.out.println("Field #" + ++count + ":");
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) { 
                        if (!Character.isDigit(grid[i][j]))
                            grid[i][j] = '*';
                        System.out.print(grid[i][j]);
                    }
                    System.out.println("");
                }
                nums = br.readLine().split(" ");
                r = Integer.valueOf(nums[0]);
                c = Integer.valueOf(nums[1]);
                if (r != 0 && c != 0)
                    System.out.println("");
            }
    }
}
