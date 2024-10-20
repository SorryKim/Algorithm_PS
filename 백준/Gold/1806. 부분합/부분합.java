import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {

        // Input
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(reader.readLine());
        int N = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        int[] arr = new int[N + 1];

        st = new StringTokenizer(reader.readLine());
        arr[0] = 0;

        // 누적 합으로 배열 저장
        for (int i = 1; i <= N; i++)
            arr[i] = Integer.parseInt(st.nextToken()) + arr[i - 1];
        

        // solve
        int answer = 987654321;
        int start = 0;
        int end = 1;

        while (start <= end && end <= N) {

            int sum = arr[end] - arr[start];

            if (sum >= S) {
                answer = Math.min(answer, end - start);
                start++;
            } else {
                end++;
            }
        }

        if (answer == 987654321)
            answer = 0;
        System.out.println(answer);
    }
}
