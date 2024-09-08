import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        // 입력 받기
        int N = Integer.parseInt(reader.readLine()); // 배열의 크기 N
        int K = Integer.parseInt(reader.readLine()); // B[k]에서 k 값

        // 이분 탐색의 범위 설정
        long left = 1, right = (long) N * N;
        long mid;
        long ans = 0; // 답을 저장할 변수

        // 이분 탐색 시작
        while (left <= right) {
            mid = (left + right) / 2;
            long count = 0;

            for (int i = 1; i <= N; i++) {
                // i번째 행에서 mid보다 작거나 같은 값의 개수는 mid / i 이다.
                // 하지만 열의 개수는 최대 N이므로 N을 초과하지 않게 조정
                count += Math.min(N, mid / i);
            }

            // count가 K보다 크거나 같으면 가능한 답을 저장하고, 더 작은 범위를 탐색
            if (count >= K) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // 결과 출력
        System.out.println(ans);
    }
}
