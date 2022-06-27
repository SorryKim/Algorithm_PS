// 트리 / baekjoon_1068.cpp
// https://www.acmicpc.net/problem/1068

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
vector<int> tree[51];
bool check[51];
int cnt = 0;

// 서브트리를 지우는 메소드
void DFS1(int n) {
	for (int i = 0; i < tree[n].size(); i++) {
		if (check[tree[n][i]] == true) {
			DFS1(tree[n][i]);
		}
	}
	check[n] = false;
}


// 리프노드의 갯수를 세는 메소드
void DFS2(int n) {


	bool b = true; // 리프노드임을 확인하는 부울변수
	if (check[n] == false)
		return;

	for (int i = 0; i < tree[n].size(); i++) {
		if (check[tree[n][i]] == true) {
			b = false;
			DFS2(tree[n][i]);
		}
	}

	// 리프노드인 경우
	if (b)
		cnt++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int root = 0;

	for (int i = 0; i <= 50; i++)
		check[i] = false;
	

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == -1) {
			root = i;
			check[i] = true;
			continue;
		}
		else {
			tree[num].push_back(i);
			check[i] = true;
		}
	}

	int del;
	cin >> del;
	DFS1(del);
	DFS2(root);
	// 결과출력
	cout << cnt;
}
