#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int test = 1; test <= 10; test++) {
        long long ans = 0;
        int N;
        cin >> N;
        int arr[100];

        for (int i = 0; i < 100; i++) {
            cin >> arr[i];
        }

        while (N--) {
            sort(arr, arr + 100);
            arr[0]++;
            arr[99]--;
        }
        sort(arr, arr + 100);
        ans = arr[99] - arr[0];


       

        cout << "#" << test << " " << ans << "\n";
    }

    return 0;
}
