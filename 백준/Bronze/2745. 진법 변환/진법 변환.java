import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String N = st.nextToken();
        int B = Integer.parseInt(st.nextToken());

        long result = 0;

        for (int i = 0; i < N.length(); i++) {
            char c = N.charAt(i);
            int value;

            if (c >= '0' && c <= '9') {
                value = c - '0';
            } else { // 'A' ~ 'Z'
                value = c - 'A' + 10;
            }

            result = result * B + value;
        }

        System.out.println(result);
    }
}
