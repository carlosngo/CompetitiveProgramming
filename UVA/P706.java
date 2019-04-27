
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class P706 {
    public static void printHLine(int s) {
        System.out.print(" ");
        for (int j = 0; j < s; j++)
            System.out.print("-");
        System.out.print(" ");
    }
    
    public static void printLBar(int s) {
        System.out.print("|");
        for (int j = 0; j < s + 1; j++)
            System.out.print(" ");
    }
    
    public static void printRBar(int s) {
        for (int j = 0; j < s + 1; j++)
            System.out.print(" ");
        System.out.print("|");
    }
    
    public static void print2Bar(int s) {
        System.out.print("|");
        for (int j = 0; j < s; j++)
            System.out.print(" ");
        System.out.print("|");
    }
    
    public static void printBlank(int s) {
        for (int j = 0; j < s + 2; j++)
            System.out.print(" ");
    }
    
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        Scanner sc = new Scanner(System.in);
        int s;
        String n;
        s = sc.nextInt();
        n = sc.next().replaceAll(" ", "");
        while (!n.equals("0") || s != 0) {
            int rows = 2 * s + 3;
            for (int i = 0; i < rows; i++) { 
                for (int j = 0; j < n.length(); j++) {
                    switch (n.charAt(j)) {
                        case '0':
                            if (i == 0 || i == rows - 1) 
                                printHLine(s);
                            else if (i == rows / 2) 
                                printBlank(s);
                            else 
                                print2Bar(s);                            
                            break;
                        case '2':
                            if (i == 0 || i == rows - 1 || i == rows / 2) 
                                printHLine(s);
                            else if (i < rows / 2) 
                                printRBar(s);
                            else
                                printLBar(s);
                            break;
                        case '3':
                            if (i == 0 || i == rows - 1 || i == rows / 2) 
                                printHLine(s);
                            else
                                printRBar(s);
                            break;
                        case '5':
                            if (i == 0 || i == rows - 1 || i == rows / 2) 
                                printHLine(s);
                            else if (i > rows / 2) 
                                printRBar(s);
                            else
                                printLBar(s);
                            break;
                        case '6':
                            if (i == 0 || i == rows - 1 || i == rows / 2) 
                                printHLine(s);
                            else if (i < rows / 2)
                                printLBar(s);
                            else
                                print2Bar(s);
                            break;
                        case '7':
                            if (i == 0) 
                                printHLine(s);
                            else if (i == rows / 2 || i == rows - 1)
                                printBlank(s);
                            else {
                                printRBar(s);
                            }
                            break;
                        case '8':
                            if (i == 0 || i == rows - 1 || i == rows / 2) 
                                printHLine(s);
                            else
                                print2Bar(s);
                            break;
                        case '9':
                            if (i == 0 || i == rows - 1 || i == rows / 2) 
                                printHLine(s);
                            else if (i < rows / 2)
                                print2Bar(s);
                            else
                                printRBar(s);
                            break;
                        case '1':
                            if (i == 0 || i == rows - 1 || i == rows / 2)
                                printBlank(s);
                            else
                                printRBar(s);
                            break;
                        case '4':
                            if (i == 0 || i == rows - 1) 
                                printBlank(s);
                            else if (i == rows / 2) 
                                printHLine(s);
                            else if (i < rows / 2)
                                print2Bar(s);
                            else
                                printRBar(s);
                    }
                    if (j < n.length() - 1)
                        System.out.print(" ");
                }
                System.out.println("");
            }
            System.out.println("");
            s = sc.nextInt();
            n = sc.next().replaceAll(" ", "");
        }
    }
}
