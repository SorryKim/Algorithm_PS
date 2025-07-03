import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[][] arr;
    
    static final int INF = 987654321;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

    }

    public static int solve() {

        // dp[i][j][k] = (최단 경로로 (i,j)에 왔을 때) 증가 부분 수열 길이가 k이고 그 끝값의 최솟값. INF면 불가능.
        int dpLen = 2 * N;

        int[][][] dp = new int[N][N][dpLen];
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                Arrays.fill(dp[i][j], INF);
            }
        }

        dp[0][0][0] = 0;
        dp[0][0][1] = arr[0][0];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == 0 && j == 0)
                    continue;

                // 위쪽에서 전이
                if (i > 0) {
                    transfer(dp[i - 1][j], dp[i][j], arr[i][j], dpLen);
                }

                // 왼쪽에서 전이
                if (j > 0) {
                    transfer(dp[i][j - 1], dp[i][j], arr[i][j], dpLen);
                }
            }
        }

        int answer = 1;
        for (int k = 1; k < dpLen; k++) {
            if (dp[N - 1][N - 1][k] < INF) {
                answer = k;
            }
        }

        return answer;
    }

    static void transfer(int[] src, int[] dest, int val, int dpLen) {

        for (int k = 0; k < dpLen; k++) {
            if (src[k] < INF) {

                // 1. 현재 칸을 선택하지 않음: 길이 k 유지
                if (src[k] < dest[k]) {
                    dest[k] = src[k];
                }

                // 2. 현재 칸을 선택해서 길이 k+1로 연장
                if (k + 1 < dpLen && src[k] < val && val < dest[k + 1]) {
                    dest[k + 1] = val;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        System.out.println(solve());
    }

    
}
