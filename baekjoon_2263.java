// 트리의 순회 / baekjoon_2263.java
// https://www.acmicpc.net/problem/2263

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, index;
	static int[] in, post, pre;

	static void input() throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		index = 0;
		in = new int[N];
		post = new int[N];
		pre = new int[N];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			in[i] = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++)
			post[i] = Integer.parseInt(st.nextToken());

		br.close();
	}

	static void func(int inS, int inE, int postS, int postE) {
		if(inS <= inE && postS <= postE) {
			
			// preorder는 root가 맨 앞으로 온다
			// postorder는 root가 맨 뒤에 있다
			pre[index] = post[postE];
			index++;	

			int root = inS;
			// inorder에서 루트 기준으로 왼쪽 서브트리 오른쪽 서브트리로 나눌 수 있다.
			for(int i = 0; i < N; i++) {
				if(in[i] == post[postE]) {
					root = i;
					break;
				}
			}

			// left subtree
			func(inS, root - 1, postS, postS + ( root - 1 - inS));

			// right subtree
			func(root + 1, inE, postS + ( root - 1 - inS) + 1, postE - 1);
		}


	}

	static void solve() {

		func(0, N - 1, 0, N - 1);
		for(int i = 0; i < N; i++)
			System.out.print(pre[i] + " ");

	}

	public static void main(String[] args) throws Exception {
		input();
		solve();
	}

}
