import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int D = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        for (int first = 1; first < K; first++) {
            
            // 첫날 수 고정
            int left = first + 1;
            int right = K;
            int[] arr = new int[D + 1];
            arr[1] = first;

            // 두번째 개수 이분탐색으로 탐색
            while (left <= right) {

                int mid = (left + right) / 2;
                arr[2] = mid;
                for (int i = 3; i <= D; i++) {
                    arr[i] = arr[i - 1] + arr[i - 2];
                }

                if (arr[D] == K) {
                    System.out.println(first);
                    System.out.println(mid);
                    return;
                } else if (arr[D] > K)
                    right = mid - 1;
                else if (arr[D] < K)
                    left = mid + 1;
            }

        }
    }
}