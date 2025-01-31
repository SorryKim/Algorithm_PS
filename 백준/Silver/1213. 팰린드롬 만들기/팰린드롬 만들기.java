import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        char[] arr = new char['Z' - 'A' + 1];

        // 문자열에 존재하는 문자갯수 count
        for (int i = 0; i < s.length(); i++)
            arr[s.charAt(i) - 'A']++;

        // 주어진 문자열의 길이가 짝수인 경우 모든 알파벳이 짝수개 있어야함
        if (s.length() % 2 == 0) {
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < arr.length; i++) {

                // 팰린드롬 불가
                if (arr[i] % 2 != 0) {
                    System.out.println("I'm Sorry Hansoo");
                    return;
                }

                for (int j = 0; j < arr[i] / 2; j++) {
                    sb.append((char) ('A' + i));
                }

            }

            // 지금까지 추가된 문자열 뒤집어서 한번 더 추가
            String ans = sb.toString() + sb.reverse().toString();
            System.out.println(ans);
        }
        // 홀수인 경우, 한 문자는 홀수개 가능 중앙에 와야함
        else {
            boolean flag = true;
            int mid = 0;
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < arr.length; i++) {

                if (arr[i] % 2 != 0) {
                    if (flag) {
                        flag = false;
                        mid = i;
                    } else {
                        System.out.println("I'm Sorry Hansoo");
                        return;
                    }
                }

                for (int j = 0; j < arr[i] / 2; j++)
                    sb.append((char) ('A' + i));
            }

            // 지금까지 추가된 문자열 뒤집어서 한번 더 추가
            String ans = sb.toString() + (char) ('A' + mid) + sb.reverse().toString();
            System.out.println(ans);
        }

    }

}
