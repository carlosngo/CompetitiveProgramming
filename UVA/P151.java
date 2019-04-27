
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class P151 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        int n = Integer.parseInt(br.readLine());
        while (n != 0) {
            ArrayList<Integer> list = new ArrayList<>();
            for (int i = 1; i <= n; i++)
                list.add(i);
            int m = 1;
            while (true) {
                ArrayList<Integer> list2 = (ArrayList<Integer>)list.clone();
                list2.remove(0);
                int temp = m - 1;
                if (temp >= list2.size())
                    temp %= list2.size();
                while (list2.size() != 1) {
                    list2.remove(temp);
                    temp += m - 1;
                    if (temp >= list2.size())
                        temp %= list2.size();
                }
                if (list2.get(0) == 13) break;
                m++;
            }
            System.out.println(m);
            n = Integer.parseInt(br.readLine());
        }
    }
}
