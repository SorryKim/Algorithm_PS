#include <iostream>
using namespace std;

int main() {
	
	int T = 0;
	cin >> T;

	for (int test = 1; test <= T; test++) {
		int N, M;
		cin >> N >> M;

		int ans = 0;
		int matrix[16][16];

		for (int i = 0; i <= 15; i++) {
			for (int j = 0; j <= 15; j++)
				matrix[i][j] = 0;
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> matrix[i][j];
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				matrix[i][j] += matrix[i][j - 1];
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				matrix[j][i] += matrix[j-1][i];
			}
		}
		
		for (int i = 1; i <= N - M + 1; i++) {
			for (int j = 1; j <= N - M + 1; j++) {
				int a = i + M - 1;
				int b = j + M - 1;
				int val = matrix[a][b] - matrix[a][j - 1] - matrix[i - 1][b] + matrix[i - 1][j - 1];
				ans = max(ans, val);
			}
		}

		
		cout << "#" << test << " " << ans << "\n";
	}

	return 0;
}