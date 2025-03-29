import java.io.*;
import java.util.*;

public class Main {

    static int N, H;
    static int[] arr1, arr2;

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        arr1 = new int[N / 2]; // 석순
        arr2 = new int[N / 2]; // 종유석

        for (int i = 0; i < N; i++) {
            int size = Integer.parseInt(br.readLine());
            if (i % 2 == 0)
                arr1[i / 2] = size; // 석순
            else
                arr2[i / 2] = size; // 종유석
        }

    }

    // arr에서 target 이상의 첫번째 인덱스를 반환
    static int LowerBound(int[] arr, int target) {
        int left = 0;
        int right = arr.length;
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }

    static int[] Solve() {

        Arrays.sort(arr1);
        Arrays.sort(arr2);

        int ans = Integer.MAX_VALUE;
        int count = 0;

        // 각 높이 h에 대해 충돌하는 장애물 수 계산
        for (int h = 1; h <= H; h++) {

            // 석순: h 이상인 장애물의 수
            int index1 = LowerBound(arr1, h);
            int cnt1 = arr1.length - index1;

            // 종유석: H - h + 1 이상인 장애물의 수
            int index2 = LowerBound(arr2, H - h + 1);
            int cnt2 = arr2.length - index2;

            int sum = cnt1 + cnt2;
            // 최소값 및 개수 업데이트
            if (sum < ans) {
                ans = sum;
                count = 1;
            } else if (sum == ans) {
                count++;
            }
        }

        return new int[] { ans, count };
    }

    public static void main(String[] args) throws Exception {
        Input();
        int[] result = Solve();
        System.out.println(result[0] + " " + result[1]);
    }
}
