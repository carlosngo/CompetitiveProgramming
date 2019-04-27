
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class P12912 {
    public static int binSearch(int[] arr, int n) {
        int l = 0;
        int u = arr.length - 1;
        int mid = -1;
        if (n > arr[u])
            return -1;
        if (n <= arr[0])
            return 0;
        while (l <= u) {
            mid = (l + u) / 2;
            if (arr[mid] >= n && arr[mid - 1] < n) 
                return mid;
            else if (arr[mid] < n)
                l = mid + 1;
            else if (arr[mid] >= n)
                u = mid - 1;
        }
        return mid;
    }
    
    
    public static void main(String[] args) throws IOException {
        int[][] grid;
        int r, c;
        int q;
        int l, u;
        String[] size;
        String[] nums;
        int max;
        int topIndex;
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        size = br.readLine().split(" ");
        r = Integer.parseInt(size[0]);
        c = Integer.parseInt(size[1]);
        while (r != 0 && c != 0) {
            grid = new int[r][c];
            for (int i = 0; i < r; i++) {
                nums = br.readLine().split(" ");
                for (int j = 0; j < c; j++) 
                    grid[i][j] = Integer.parseInt(nums[j]);
            }
            q = Integer.parseInt(br.readLine());
            while (q-- > 0) {
                max = 0;
                size = br.readLine().split(" ");
                l = Integer.parseInt(size[0]);
                u = Integer.parseInt(size[1]);
                for (int i = 0; i < r; i++) {
                    topIndex = binSearch(grid[i], l);
                    if (topIndex != -1) {
                        for (int j = max; j < r; j++) {
                            int m = i + j;
                            int n = topIndex + j;
                            if (m >= r || n >= c)
                                break;
                            if (grid[m][n] > u)
                                break;
                            if (j + 1 > max)
                                max = j + 1;
                        }
                    }
                }
                System.out.println(max);
            }
            System.out.println("-");
            size = br.readLine().split(" ");
            r = Integer.parseInt(size[0]);
            c = Integer.parseInt(size[1]);
        }
    }
}
