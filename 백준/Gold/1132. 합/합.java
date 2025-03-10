import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String[] arr = new String[N];
        long[] weight = new long[10]; // 각 알파벳의 가중치
        int[] num = new int[10]; // 각 알파벳에 할당할 숫자
        Arrays.fill(weight, 0);
        Arrays.fill(num, -1);

        // 각 알파벳이 0을 가질 수 있는지 여부
        boolean[] canZero = new boolean[10];
        Arrays.fill(canZero, true);

        for (int i = 0; i < N; i++) {
            arr[i] = br.readLine();
            int len = arr[i].length();

            // 단어의 첫 글자는 0 불가
            canZero[arr[i].charAt(0) - 'A'] = false;

            // 각 자리의 알파벳에 대해 10^(자리수) 만큼의 가중치를 더함
            for (int j = 0; j < len; j++) {
                int idx = arr[i].charAt(j) - 'A';
                long temp = (long) Math.pow(10, len - j - 1);
                weight[idx] += temp;
            }
        }

        // 0을 할당할 수 있는 문자 중 가중치가 가장 작은 문자를 선택
        int temp = -1;
        long minWeight = Long.MAX_VALUE;
        for (int i = 0; i < 10; i++) {
            if (canZero[i] && weight[i] < minWeight) {
                minWeight = weight[i];
                temp = i;
            }
        }

        // 선택된 문자에 0 할당
        if (temp != -1) {
            num[temp] = 0;
        }

        // 남은 문자들에 대해 가중치가 큰 순서대로 할당
        int now = 9;
        int cnt = 0;
        while (cnt < 10) {

            int n = -1;
            long maxV = -1;

            for (int i = 0; i < 10; i++) {
                if (num[i] == -1 && weight[i] > maxV) {
                    maxV = weight[i];
                    n = i;
                }
            }

            if (n == -1)
                break;
            num[n] = now--;
            cnt++;
        }

        // 각 단어를 할당된 숫자로 변환 후 합산
        long answer = 0;

        for (int i = 0; i < N; i++) {

            int len = arr[i].length();
            long number = 0;

            for (int j = 0; j < len; j++) {
                int idx = arr[i].charAt(j) - 'A';
                number = number * 10 + num[idx];
            }

            answer += number;
        }

        System.out.println(answer);
    }
}
