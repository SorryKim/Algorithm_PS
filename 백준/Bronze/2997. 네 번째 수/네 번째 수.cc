#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
    
	vector<int> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);

	sort(v.begin(), v.end());
	a = v[0];
	b = v[1];
	c = v[2];
	
	// 첫번째 or 마지막인 경우
	if(2*b == a + c){

		int d = b - a;
		cout << a - d;
	}
	else{
		// 2번째인 경우
		if(b - a > c - b)
			cout << (b + a) / 2;
		else
			cout << (b + c) / 2;
	}

    return 0;
}
