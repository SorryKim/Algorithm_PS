import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static long totalVotes;
    static int[] arr;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[N];
        totalVotes = 0;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            totalVotes += arr[i];
        }
    }

    public static int solve() {

        // 투표 수 오름차순 정렬
        Arrays.sort(arr);

        long majority = (totalVotes / 2) + 1;
        long currentVotes = 0;
        int idx = 0;

        // 탄핵 찬성표가 과반수가 넘지 않는 선까지 0원 지급
        while (idx < N && currentVotes + arr[idx] < majority) {
            currentVotes += arr[idx];
            idx++;
        }

        // 남은 단체 수
        int remain = N - idx;

        // 학생회가 가져갈 수 있는 최대 예산 (n빵)
        int ans = M / (remain + 1);

        return ans;
    }

    public static void main(String[] args) throws IOException {
        input();
        System.out.println(solve());
    }
}
