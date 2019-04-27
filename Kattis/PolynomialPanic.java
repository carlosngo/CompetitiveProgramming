/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Carlos
 */
import java.util.*;
import java.io.*;
public class PolynomialPanic {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        String[] split = input.split("\\s+");
        int deg = Integer.parseInt(split[0]);
        while (deg != 0) {
            int x = Integer.parseInt(split[1]);
            ArrayList<Integer> polyCoef = new ArrayList<>();
            int polyAns = 0;
            ArrayList<Integer> firstCoef = new ArrayList<>();
            int firstAns = 0;
            ArrayList<Integer> secondCoef = new ArrayList<>();
            int secondAns = 0;
            String[] split2 = br.readLine().split("\\s+");
            for (int i = 0; i < deg + 1; i++) {
                polyCoef.add(Integer.parseInt(split2[i]));
            if (i < deg)
                firstCoef.add(polyCoef.get(i) * (deg - i));
            if (i < deg - 1)
                secondCoef.add(firstCoef.get(i) * (deg - i - 1));
            
            polyAns += polyCoef.get(i) * Math.pow(x, deg - i);
        }
        for (int i = 0; i < firstCoef.size(); i++) {
            // printf("%d ", firstCoef[i]);
            firstAns += firstCoef.get(i) * Math.pow(x, (int)firstCoef.size() - i - 1);
        }
        for (int i = 0; i < secondCoef.size(); i++) {
            // printf("%d ", secondCoef[i]);
            secondAns += secondCoef.get(i) * Math.pow(x, (int) secondCoef.size() - i - 1);
        }
        System.out.printf("%d %d %d\n", polyAns, firstAns, secondAns);
            
//            System.out.println("");   
            split = br.readLine().split("\\s+");
            deg = Integer.parseInt(split[0]);
        }
   
    }
}
