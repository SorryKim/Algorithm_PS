#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

vector<int> v;
bool visited[10] = { false, };
int arr[10] = { 0, };

void DFS(int cnt) {

	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	int temp = 0;

	for (int i = 0; i < v.size(); i++) {
		if (temp != v[i]) {
			arr[cnt] = v[i];
			temp = v[i];
			DFS(cnt + 1);
		}
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
	DFS(0);

	return 0;
}