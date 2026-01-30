import java.io.*;
import java.util.*;

public class Main {

    static long calc(String birth, String day) {
        long year = 0, month = 0, date = 0;

        // 연도 (4자리)
        for (int i = 0; i < 4; i++) {
            int a = birth.charAt(i) - '0';
            int b = day.charAt(i) - '0';
            year += (a - b) * (a - b);
        }

        // 월 (2자리)
        for (int i = 4; i < 6; i++) {
            int a = birth.charAt(i) - '0';
            int b = day.charAt(i) - '0';
            month += (a - b) * (a - b);
        }

        // 일 (2자리)
        for (int i = 6; i < 8; i++) {
            int a = birth.charAt(i) - '0';
            int b = day.charAt(i) - '0';
            date += (a - b) * (a - b);
        }

        return year * month * date;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String birth = br.readLine();
        int N = Integer.parseInt(br.readLine());

        long maxVal = -1;
        String answer = "";

        for (int i = 0; i < N; i++) {
            String day = br.readLine();
            long val = calc(birth, day);

            if (val > maxVal || (val == maxVal && day.compareTo(answer) < 0)) {
                maxVal = val;
                answer = day;
            }
        }

        System.out.println(answer);
    }
}
