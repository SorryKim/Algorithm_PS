#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int sum = 0;
    while(N--){
        int num;
        cin >> num;
        sum += num;
    }
    cout << sum << '\n';
    return 0;
}
