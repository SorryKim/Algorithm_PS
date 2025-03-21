import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        final int MOD = 1000000000;
        int N = Integer.parseInt(br.readLine());

        long[] dp = new long[N + 1];

        dp[0] = 1;
        dp[1] = 0;

        for (int i = 2; i <= N; i++) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
        }

        System.out.println(dp[N]);
    }
}
