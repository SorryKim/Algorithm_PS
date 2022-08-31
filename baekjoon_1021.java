// 회전하는 큐 / baekjoon_1021.java
// https://www.acmicpc.net/problem/1021

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

	static int cnt = 0;
	static int N, M;
	static int[] arr;
	static LinkedList<Integer> deque = new LinkedList<Integer>();

	static void input() throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[M];

		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < M; i++)
			arr[i] = Integer.parseInt(st.nextToken());

		for(int i = 1; i <= N; i++)
			deque.offerLast(i);

		br.close();
	}

	static void solve() {
		for(int i = 0; i < M; i++) {
			int idx = deque.indexOf(arr[i]);
			int half = ((deque.size() % 2) == 0) ? (deque.size() / 2 - 1) : (deque.size() / 2);

			// 2번 연산
			if(idx <= half) {
				for(int j = 0; j < idx; j++) {
					int num = deque.pollFirst();
					deque.offerLast(num);
					cnt++;
				}
			}
			// 3번 연산
			else {
				for(int j = 0; j < deque.size() - idx; j++) {
					int num = deque.pollLast();
					deque.offerFirst(num);
					cnt++;
				}
			}
			deque.pollFirst();
		}
		System.out.println(cnt);
	}

	public static void main(String[] args) throws IOException{

		input();
		solve();

	}


}
