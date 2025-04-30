import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine().trim()); // coin row 수

        for (int i = 0; i < n; i++) {
            String line = br.readLine().trim();
            String[] tokens = line.split("\\s+");
            int[] coins = new int[tokens.length];

            for (int j = 0; j < tokens.length; j++) {
                coins[j] = Integer.parseInt(tokens[j]);
            }

            int result = maxMoney(coins);
            System.out.println(result);
        }
    }

    private static int maxMoney(int[] coins) {
        int n = coins.length;

        if (n == 0) return 0;
        if (n == 1) return coins[0];

        int[] dp = new int[n];
        dp[0] = coins[0];
        dp[1] = Math.max(coins[0], coins[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + coins[i]);
        }

        return dp[n - 1];
    }
}
