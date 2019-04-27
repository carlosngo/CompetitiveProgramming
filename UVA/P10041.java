
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;


public class P10041 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String[] input;
        int cases = Integer.parseInt(br.readLine());
        int relatives;
        int[] pos;
        int best;
        long sum;
        while (cases-- > 0) {
            sum = 0;
            input = br.readLine().split(" ");
            relatives = Integer.parseInt(input[0]);
            pos = new int[relatives];
            for (int i = 0; i < input.length - 1; i++) 
                pos[i] = Integer.parseInt(input[i + 1]);
            Arrays.sort(pos);
            best = pos[(pos.length - 1) / 2];
            for (int i = 0; i < pos.length; i++) 
                if (i != (pos.length - 1) / 2)
                    sum += Math.abs(best - pos[i]);
            System.out.println(sum);
        }
    }
}