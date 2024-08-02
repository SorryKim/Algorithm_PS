#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
vector<char> v;
char chars[5] = { 'a', 'e', 'i', 'o', 'u' };
char answer[15];

void DFS(int idx, int start, int cnt1, int cnt2) {

	if (idx == L) {

		if (cnt1 >= 2 && cnt2 >= 1) {
			string s = "";

			for (int i = 0; i < L; i++)
				s += answer[i];

			cout << s << "\n";
		}

		return;
	}

	for (int i = start; i < C; i++) {

		answer[idx] = v[i];
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
			DFS(idx + 1, i + 1, cnt1, cnt2 + 1);
		else
			DFS(idx + 1, i + 1, cnt1 + 1, cnt2);

		
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		char ch;
		cin >> ch;

		v.push_back(ch);
	}
	
	sort(v.begin(), v.end());
	
	DFS(0, 0, 0, 0);

	return 0;
}