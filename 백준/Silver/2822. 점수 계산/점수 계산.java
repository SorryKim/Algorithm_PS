import java.io.*;
import java.util.*;

public class Main {

    public static class Num {
        int index;
        int n;

        public Num(int index, int n) {
            this.index = index;
            this.n = n;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Num[] arr = new Num[8];

        for (int i = 0; i < 8; i++) {
            int num = Integer.parseInt(br.readLine());
            arr[i] = new Num(i + 1, num);
        }

        // 점수를 기준으로 내림차순 정렬
        Arrays.sort(arr, (a, b) -> Integer.compare(b.n, a.n));

        int sum = 0;
        List<Integer> list = new ArrayList<>();

        // 상위 5개 문제 선택
        for (int i = 0; i < 5; i++) {
            sum += arr[i].n;
            list.add(arr[i].index);
        }

        // 문제 번호를 오름차순 정렬
        Collections.sort(list);

        // 결과 출력
        System.out.println(sum);
        for (int num : list) {
            System.out.print(num + " ");
        }
    }
}
