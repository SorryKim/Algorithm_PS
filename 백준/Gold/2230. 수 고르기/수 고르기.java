import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {

        // Input
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(reader.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] arr = new int[N + 1];

        for (int i = 1; i <= N; i++)
            arr[i] = Integer.parseInt(reader.readLine());

        Arrays.sort(arr);

        int answer = 2000000000;

        for (int i = 1; i <= N; i++) {

            for (int j = i + 1; j <= N; j++) {
                int val = arr[j] - arr[i];
                if (val >= M) {
                    answer = Math.min(answer, val);
                    break;
                }
            }
        }

        System.out.println(answer);

    }
}
