import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static int[] preOrder, inOrder;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int TC = 0; TC < T; TC++) {

            N = Integer.parseInt(br.readLine());
            preOrder = new int[N + 1];
            inOrder = new int[N + 1];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++)
                preOrder[i] = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++)
                inOrder[i] = Integer.parseInt(st.nextToken());

            DFS(1, N, 1, N);
            System.out.println();
        }
    }

    static void DFS(int preStart, int preEnd, int inStart, int inEnd) {

        if (preStart > preEnd || inStart > inEnd)
            return;

        int root = preOrder[preStart];
        int inRoot = 0;
        for (int i = 1; i <= N; i++) {
            if (inOrder[i] == root) {
                inRoot = i;
                break;
            }
        }

        int left = inRoot - inStart;

        // Left
        DFS(preStart + 1, preStart + left, inStart, inRoot - 1);

        // Right
        DFS(preStart + left + 1, preEnd, inRoot + 1, inEnd);

        System.out.print(root + " ");
    }
}