// 움직이는 미로 탈출 / baekjoon_16954.java
// https://www.acmicpc.net/problem/16954

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

	static char[][] map;

	static boolean check(int r, int c, int t) {

		return 0 <= r - t && r - t <= 7 && 0 <= c && c <= 7 && map[r - t][c] == '#';
	}

	static int BFS() {
		Queue<int[]> queue = new LinkedList<>();
		queue.add(new int[] { 7, 0, 0 });

		while (!queue.isEmpty()) {
			int[] a =  queue.remove();
			int r = a[0], c = a[1], t = a[2];

			// 맵을 벗어나는 경우
			if (r < 0 || c < 0 || r > 7 || c > 7)
				continue;

			// 벽이랑 부딪히는 경우
			if (check(r, c, t))
				continue;


			if (r == 0 && c == 7)
				return 1;

			for(int i = -1; i <= 1; i++) {
				for(int j = -1; j <=1; j++) {
					if(!check(r + i, c + j, t)) {
						queue.add(new int[] { r + i, c + j, t + 1});
					}
				}
			}
		}

		return 0;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		map = new char[8][8];

		for (int i = 0; i < 8; i++) {
			String s = reader.readLine();
			for(int j = 0; j < 8; j++) {
				char ch = s.charAt(j);
				map[i][j] = ch;
			}
		}

		
		System.out.println(BFS());
		reader.close();
	}
}
