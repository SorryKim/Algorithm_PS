// 미세먼지 안녕! / baekjoon_17144.java
// https://www.acmicpc.net/problem/17144

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int R, C, T;
	static int[][] arr;
	static int top, bottom;

	static void Input() throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());

		arr = new int[R][C];
		top = -1;
		for (int i = 0; i < R; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < C; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if (arr[i][j] == -1 && top == -1) {
					top = i;
					bottom = i + 1;
				}
			}
		}
		br.close();
	}

	// 먼지의 확산 메소드
	static void Diffusion() {

		int[][] temp = new int[R][C];
		Copy(temp, arr);

		int[] moveX = { 1, -1, 0, 0 };
		int[] moveY = { 0, 0, 1, -1 };

		for (int x = 0; x < R; x++) {
			for (int y = 0; y < C; y++) {
				if (arr[x][y] == -1)
					continue;
				for (int i = 0; i < 4; i++) {

					int nextX = x + moveX[i];
					int nextY = y + moveY[i];
					int dust = arr[x][y] / 5;
					if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C)
						continue;
					if (arr[nextX][nextY] == -1)
						continue;

					temp[nextX][nextY] += dust;
					temp[x][y] -= dust;
				}

			}
		}

		Copy(arr, temp);
	}

	static void Copy(int[][] arr1, int[][] arr2) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++)
				arr1[i][j] = arr2[i][j];
		}
	}

	// 공기청정기의 작동 메소드
	static void Cleaning() {

		// 위쪽 공기청정기
		for (int x = top - 1; x > 0; x--) {
            arr[x][0] = arr[x - 1][0];
        }

        for (int y = 0; y < C - 1; y++) {
            arr[0][y] = arr[0][y + 1];
        }

        for (int x = 0; x < top; x++) {
            arr[x][C - 1] = arr[x + 1][C - 1];
        }

        for (int y = C - 1; y > 1; y--) {
            arr[top][y] = arr[top][y - 1];
        }

        arr[top][1] = 0;

        // 아래쪽 공기청정기
        for (int x = bottom + 1; x < R - 1; x++) {
            arr[x][0] = arr[x + 1][0];
        }

        for (int y = 0; y < C - 1; y++) {
            arr[R - 1][y] = arr[R - 1][y + 1];
        }

        for (int x = R - 1; x > bottom; x--) {
            arr[x][C - 1] = arr[x - 1][C - 1];
        }

        for (int y = C - 1; y > 1; y--) {
            arr[bottom][y] = arr[bottom][y - 1];
        }

        arr[bottom][1] = 0;
	}

	// 현재남은 먼지의 양을 반환하는 메소드
	static int CheckDust() {

		int sum = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (arr[i][j] > 0)
					sum += arr[i][j];
			}
		}

		return sum;
	}

	static void Solve() {

		for (int i = 0; i < T; i++) {
			Diffusion();
			Cleaning();
		}

		System.out.println(CheckDust());
	}

	public static void main(String[] args) throws Exception {
		Input();
		Solve();
	}

}
