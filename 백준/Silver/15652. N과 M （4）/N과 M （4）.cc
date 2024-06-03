#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

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

	for (int i = n; i <= N; i++) {
		arr[cnt] = i;
		DFS(i, cnt + 1);
	}
}

int main() {
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N >> M;
	
	DFS(1, 0);

    return 0;
}