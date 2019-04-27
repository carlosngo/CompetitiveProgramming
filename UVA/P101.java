
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P101 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        int cases = Integer.parseInt(br.readLine());
        int[][] deques = new int[cases][cases];
        int b1, b2;
        for (int i = 0; i < cases; i++) 
            deques[i][0] = i;
        int stackIndex, blockIndex;
        
        String[] split;
        String input = br.readLine();
        while (!input.equals("quit")) {
            split = input.split("\\s+");
            b1 = Integer.parseInt(split[1]);
            b2 = Integer.parseInt(split[3]);
            stackIndex = -1;
            blockIndex = -1;
            for (int i = 0; i < cases; i++) {
                for (int j = 0; j < deques[i].length; j++) {
                    if (deques[i][j] == b1) {
                        stackIndex = i; 
                        blockIndex = j;
                    }                        
                }
            }
            if (b1 != b2) {
                if (split[0].equals("move")) {
                    for (int i = blockIndex; i < deques[stackIndex].length; i++) {
                        deques[deques[stackIndex][i]][0] = deques[stackIndex][i];
                    }
                    
                    if (split[2].equals("over")) {

                    } else {

                    }
                } else {
                    if (split[2].equals("over")) {

                    } else {

                    }
                }
            }
            input = br.readLine();
        }
    }
}
