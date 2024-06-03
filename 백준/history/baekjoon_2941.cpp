// 크로아티아 알파벳 / baekjoon_2941.cpp
// https://www.acmicpc.net/problem/2941

#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str[8] = { "c=", "c-", "dz=", "d-", "lj", "nj","s=","z=" };
	string s;
	cin >> s;

	for (int i = 0; i < 8; i++) {

		while (true) {

			// 찾는 문자열에 첫번째 인덱스를 반환하는 find
			int index = s.find(str[i]);
			
			// string::npos -> 찾는 문자열이 없는 경우 반환
			if (index == string::npos)
				break;

			// 해당문자열을 한글자로 replace
			s.replace(index, str[i].length(), "A");
		}
	}

	cout << s.length();

}
