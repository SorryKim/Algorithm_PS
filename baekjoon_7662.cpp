// baekjoon_7662
// https://www.acmicpc.net/problem/7662

// priority queue로 풀기 실패
//#include <iostream>
//#include <queue>
//using namespace std;
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int T;
//	cin >> T;
//
//	for (int test = 0; test < T; test++) {
//		int k;
//		cin >> k;
//		priority_queue<int, vector<int>> max;
//		priority_queue<int, vector<int>, greater<int >> min;
//		int cnt = 0;
//
//		for (int i = 0; i < k; i++) {
//			char cmd;
//			int n;
//			cin >> cmd >> n;
//
//			if (cmd == 'I') {
//				max.push(n);
//				min.push(n);
//				cnt++;
//			}
//
//			if (cmd == 'D') {
//				if (n == 1) {
//					if (cnt != 0) {
//						max.pop();
//						cnt--;
//					}
//					else {
//						while (!min.empty()) {
//							min.pop();
//						}
//					}
//					
//				}
//				if (n == -1) {
//					if (cnt != 0) {
//						min.pop();
//						cnt--;
//					}
//					else{
//						while (!max.empty()) {
//							max.pop();
//						}
//					}
//				}
//			}
//		}
//		// 출력 부분
//		if (cnt == 0)
//			cout << "EMPTY" << "\n";
//		else if (cnt == 1) {
//			cout << max.top();
//		}
//		else if (max.size() > 0 && min.size() > 0) {
//			cout << max.top() << " " << min.top() << "\n";
//		}
//		else if (max.size() > 0 && min.size() == 0) {
//			int v1, v2;
//			v1 = max.top();
//			max.pop();
//			while (!max.empty()) {
//				v2 = max.top();
//				max.pop();
//			}
//			cout << v1 << " " << v2 << "\n";
//		}
//		else if (max.size() == 0 && min.size() > 0) {
//			int v1, v2;
//			v1 = min.top();
//			min.pop();
//			while (!min.empty()) {
//				v2 = min.top();
//				min.pop();
//			}
//			cout << v1 << " " << v2 << "\n";
//		}
//	}
//}

// multiset을 이용한 우선순위 deque 구현

#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int k;
		cin >> k;
		multiset<int> set;
		for (int i = 0; i < k; i++) {
			char cmd;
			int n;
			cin >> cmd >> n;
			if (cmd == 'I') {
				set.insert(n);
			}
			if (cmd == 'D') {
				if (!set.empty()) {
					if (n == 1) {
						// end는 끝값 다음 주소값을 가리키고 있다
						auto tmp = set.end();
						tmp--;
						set.erase(tmp);
					}
					else {
						set.erase(set.begin());
					}
				}
				else
					continue;
			}
		}
		if (set.empty()) {
			cout << "EMPTY" << "\n";
		}
		else {
			auto tmp = set.end();
			tmp--;
			cout << *tmp << " " << *set.begin() << "\n";
		}
		
	}

}
