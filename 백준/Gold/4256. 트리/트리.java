import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static int[] preorder, inorder;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int test = 0; test < T; test++) {

            N = Integer.parseInt(br.readLine());
            preorder = new int[N + 1];
            inorder = new int[N + 1];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++)
                preorder[i] = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++)
                inorder[i] = Integer.parseInt(st.nextToken());

            Build(1, N, 1, N);
            System.out.println();
        }

    }

    static void Build(int preStart, int preEnd, int inStart, int inEnd) {

        if (preStart > preEnd)
            return;

        // 현재 서브트리의 루트
        int root = preorder[preStart];

        int inRootIdx = 0;

        for (int i = 1; i <= N; i++) {
            if (inorder[i] == root) {
                inRootIdx = i;
                break;
            }
        }

        // 왼쪽 서브트리 크기
        int leftSize = inRootIdx - inStart;

        // Left
        Build(preStart + 1, preStart + leftSize, inStart, inRootIdx - 1);

        // Right
        Build(preStart + leftSize + 1, preEnd, inRootIdx + 1, inEnd);

        System.out.print(root + " ");

        return;
    }

}