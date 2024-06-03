// IQ Test / baekjoon_1111.java
// https://www.acmicpc.net/problem/1111

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[] arr;

	public static void main(String[] args) throws Exception {

		Input();
		Solve();

	}

	static void Input() throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[N + 1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
	}

	static void Solve() throws IOException{

		// 답이 여러가지인 경우
		if (N == 1 || (N == 2 && arr[0] != arr[1])) {
            System.out.println("A");
		}
		else if(N == 2 && arr[0] == arr[1]) {
			System.out.println(arr[0]);
		}
		else {
			
			int a, b;
			if(arr[1] == arr[0] ) {
				a = 1;
				b = 0;
			}
			else {
				a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
				b = arr[1] - (arr[0] * a);
			}
			
			boolean flag = true;
			for(int i = 1; i < N; i++) {
				if(arr[i] != (arr[i - 1] * a + b)) {
					flag = false;
					break;
				}
			}
			if(!flag)
				System.out.println("B");
			else
				System.out.println(arr[N - 1]*a  + b);

		}
	}

}
