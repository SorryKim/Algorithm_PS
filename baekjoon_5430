// baekjoon_5430
// https://www.acmicpc.net/problem/5430

#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	for(int test = 0; test < T; test++) {
		deque<int> deq;
		vector<char> v;
		bool reverse = false;
		bool error = false;

		string s;
		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			v.push_back(s[i]);
		}

		int n;
		cin >> n;
		string str;
		cin >> str;
		string temp ="";

		for (int i = 0; i < str.size(); i++) {
			if (deq.size() == n)
				break;
			if (str[i] == '[')
				continue;
			else if (str[i] >= '0' && str[i] <= '9') {
				temp += str[i];
			}
			else if (str[i] == ',' || str[i] == ']') {
				if (temp == "")
					continue;
				deq.push_back(stoi(temp));
				temp = "";
			}
		}

		for (auto a : v) {
			if (a == 'R') {
				reverse = (!reverse);
			}
			else {
				if (deq.size() == 0) {
					error = true;
					continue;
				}
				else if (reverse)
					deq.pop_back();
				else
					deq.pop_front();
			}
		}

		if (error) {
			cout << "error\n";
		}
		else {
			if (reverse) {
				cout << "[";
				while (!deq.empty()) {
					if (deq.size() == 1) {
						cout << deq.back();
						deq.pop_back();
					}
					else {
						cout << deq.back() << ",";
						deq.pop_back();
					}
				}
				cout << "]\n";
			}
			else {
				cout << "[";
				while (!deq.empty()) {
					if (deq.size() == 1) {
						cout << deq.front();
						deq.pop_front();
					}
					else {
						cout << deq.front() << ",";
						deq.pop_front();
					}
				}
				cout << "]\n";
			}
		}

	}
}
