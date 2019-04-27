
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P118 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String[] split = br.readLine().split("\\s+");
        int c = Integer.parseInt(split[0]);
        int r = Integer.parseInt(split[1]);
        boolean[][] dead = new boolean[++r][++c];
        for (int i = 0; i < r; i++) 
            for (int j = 0; j < c; j++)
                dead[i][j] = false;
        String input;
        while ((input = br.readLine()) != null) {
            split = input.split("\\s+");
            Robot rb = new Robot(Integer.parseInt(split[1]), Integer.parseInt(split[0]), split[2].charAt(0));
            String commands = br.readLine();
            boolean fall = false;
            for (int i = 0; i < commands.length() && !fall; i++) {
                char ch = commands.charAt(i);
                switch (ch) {
                    case 'R':
                        rb.rotateRight();
                        break;
                    case 'L':
                        rb.rotateLeft();
                        break;
                    default:
                        rb.moveForward();
                        if ((rb.r == r || rb.r == -1 || rb.c == c || rb.c == -1)) {
                            rb.moveBack();
                            if (dead[r - rb.r - 1][rb.c] == false) {
                                fall = true;
                                dead[r - rb.r - 1][rb.c] = true;
                            }
                        }
                }
            }
            System.out.print(rb.c + " " + rb.r + " " + rb.dir);
            if (fall)
                System.out.println(" LOST");
            else
                System.out.println("");
        }
    }
    
    static class Robot {
        int r, c;
        char dir;

        public Robot(int r, int c, char dir) {
            this.r = r;
            this.c = c;
            this.dir = dir;
        }
        
        public void rotateLeft() {
            switch (dir) {
                case 'W':
                    dir = 'S';
                    break;
                case 'N':
                    dir = 'W';
                    break;
                case 'E':
                    dir = 'N';
                    break;
                default:
                    dir = 'E';
            }
        }
        
        public void rotateRight() {
            switch (dir) {
                case 'S':
                    dir = 'W';
                    break;
                case 'W':
                    dir = 'N';
                    break;
                case 'N':
                    dir = 'E';
                    break;
                default:
                    dir = 'S';
            }
        }
        
        public void moveForward() {
            switch (dir) {
                case 'S':
                    r--;
                    break;
                case 'W':
                    c--;
                    break;
                case 'N':
                    r++;
                    break;
                default:
                    c++;
            }
        }
        
        public void moveBack() {
            rotateLeft();
            rotateLeft();
            moveForward();
            rotateLeft();
            rotateLeft();
        }
    }
}
