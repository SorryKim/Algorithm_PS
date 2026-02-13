import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        long answer = 0;
        int len = 1;
        int start = 1;

        while (true) {
            int end = start * 10 - 1;

            if (N >= end) {
                // 이 자리수 구간을 전부 포함
                answer += (long)(end - start + 1) * len;
            } else {
                // 마지막 부분 구간
                answer += (long)(N - start + 1) * len;
                break;
            }

            len++;
            start *= 10;
        }

        System.out.println(answer);
    }
}
