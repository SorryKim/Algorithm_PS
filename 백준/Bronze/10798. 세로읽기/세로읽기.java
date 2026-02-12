import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] s = new String[5];
        int maxLen = 0;

        for (int i = 0; i < 5; i++) {
            s[i] = br.readLine();
            maxLen = Math.max(maxLen, s[i].length());
        }

        StringBuilder sb = new StringBuilder();

        for (int col = 0; col < maxLen; col++) {
            for (int row = 0; row < 5; row++) {
                if (col < s[row].length()) {
                    sb.append(s[row].charAt(col));
                }
            }
        }

        System.out.println(sb.toString());
    }
}
