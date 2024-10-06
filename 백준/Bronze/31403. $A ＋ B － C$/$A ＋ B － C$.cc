#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A,B,C;

    cin >> A >> B >> C;

    cout << A + B - C << '\n';

    int temp = stoi(to_string(A) + to_string(B)) - C;
    cout << temp << '\n';


    return 0;
}
