// 다각형의 면적/ baekjoon_2166.java
// https://www.acmicpc.net/problem/2166

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


class Point{

	long x,y;

	Point(long x,long y){
		this.x = x;
		this.y = y;
	}
}

public class Main {

	static int N;
	static Point[] arr;
	static long result;

	public static long calc(Point p1, Point p2, Point p3) {
		long sum = (p1.x*p2.y + p2.x*p3.y + p3.x * p1.y) - (p1.y*p2.x + p2.y*p3.x + p3.y*p1.x);
		return sum;
	}

	public static void Input() throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		arr = new Point[N];
		result = 0;

		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			arr[i] = new Point(x,y);
		}

	}

	static void Solve() {

		for(int i = 1; i < N - 1; i++) {
			result += calc(arr[0], arr[i], arr[i+1]);
		}

		result = Math.abs(result);
		System.out.println(String.format("%.1f", result / 2.0));
	}

	public static void main(String[] args) throws Exception {
		Input();
		Solve();
	}

}
