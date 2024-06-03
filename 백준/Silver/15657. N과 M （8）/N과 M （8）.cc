#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> v;
bool visited[10] = { false, };
int arr[10] = { 0, };

void DFS(int n, int cnt) {

	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = n; i < v.size(); i++) {
		arr[cnt] = v[i];
		DFS(i, cnt + 1);
	}
}

int main() {
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());


	DFS(0, 0);

	return 0;
}