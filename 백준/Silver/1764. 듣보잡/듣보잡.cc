#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N,M;
	cin >> N >> M;
	vector<string> v1, v2,result;

	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		v1.push_back(name);
	}
	sort(v1.begin(), v1.end());
	for (int i = 0; i < M; i++) {
		string name;
		cin >> name;
		v2.push_back(name);
	}
	sort(v2.begin(), v2.end());

	if (v1.size() < v2.size()) {
		for (auto a : v1) {
			int left = 0;
			int right = v2.size() - 1;
			int mid = 0;
			while (left <= right) {
				mid = (left + right) / 2;
				if (a == v2[mid]) {
					result.push_back(a);
					break;
				}
				else if (a > v2[mid]) {
					left = mid + 1;
				}
				else
					right = mid - 1;
			}
		}
	}
	else{
		for (auto a : v2) {
			int left = 0;
			int right = v1.size() - 1;
			int mid = 0;
			while (left <= right) {
				mid = (left + right) / 2;
				if (a == v1[mid]) {
					result.push_back(a);
					break;
				}
				else if (a > v1[mid]) {
					left = mid + 1;
				}
				else
					right = mid - 1;
			}
		}
	}


	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (auto a : result) {
		cout << a << "\n";
	}

}