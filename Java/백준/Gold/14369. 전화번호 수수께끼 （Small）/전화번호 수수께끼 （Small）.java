import java.io.*;
import java.util.*;

public class Main {

    static String[] words = {
            "ZERO", // 0
            "ONE", // 1
            "TWO", // 2
            "THREE", // 3
            "FOUR", // 4
            "FIVE", // 5
            "SIX", // 6
            "SEVEN", // 7
            "EIGHT", // 8
            "NINE" // 9
    };

    static char[] filter = { 'Z', 'W', 'U', 'X', 'G', 'H', 'F', 'S', 'O', 'I' };
    static int[] order = { 0, 2, 4, 6, 8, 3, 5, 7, 1, 9 };

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int test = 1; test <= T; test++) {
            String S = br.readLine();

            // 문자 개수 세기
            int[] charCount = new int[26];
            for (char c : S.toCharArray()) {
                charCount[c - 'A']++;
            }

            // 숫자 개수 세기
            int[] digitCount = new int[10];
            for (int i = 0; i < filter.length; i++) {
                char unique = filter[i];
                int digit = order[i];
                int count = charCount[unique - 'A'];

                if (count > 0) {
                    digitCount[digit] = count;

                    // 해당 숫자의 문자들을 count만큼 제거
                    for (char ch : words[digit].toCharArray()) {
                        charCount[ch - 'A'] -= count;
                    }
                }
            }

            StringBuilder result = new StringBuilder();
            for (int i = 0; i < 10; i++) {
                while (digitCount[i]-- > 0) {
                    result.append(i);
                }
            }

            System.out.println("Case #" + test + ": " + result);
        }
    }
}
