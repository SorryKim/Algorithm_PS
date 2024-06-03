// 불 / baekjoon_5427.java
// https://www.acmicpc.net/problem/5427

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static class Pos{
		int x,y,cnt;

		public Pos(int x, int y, int cnt) {
			this.x = x;
			this.y = y;
			this.cnt = cnt;
		}
	}
	
	public static int w,h;
	public static char[][] graph;
	public static Queue<Pos> q, fire;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for(int t = 0; t < T; t++) {

			StringTokenizer st = new StringTokenizer(br.readLine());
			q = new LinkedList<>();
			fire = new LinkedList<>();
			h = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());
			graph = new char[w][h];

			for(int i = 0; i < w; i++) {
				String s = br.readLine();
				for(int j = 0; j < h; j++) {
					char ch = s.charAt(j);
					graph[i][j] = ch;
					if(ch == '*')
						fire.add(new Pos(i,j,0));
					else if(ch == '@')
						q.add(new Pos(i,j,0));
				}
			}
			Solve();
		}
	}

	static void Solve() throws IOException{
		int result = BFS();

		if(result == 0)
			System.out.println("IMPOSSIBLE");
		else
			System.out.println(result);

	}

	public static int BFS() {

		int result = 0;
		int[] moveX = { -1, 1 ,0 ,0 };
		int[] moveY = { 0, 0, 1, -1 };

		while(!q.isEmpty()) {
			int size = fire.size();
			for(int i = 0; i < size; i++) {

				Pos nowFire = fire.poll();

				for(int j = 0; j < 4; j++) {
					int nowX = nowFire.x + moveX[j];
					int nowY = nowFire.y + moveY[j];

					if(nowX < 0 || nowX >= w || nowY < 0 || nowY >= h)
						continue;

					if(graph[nowX][nowY] == '@' || graph[nowX][nowY] == '.') {
						graph[nowX][nowY] = '*';
						fire.add(new Pos(nowX, nowY, 0));
					}
				}
			}

			size = q.size();
			for(int i = 0; i < size; i++) {
				Pos now = q.poll();
				for(int j = 0; j < 4; j++) {
					int nowX = now.x + moveX[j];
					int nowY = now.y + moveY[j];

					if(nowX < 0 || nowX >= w || nowY < 0 || nowY >= h) {
						result += now.cnt + 1;
						return result;
					}

					if(graph[nowX][nowY] == '.') {
						graph[nowX][nowY] = '@';
						q.add(new Pos(nowX, nowY, now.cnt + 1));
					}
				}
			}
		}

		return result;
	}
}
