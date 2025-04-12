import java.io.*;
import java.util.*;

public class Main {

    static int N, M, K;
    static int[][] orders;

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        orders = new int[N][2];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            orders[i][0] = Integer.parseInt(st.nextToken());
            orders[i][1] = Integer.parseInt(st.nextToken());
        }
    }

    static int Solve() {

        int[][] dp = new int[M + 1][K + 1];
        for (int i = 0; i <= M; i++)
            Arrays.fill(dp[i], -1);

        dp[0][0] = 0;

        for (int[] order : orders) {

            int burger = order[0];
            int fries = order[1];

            for (int i = M; i >= burger; i--) {
                for (int j = K; j >= fries; j--) {

                    if (dp[i - burger][j - fries] == -1)
                        continue;

                    dp[i][j] = Math.max(dp[i][j], dp[i - burger][j - fries] + 1);
                }
            }
        }

        int result = 0;

        for (int i = 0; i <= M; i++) {
            for (int j = 0; j <= K; j++) {
                result = Math.max(result, dp[i][j]);
            }
        }

        return result;
    }

    public static void main(String[] args) throws IOException {

        Input();
        System.out.println(Solve());

    }
}
