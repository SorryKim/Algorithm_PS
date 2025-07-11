import java.io.*;
import java.util.*;

public class Main {

    static int L, N, K;
    static int[] stations;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        L = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        stations = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            stations[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(stations);
    }

    public static boolean check(int battery) {

        int cnt = 0; // 사용한 충전 횟수
        int dist = 0; // 마지막으로 충전한 위치

        for (int i = 0; i < N; i++) {

            // 현재 충전소에 도달 자체가 불가능한 경우
            if (stations[i] - dist > battery) {
                return false;
            }

            // 다음 목적지를 설정
            int next = (i + 1 < N) ? stations[i + 1] : L;

            // 현재 충전소에서 충전하지 않고 다음 목적지까지 갈 수 있는지 확인.
            if (next - dist > battery) {
                // 충전
                cnt++;
                dist = stations[i];
            }
        }

        // 마지막 충전 위치에서 학교까지 도달 가능한지 확인
        if (L > dist + battery) {
            return false;
        }

        // 사용한 총 충전 횟수가 허용된 횟수 이하인지
        return cnt <= K;
    }

    public static int solve() {

        int left = 1;
        int right = L;
        int ans = L;

        // 파라매트릭서치로 배터리 용량 찾기
        while (left <= right) {
            int mid = (left + right) / 2;

            if (check(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }

    public static void main(String[] args) throws IOException {
        input();
        System.out.println(solve());
    }

}
