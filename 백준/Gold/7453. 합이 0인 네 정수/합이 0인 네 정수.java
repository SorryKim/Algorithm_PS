import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        // 입력 받기
        int n = Integer.parseInt(reader.readLine()); // 배열의 크기 N
        long[] A = new long[n];
        long[] B = new long[n];
        long[] C = new long[n];
        long[] D = new long[n];
        long answer = 0;

        for (int i = 0; i < n; i++) {
            String s = reader.readLine();
            StringTokenizer st = new StringTokenizer(s);
            A[i] = Long.parseLong(st.nextToken());
            B[i] = Long.parseLong(st.nextToken());
            C[i] = Long.parseLong(st.nextToken());
            D[i] = Long.parseLong(st.nextToken());
        }

        long[] arr = new long[n * n];

        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[idx++] = A[i] + B[j];
            }
        }

        Arrays.sort(arr);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                long sum = C[i] + D[j];
                int a = lower(arr, -sum);
                int b = upper(arr, -sum);

                answer += (b - a);
            }
        }

        System.out.println(answer);
    }

    public static int lower(long[] arr, long target) {
        int left = 0;
        int right = arr.length;

        while (left < right) {
            int mid = (left + right) / 2;

            if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }

    public static int upper(long[] arr, long target) {
        int left = 0;
        int right = arr.length;

        while (left < right) {
            int mid = (left + right) / 2;

            if (arr[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
}
