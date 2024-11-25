import java.util.Scanner;
import java.util.Arrays;

public class Main {
    static int[] arr = new int[9];

    public static int sum() {
        int n = 0;
        for (int i = 0; i < 9; i++) {
            n += arr[i];
        }
        return n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 9; i++) {
            arr[i] = sc.nextInt();
        }

        boolean found = false;

        for (int i = 0; i < 9; i++) {
            int temp1 = arr[i];
            arr[i] = 0;
            for (int j = 0; j < 9; j++) {
                if (arr[j] == 0) continue;
                int temp2 = arr[j];
                arr[j] = 0;
                int result = sum();
                if (result == 100) {
                    found = true;
                    break;
                }
                arr[j] = temp2;
            }
            if (found) break;
            arr[i] = temp1;
        }

        Arrays.sort(arr);

        for (int i = 2; i < 9; i++) {
            System.out.println(arr[i]);
        }

        sc.close();
    }
}
