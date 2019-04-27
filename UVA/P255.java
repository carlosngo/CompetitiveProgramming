
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class P255 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String[] split;
        String input;
        int kPos;
        int qPos1;
        int qPos2;
        while ((input = br.readLine()) != null) {
            split = input.split("\\s+");
            kPos = Integer.parseInt(split[0]);
            qPos1 = Integer.parseInt(split[1]);
            qPos2 = Integer.parseInt(split[2]);
            if (kPos == qPos1)
                System.out.println("Illegal state");
            else {
                King k = new King(kPos);
                Queen q = new Queen(qPos1);
                boolean legal = false;
                boolean sameFile = false;
                for (Integer i : q.getPossibleMoves()) {
                    if (i.intValue() == k.pos)
                        sameFile = true;
                    if (i.intValue() == qPos2) {
                        legal = true;
                        break;
                    }
                }
                if (legal && sameFile) {
                    if (sameFile) {
                        if (k.pos > q.pos) 
                            legal = qPos2 < k.pos;
                        else
                            legal = qPos2 > k.pos;
                    }
                }
                if (!legal) 
                    System.out.println("Illegal move");
                else {
                    boolean allowed = true;
                    for (Integer i : k.getPossibleMoves()) {
                        if (qPos2 == i) {
                            allowed = false;
                            break;
                        }
                    }
                    if (!allowed)
                        System.out.println("Move not allowed");
                    else {
                        Queen q2 = new Queen(qPos2);
                        boolean stale = true;
                        for (Integer i : k.getPossibleMoves()) {
                            boolean found = false;
                            for (Integer j : q2.getPossibleMoves()) {
                                if (i.intValue() == j.intValue()) {
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) {
                                stale = false;
                            }
                        }
                        System.out.println(stale ? "Stop" : "Continue");
                    }
                }
            }
        }
    }
    
    static class King {
        int pos;
        
        public King(int pos) {
            this.pos = pos;
        }
        
        public ArrayList<Integer> getPossibleMoves() {
            ArrayList<Integer> list = new ArrayList<>();
            if (pos - 8 >= 0)
                list.add(pos - 8);
            if (pos + 8 <= 63)
                list.add(pos + 8);
            if (pos - 1 >= getLeftMostSquare())
                list.add(pos - 1);
            if (pos + 1 <= getRightMostSquare())
                list.add(pos + 1);
            return list;
        }
        
        public int getLeftMostSquare() {
            int temp = pos;
            while (temp % 8 != 0)
                temp--;
            return temp;
        }
        
        public int getRightMostSquare() {
            int temp = pos;
            while (temp % 8 != 7)
                temp++;
            return temp;
        }
    }
    
    static class Queen {
        int pos;
        
        public Queen(int pos) {
            this.pos = pos;
        }
        
        public ArrayList<Integer> getPossibleMoves() {
            ArrayList<Integer> list = new ArrayList<>();
            int temp = pos;
            while (temp < getBottomSquare()) {
                temp += 8;
                list.add(temp);
            }
            temp = pos;
            while (temp > getTopMostSquare()) {
                temp -= 8;
                list.add(temp);
            }
            temp = pos;
            while (temp < getRightMostSquare()) {
                temp++;
                list.add(temp);
            }
            temp = pos;
            while (temp > getLeftMostSquare()) {
                temp--;
                list.add(temp);
            }
            return list;
        }
        
        public int getLeftMostSquare() {
            int temp = pos;
            while (temp % 8 != 0)
                temp--;
            return temp;
        }
        
        public int getRightMostSquare() {
            int temp = pos;
            while (temp % 8 != 7)
                temp++;
            return temp;
        }
        
        public int getTopMostSquare() {
            int temp = pos;
            while (temp > 7)
                temp -= 8;
            return temp;
        }
        
        public int getBottomSquare() {
            int temp = pos;
            while (temp < 56)
                temp += 8;
            return temp;
        }
    }
}
