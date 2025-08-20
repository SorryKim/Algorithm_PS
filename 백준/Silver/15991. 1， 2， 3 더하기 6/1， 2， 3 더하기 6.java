import java.io.*;

public class Main {

    static long[] dp;
    static final int MAX = 100000;
    static final int DIV = 1000000009;

    public static void solve() {

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 2;
        dp[4] = 3;
        dp[5] = 3;
        dp[6] = 6;

        for (int i = 7; i <= MAX; i++) {
            dp[i] = (dp[i - 2] + dp[i - 4]+ dp[i - 6]) % DIV;
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        dp = new long[100001];

        solve();

        for (int test = 0; test < T; test++) {
            int n = Integer.parseInt(br.readLine());
            System.out.println(dp[n]);
        }

    }
}