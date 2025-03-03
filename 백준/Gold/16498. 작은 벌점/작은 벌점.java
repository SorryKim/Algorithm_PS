import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        int[] a = new int[A];
        int[] b = new int[B];
        int[] c = new int[C];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < A; i++)
            a[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < B; i++)
            b[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < C; i++)
            c[i] = Integer.parseInt(st.nextToken());

        // Arrays.sort(a);
        // Arrays.sort(b);
        Arrays.sort(c);

        int answer = 100000000;

        // 두 수를 고정시키고 하나를 이분탐색
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {

                int varA = a[i];
                int varB = b[j];

                int left = 0;
                int right = C - 1;

                while (left <= right) {
                    int mid = (left + right) / 2;
                    int varC = c[mid];

                    int var1 = Math.max(varA, varB);
                    int var2 = Math.min(varA, varB);

                    // var1 > varC > var2 를 찾아야함.

                    if (varC >= var1)
                        right = mid - 1;
                    else
                        left = mid + 1;

                    answer = Math.min(answer, Math.abs(Math.max(var1, varC) - Math.min(var2, varC)));
                }
            }
        }

        System.out.println(answer);
    }
}