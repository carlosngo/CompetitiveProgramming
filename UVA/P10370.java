
import java.util.Arrays;
import java.util.Scanner;


public class P10370 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        int sum;
        int[] grades;
        while (cases-- > 0) {
            sum = 0;
            int p = sc.nextInt();
            grades = new int[p];
            for (int i = 0; i < p; i++) {
                grades[i] = sc.nextInt(); 
                sum += grades[i];
            }
            Arrays.sort(grades);
            double ave = 1.0 * sum / p; 
            int i;
            for (i = 0; i < p; i++)  
                if (grades[i] > Math.floor(ave))
                    break;
            System.out.printf("%.3f", (p - i) * 1.0 / p * 100);
            System.out.println("%");
        }
            
    }
}
