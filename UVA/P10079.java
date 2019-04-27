
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class P10079 {
    public static void main(String[] args) throws IOException {
	InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        long[] slices = new long[210000001];
        slices[0] = 1;
        for (int i = 1; i < 210000001; i++) 
            slices[i] = slices[i - 1] + i;
        int cuts = Integer.parseInt(br.readLine());
        while (cuts > -1) {
            System.out.println(slices[cuts]);
            cuts = Integer.parseInt(br.readLine());
        }
    }   
}