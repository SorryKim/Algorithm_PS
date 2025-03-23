import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        int[] dp = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i = 0; i < N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i < N; i++) {
            int maxV = arr[i];
            int minV = arr[i];

            // j는 i부터 0까지 감소하면서 [j, i] 구간의 최대-최소 계산
            for(int j = i; j >= 0; j--) {
                maxV = Math.max(maxV, arr[j]);
                minV = Math.min(minV, arr[j]);

                int value = maxV - minV;

                if (j == 0) dp[i] = Math.max(dp[i], value); 
                else dp[i] = Math.max(dp[i], dp[j - 1] + value); 
            }
        }

        System.out.println(dp[N - 1]);
    }
}
