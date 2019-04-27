
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P400 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        int cases;
        String[] arr;
        String input;
        while ((input = br.readLine()) != null) {
            int n = Integer.parseInt(input);
            arr = new String[n];
            int max = 0;
            for (int i = 0; i < n; i++) {
                arr[i] = br.readLine();
                if (arr[i].length() > max)
                    max = arr[i].length();
            }
            insertionSort(arr, n);
            
            int cols = 1;
            int rCharacters = max;
            while (rCharacters + max + 2 <= 60) {
                rCharacters += max + 2;
                cols++;
            }
            int rows = n / cols;
            if (n % cols != 0)
                rows++;
            String format1 = "%-" + max + "s";
            String format2 = "%-" + (max + 1) + "s ";
            
            for (int i = 0; i < 60; i++)
                System.out.print("-");
            System.out.println("");
            for (int i = 0; i < rows; i++) {
                for (int j = i; j < n; j += rows) {
                    if (j + rows >= n)
                        System.out.printf(format1, arr[j]);
                    else
                        System.out.printf(format2, arr[j]);
                }
                System.out.println("");
            }
        }
    }
    
    static void insertionSort(String[] arr, int n) {
        for (int i = 1; i < n; i++) {
            String temp = arr[i];
            int j = i - 1;
            while (j >= 0 && compareStrings(temp, arr[j]) < 0) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }
    
    static int compareStrings(String s1, String s2) {
        int comparison;
        for (int i = 0; i < s1.length() && i < s2.length(); i++) {
            int ch1 = s1.charAt(i);
            int ch2 = s2.charAt(i);
            comparison = ch1 - ch2;
            
            if (comparison != 0)
                return comparison;
        }
        
        if (s1.length() > s2.length())
            return 1;
        else if (s1.length() < s2.length())
            return -1;
        else
            return 0;
    }
}
