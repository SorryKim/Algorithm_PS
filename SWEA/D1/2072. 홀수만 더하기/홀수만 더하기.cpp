#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int test = 1; test <= T; test++) {

        int sum = 0;
        for (int i = 0; i < 10; i++) {
            int num;
            cin >> num;
            if (num % 2 != 0) 
                sum += num;
        }

        cout << "#" << test << " " << sum << "\n";
    }
}