import java.io.*;
import java.util.*;

public class Main {

    static int N, K;
    static int[] arr, dp;

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        arr = new int[N];
        dp = new int[K + 1];
        Arrays.fill(dp, -1);
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
    }

    static int Solve() {
        dp[0] = 0;

        for (int i = 0; i < N; i++) {
            int now = arr[i];

            for (int j = K; j >= now; j--) {

                int next = j - now;
                if (dp[next] == -1)
                    continue;

                if (dp[j] == -1 || dp[j] > dp[next] + 1) {
                    dp[j] = dp[next] + 1;
                }
            }
        }

        return dp[K];
    }

    public static void main(String[] args) throws Exception {

        Input();
        System.out.println(Solve());
    }
}
