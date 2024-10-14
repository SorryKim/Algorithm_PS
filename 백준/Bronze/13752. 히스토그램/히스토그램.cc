#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		while(n--)
			cout << '=';
		cout << '\n';
	}


    
    return 0;
}
