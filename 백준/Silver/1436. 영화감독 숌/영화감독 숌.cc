#include <iostream>
#include <string>

using namespace std;

int main(){

	int n;
	cin >> n;
	int count = 0;
	int num = 665;

	while (true) {
		if (count == n)
			break;
		num++;
		string s = to_string(num);
		bool b = false;

		for (int i = 0; i < s.size(); i++) {
			if (i <= s.size() - 3) {
				if ((s[i] == '6' && s[i + 1] == '6')&& s[i+2] =='6') {
					count++;
					b = true;
					break;
				}
			}
		}
	}
	
	cout << num;
}