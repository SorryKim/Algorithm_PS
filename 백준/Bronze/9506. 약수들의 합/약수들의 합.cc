#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;

        if (n == -1) break;

        vector<int> divisors;
        int sum = 0;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i != n) {
                    divisors.push_back(i);
                    sum += i;
                }

                int other = n / i;
                if (other != i && other != n) {
                    divisors.push_back(other);
                    sum += other;
                }
            }
        }

        if (sum == n) {
            sort(divisors.begin(), divisors.end());

            cout << n << " = ";
            for (int i = 0; i < divisors.size(); i++) {
                cout << divisors[i];
                if (i != divisors.size() - 1)
                    cout << " + ";
            }
            cout << "\n";
        } else {
            cout << n << " is NOT perfect.\n";
        }
    }

    return 0;
}