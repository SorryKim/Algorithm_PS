#include <iostream>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int test = 1; test <= T; test++) {
        double sum = 0;
        for (int i = 0; i < 10; i++) {
            int num;
            cin >> num;
            sum += num;
            
        }
        double avg = sum / 10;
        cout << "#" << test << " " << round(avg) << "\n";
    }
}