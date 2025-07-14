import java.io.*;
import java.util.*;

public class Main {

    static String s;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        s = br.readLine();
    }

    public static int solve() {
        char[] duck = { 'q', 'u', 'a', 'c', 'k' };
        List<Integer> state = new ArrayList<>();

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            char now = s.charAt(i);
            int idx = -1;

            for (int j = 0; j < 5; j++) {
                if (duck[j] == now) {
                    idx = j;
                    break;
                }
            }

            boolean matched = false;
            for (int j = 0; j < state.size(); j++) {
                if (state.get(j) == idx) {
                    state.set(j, (idx + 1) % 5);
                    matched = true;
                    break;
                }
            }

            if (!matched) {
                if (now == 'q') {
                    state.add(1); 
                    ans = Math.max(ans, state.size());
                } else {
                    return -1;
                }
            }
        }

        // 모든 오리가 울음을 끝내야 함
        for (int i : state) {
            if (i != 0) return -1;
        }

        return ans == 0 ? -1 : ans;
    }

    public static void main(String[] args) throws IOException {
        input();
        System.out.println(solve());
    }

}
