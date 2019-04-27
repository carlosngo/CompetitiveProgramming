
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P579 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String[] time = br.readLine().split(":");
        int hour = Integer.parseInt(time[0]);
        int minute = Integer.parseInt(time[1]);
        float hAngle, mAngle, angle;
        while (hour > 0 || minute > 0) {
            mAngle = 6 * minute;
            hAngle = 30 * hour + (mAngle / 360 * 30);
            angle = hAngle > mAngle ? hAngle - mAngle : mAngle - hAngle;
            if (angle > 180)
                angle = 360 - angle;
            else if (angle == 360)
                angle = 0;
            System.out.printf("%.3f", angle);
            System.out.println("");
            time = br.readLine().split(":");
            hour = Integer.parseInt(time[0]);
            minute = Integer.parseInt(time[1]);
        }
    }
}
