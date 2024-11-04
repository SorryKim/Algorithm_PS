#include <iostream>
#include <vector>
using namespace std;

int N;
int child[201];
int dp[201][201];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<int> v;

    for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (v.empty() || num > v.back()) 
			v.push_back(num);
		else {
			int index = lower_bound(v.begin(), v.end(), num) - v.begin();
			v[index] = num;
		}

	}

    cout << N - v.size();
    return 0;
}