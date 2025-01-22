import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        int cnt = 1;

        // 구간의 수를 구함
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) != s.charAt(i))
                cnt++;
        }

        System.out.println(cnt / 2);
    }
}
