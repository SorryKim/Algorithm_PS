import java.io.*;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

	static int N, K;
	static int[] tree;
    static int ans = 0;

    public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		K = Integer.parseInt(br.readLine());
		N = (int)Math.pow(2, K+1) - 1;
		tree = new int[N + 1];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 2; i <= N; i++) tree[i] = Integer.parseInt(st.nextToken());
		
		DFS(1,0);

		System.out.println(ans);
	}
	
	static int DFS(int node, int h) {

        // 리프노드
		if(h == K) {
			ans += tree[node];
			return tree[node];
		}
		
        int left =  node * 2;
        int right = node * 2 + 1;
		
        int leftCost = DFS(left, h + 1);
        int rightCost = DFS(right, h + 1);

		ans += tree[node] + Math.abs(leftCost - rightCost);

		return tree[node] + Math.max(leftCost, rightCost);
	}
}