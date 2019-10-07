import java.lang.StringBuilder;
import java.io.*;

class solution {
    public static void main(String[] args) throws IOException{
        InputStreamReader in = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(in);
        StringBuilder sb = new StringBuilder();

        String[] input = br.readLine().split("\\s+"); 
        int N = Integer.parseInt(input[0]);
        int Q = Integer.parseInt(input[1]);

        String[] input2 = br.readLine().split("\\s+"); 
        for(int i = 0; i < Q; i++) {
            int query = Integer.parseInt(input2[i]);
        }
        System.out.print(sb.toString());
        br.close();
    }
}