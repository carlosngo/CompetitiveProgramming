
import java.io.*;
import java.util.*;
import java.math.*;

public class CF560D {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter("out.txt", "UTF-8");
        PrintWriter out = new PrintWriter(System.out);
        String line;
        String[] split;
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			split = br.readLine().split("\\s+");
			ArrayList<Long> divisors = new ArrayList<>();
			for (int i = 0; i < split.length; i++) {
				divisors.add(Long.parseLong(split[i]));
			}
			boolean isValid = true;
			Collections.sort(divisors);
			long num = (long)divisors.get(0) * (long)divisors.get(divisors.size() - 1);
			for (long i = 2; i <= Math.sqrt(num) && isValid; i++) {
				if (num % i == 0) {
					long j = num / i;
					if (Collections.binarySearch(divisors, i) < 0) isValid = false;
					if (Collections.binarySearch(divisors, j) < 0) isValid = false;
				}
			}
			if (isValid) out.println(num);
			else out.println(-1);
		}
        pw.close();
        out.close();
        br.close();
    }
}
