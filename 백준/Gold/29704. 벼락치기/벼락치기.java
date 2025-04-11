import java.io.*;
import java.util.*;

public class Main {

    static int N, T;
    static int[][] arr;
    static int SUM;

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        SUM = 0;

        arr = new int[N + 1][2];

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
            SUM += arr[i][1];
        }

    }

    static int Solve() {

        int[] dp = new int[T + 1];
        Arrays.fill(dp, -1);
        dp[0] = 0;

        for (int i = 1; i <= N; i++) {
            int d = arr[i][0];
            int m = arr[i][1];

            for (int j = T; j >= d; j--) {
                int next = j - d;
                if (dp[next] == -1)
                    continue;

                dp[j] = Math.max(dp[j], dp[next] + m);
            }
        }

        int val = 0;
        for (int i = 0; i <= T; i++) {
            val = Math.max(val, dp[i]);
        }

        return SUM - val;
    }

    public static void main(String[] args) throws Exception {

        Input();
        System.out.println(Solve());
    }
}
