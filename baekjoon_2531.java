// 회전 초밥/ baekjoon_2531.java
// https://www.acmicpc.net/problem/2531

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, d, k, c;
	static int[] sushi, eat;


	static void Input() throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		sushi = new int[N];
		eat = new int[d + 1];

		for(int i = 0; i < N; i++)
			sushi[i] = Integer.parseInt(br.readLine());

	}


	static int Solve() {

		int cnt = 0;
		for(int i = 0; i < k; i++) {
			if(eat[sushi[i]] == 0)
				cnt++;
			eat[sushi[i]]++;
		}

		int result = cnt;

		for(int i = 1; i < N; i++) {

			if(result <= cnt) {
				if(eat[c] == 0)
					result = cnt + 1;
				else
					result = cnt;
			}

			int end = (i + k - 1) % N;
			if(eat[sushi[end]] == 0)
				cnt++;
			eat[sushi[end]]++;
			eat[sushi[i - 1]]--;
			if(eat[sushi[i-1]] == 0)
				cnt--;
		}

		return result;
	}

	public static void main(String[] args) throws Exception {
		Input();
		System.out.println(Solve());

	}
}
