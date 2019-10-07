import java.util.Scanner;

public class solution {
    // Note that using this template is optional
    // Do not include any extraneous I/O, such as "Please insert T:" or "The answer is ..."

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        for(int cn=1; cn<=T; cn++) {
            int N = sc.nextInt();
            int X = sc.nextInt();
            int Y = sc.nextInt();

            int x[] = new int[N];
            int y[] = new int[N];
            for(int i=0; i<N; i++) {
                x[i] = sc.nextInt();
                y[i] = sc.nextInt();
            }
            
            int p_a = 0;
            int p_b = 0;
            //insert your solution here

            System.out.println(String.format("Case #%d: (%d,%d) (%d,%d)",cn,x[p_a],y[p_a],x[p_b],y[p_b]));
        }
    }
}