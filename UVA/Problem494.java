
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Carlos
 */

class Problem494 {
    
    public static void main(String args[]) {
        String input;
        String[] words;
        int count;
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLine()) {
            count = 0;
            input = sc.nextLine();
            words = input.split(" ");
            for (int i = 0; i < words.length; i++)
                if (!words[i].isEmpty())
                    if (!(words[i].length() == 1 && !Character.isLetter(words[i].charAt(0))))
                        count++;
            System.out.println(count);
        }
    }
}
