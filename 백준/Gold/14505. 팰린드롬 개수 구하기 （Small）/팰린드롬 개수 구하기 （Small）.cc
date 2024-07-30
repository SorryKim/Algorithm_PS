#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

    string s;
    int DP[31][31];

    cin >> s;

    int n = s.size();

	for (int i = 0; i < n; i++){
		DP[i][i] = 1;
		if (i + 1 < n) {
			if (s[i] == s[i + 1])
				DP[i][i + 1] = 3;
			else
				DP[i][i + 1] = 2;
		}
	}

	for (int i = 2; i < n; i++) {
		for (int left = 0; left < n; left++) {
			int right = i + left;
			if (right >= n)
				break;

			if (s[left] == s[right])
				DP[left][right] = DP[left + 1][right] + DP[left][right - 1] + 1;
			else
				DP[left][right] = DP[left + 1][right] + DP[left][right - 1] - DP[left + 1][right - 1];
		}
	}

	cout << DP[0][n - 1];
    return 0;
}
