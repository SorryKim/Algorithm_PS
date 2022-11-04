// TV 크기 / baekjoon_1297.java
// https://www.acmicpc.net/problem/1297

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;



public class Main {

	static int D, H, W;

	public static void Input() throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		D = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		W = Integer.parseInt(st.nextToken());

		br.close();

	}



	static void Solve() {
		double result = Math.sqrt(Math.pow(D, 2) / (Math.pow(H, 2) + Math.pow(W, 2)));
		System.out.print((int)(result*H) +" ");
		System.out.println((int)(result*W));
	}

	public static void main(String[] args) throws Exception {
		Input();
		Solve();
	}

}
