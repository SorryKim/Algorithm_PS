import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        // 위쪽
        for (int i = 0; i < N; i++) {
            // 공백
            for (int j = 0; j < i; j++) {
                System.out.print(" ");
            }
            // 별
            for (int j = 0; j < 2 * (N - i) - 1; j++) {
                System.out.print("*");
            }
            System.out.println();
        }

        // 아래쪽
        for (int i = N - 2; i >= 0; i--) {
            // 공백
            for (int j = 0; j < i; j++) {
                System.out.print(" ");
            }
            // 별
            for (int j = 0; j < 2 * (N - i) - 1; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
