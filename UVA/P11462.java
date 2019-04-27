
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class P11462 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        int peeps = Integer.parseInt(br.readLine());
        String[] split;
        while (peeps != 0) {
            int[] arr = new int[peeps];
            split = br.readLine().split("\\s+");
            for (int i = 0; i < split.length; i++)
                arr[i] = Integer.parseInt(split[i]);
            Arrays.sort(arr);
            for (int i = 0; i < arr.length; i++) {
                System.out.print(arr[i]);
                if (i != arr.length - 1)
                    System.out.print(" ");
            }
            System.out.println("");
            peeps = Integer.parseInt(br.readLine());
        }
    }
}
