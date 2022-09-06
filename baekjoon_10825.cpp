// baekjoon_10825
// https://www.acmicpc.net/problem/10825

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student {
public:
	string name;
	int korean;
	int english;
	int math;

	Student(string s, int a, int b, int c) {
		this->name = s;
		this->korean = a;
		this->english = b;
		this->math = c;
	}

};

bool compare(const Student &s1, const Student & s2) {
	if (s1.korean == s2.korean && s1.english == s2.english && s1.math == s2.math)
		return s1.name < s2.name;
	if (s1.korean == s2.korean && s1.english == s2.english)
		return s1.math > s2.math;
	if (s1.korean == s2.korean)
		return s1.english < s2.english;

	return s1.korean > s2.korean;

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<Student> v;
	for (int i = 0; i < N; i++) {
		string name;
		int korean, english, math;
		cin >> name >> korean >> english >> math;
		Student s = { name, korean, english, math };
		v.push_back(s);
	}

	sort(v.begin(), v.end(), compare);

	for (auto a : v) {
		cout << a.name << "\n";
	}

}
