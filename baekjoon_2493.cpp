// 탑 / baekjoon_2493.cpp
// https://www.acmicpc.net/problem/2493

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);
	int N;
	vector<int> v;
	stack<pair<int,int>> s; // < 탑의 순서, 높이 > 
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int height;
		cin >> height;
		v.push_back(height);
	}
	
	for (int i = 0; i < N ; i++) {
		// 이전 탑들의 정보를 스택에 넣으면서 진행
		while (!s.empty() && s.top().second < v[i]) {
			s.pop();
		}
		// 스택이 비는 경우 전송실패이므로 0출력
		if (s.empty())
			cout << "0 ";
		// 스택의 top부분의 탑이 전송가능한 탑이므로 출력
		else
			cout << s.top().first << " ";
		s.push({ i + 1,v[i] });
	}

}
