import java.util.*;
import java.io.*;

public class Main {
  
    static final String[] codes = {
        "000000", // A
        "001111", // B
        "010011", // C
        "011100", // D
        "100110", // E
        "101001", // F
        "110101", // G
        "111010"  // H
    };

    static final char[] letters = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
    };

    // 두 문자열의 해밍 거리 계산
    static int calc(String a, String b) {
        int count = 0;
        for (int i = 0; i < 6; i++) {
            if (a.charAt(i) != b.charAt(i)) count++;
        }
        return count;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());   
        String data = br.readLine();      

        StringBuilder result = new StringBuilder();

        for (int i = 0; i < n; i++) {
            String chunk = data.substring(i * 6, (i + 1) * 6);
            boolean found = false;

            for (int j = 0; j < codes.length; j++) {
                if (calc(chunk, codes[j]) <= 1) {
                    result.append(letters[j]);
                    found = true;
                    break;
                }
            }

            if (!found) {
                // 인식 못한 문자의 위치 출력
                System.out.println(i + 1);
                return;
            }
        }

        System.out.println(result);
    }
}
