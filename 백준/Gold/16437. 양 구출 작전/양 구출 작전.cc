#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 123457;

int N;
vector<int> tree[MAX];
vector<bool> isWolf;
vector<int> cnt;

void Input(){
    cin >> N;
    isWolf.resize(N + 1, false);
    cnt.resize(N + 1);

	for (int i = 2; i <= N; i++) {
        char animal;
        int a, p;
		cin >> animal >> a >> p;

		if (animal == 'W') isWolf[i] = true;
		cnt[i] = a;
		tree[p].push_back(i);
	}
}

long long DFS(int now) {

	int size = tree[now].size();
    long long temp = 0;

    // 리프노드 처리
	if (size == 0) {
		if (isWolf[now]) return 0;
		else return cnt[now];
    }

    // Bottom Up
	for (int i = 0; i < size; i++) temp += DFS(tree[now][i]);
	
	if (isWolf[now]) temp -= cnt[now];
	else temp += cnt[now];

    // 양이 다 잡아 먹힘
	if (temp <= 0) return 0;
	
    return temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
    Input();
	cout << DFS(1) << '\n';

}