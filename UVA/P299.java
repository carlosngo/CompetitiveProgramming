import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P299 {
    public static void main(String[] args) {
        int size;
        int cases;
        int[] arr;
        String[] nums;
        int swaps;
        int temp;
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        try {
            cases = Integer.valueOf(br.readLine());
            while (cases-- > 0) {
                swaps = 0;
                size = Integer.valueOf(br.readLine());
                arr = new int[size];
                nums = br.readLine().split(" ");
                for (int i = 0; i < size; i++)
                    arr[i] = Integer.valueOf(nums[i]);
                for (int i = 0; i < size - 1; i++) {
                    for (int j = 0; j < size - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                            swaps++;
                        }
                    }
                }
                System.out.println("Optimal train swapping takes " + swaps + " swaps.");
            }
              
        } catch (IOException ioe) {
        }
    }
}
