import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine());
        int[] arr = new int[N];
        StringTokenizer st = new StringTokenizer(reader.readLine());
        for (int i = 0; i < N; i++) 
            arr[i] = Integer.parseInt(st.nextToken());
        

        long[] sum = new long[N];
        sum[0] = arr[0];
        for (int i = 1; i < N; i++)
            sum[i] = sum[i - 1] + arr[i];
        

        long answer = 0;

        // 벌통 - 벌 - 벌
        for (int i = 1; i < N - 1; i++) {
            long temp = (sum[N - 2] - arr[i]) + sum[i - 1];
            answer = Math.max(answer, temp);
        }

        // 벌 - 벌 - 벌통
        for (int i = 1; i < N - 1; i++) {
            long temp = (sum[N - 1] - sum[i]) + (sum[N - 1] - arr[i] - arr[0]);
            answer = Math.max(answer, temp);
        }

        // 벌 - 벌통 - 벌
        for (int i = 1; i < N - 1; i++) {
            long temp = (sum[i] - arr[0]) + (sum[N - 1] - sum[i - 1] - arr[N - 1]);
            answer = Math.max(answer, temp);
        }

        System.out.println(answer);
    }
}
