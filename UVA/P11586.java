/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Carlos
 */
import java.io.*;
import java.util.*;

public class P11586 {
    public static void main(String[] args) throws IOException {
        int cases;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        cases = Integer.parseInt(br.readLine());
        while (cases-- > 0) {
            boolean ans;
            char end;
            String input = br.readLine();
            String[] pcs = input.split("\\s+");
           
            int fm, ff, mm;
            fm = ff = mm = 0;
            for (int i = 0; i < pcs.length; i++) {
                if (pcs[i].equals("MM")) {
                    mm++;
                } else if (pcs[i].equals("FF")) {
                    ff++;
                } else {
                    fm++;  
                }
            }
//            System.out.println("MM: " + mm + "\nFF: " + ff + "\nMF: " + fm);
            ans = ff == mm && pcs.length > 1;
            System.out.println(ans ? "LOOP" : "NO LOOP");
        }
    }
}
