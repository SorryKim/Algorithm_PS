#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

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

	for (int i = 1; i <= N; i++) {
		if (cnt == 0 && visited[i] == false) {
			visited[i] = true;
			arr[cnt] = i;
			DFS(cnt + 1);
			visited[i] = false;
		}
		else if (visited[i] == false) {
			if (arr[cnt - 1] < i) {
				visited[i] = true;
				arr[cnt] = i;
				DFS(cnt + 1);
				visited[i] = false;
			}
		}
	}
}

int main() {
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N >> M;
	
	DFS(0);

    return 0;
}