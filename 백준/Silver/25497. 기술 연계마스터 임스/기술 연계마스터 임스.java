import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static String s;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        s = br.readLine();
    }

    public static int solve() {
        int cnt = 0;
        int l_skill_count = 0;
        int s_skill_count = 0; 

        for (int i = 0; i < N; i++) {
            char ch = s.charAt(i);

            if (Character.isDigit(ch)) {
                cnt++;
            } else if (ch == 'L') {
                l_skill_count++; 
            } else if (ch == 'S') {
                s_skill_count++; 
            } else if (ch == 'R') {
                if (l_skill_count > 0) {
                    l_skill_count--;
                    cnt++;
                } else { 
                    break; 
                }
            } else if (ch == 'K') {
                if (s_skill_count > 0) { 
                    s_skill_count--;
                    cnt++;
                } else { 
                    break;
                }
            }
        }
        return cnt;
    }

    public static void main(String[] args) throws IOException {
        input();
        System.out.println(solve());
    }
}