import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int D = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());
        int[][] arr = new int[P][2];
        int[] dp = new int[D + 1];

        Arrays.fill(dp, -1);
        dp[0] = Integer.MAX_VALUE;

        for (int i = 0; i < P; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }

        for (int[] temp : arr) {
            int dist = temp[0];
            int cap = temp[1];

            for (int i = D - dist; i >= 0; i--) {

                if (dp[i] == -1)
                    continue;

                dp[i + dist] = Math.max(dp[i + dist], Math.min(cap, dp[i]));
            }
        }

        System.out.println(dp[D]);
    }

}