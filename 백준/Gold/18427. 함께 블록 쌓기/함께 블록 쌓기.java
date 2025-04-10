import java.io.*;
import java.util.*;

public class Main {

    static int N, M, H;
    static List<Integer>[] student;
    static int[][] dp; // {인원, 높이}
    final static int MOD = 10007;

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        student = new List[N + 1];
        dp = new int[N + 1][H + 1];

        for (int i = 1; i <= N; i++) {
            student[i] = new ArrayList<>();
            st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                student[i].add(Integer.parseInt(st.nextToken()));
            }
        }

    }

    static int Solve() {

        for (int i = 0; i <= N; i++)
            Arrays.fill(dp[i], 0);
        dp[0][0] = 1;
        for (int i = 1; i <= N; i++) {

            // 해당 학생의 블록을 사용하지 않는 경우
            for (int j = 0; j <= H; j++)
                dp[i][j] = dp[i - 1][j];

            List<Integer> blocks = student[i];

            for (int block : blocks) {
                for (int j = H; j >= block; j--) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - block]) % MOD;
                }
            }
        }

        return dp[N][H];
    }

    public static void main(String[] args) throws Exception {

        Input();
        System.out.println(Solve());
    }
}
