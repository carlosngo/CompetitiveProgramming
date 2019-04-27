
import java.io.IOException;
import java.util.Scanner;

public class P10327 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int elem = sc.nextInt();
            int[] arr = new int[elem];
            int flip = 0;
            for (int i = 0; i < elem; i++) 
                arr[i] = sc.nextInt();
            for (int i = 0; i < elem - 1; i++) {
                for (int j = 0; j < elem - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                        flip++;
                    }
                }
            }
            System.out.println("Minimum exchange operations : " + flip);
        }
        
    }
}
