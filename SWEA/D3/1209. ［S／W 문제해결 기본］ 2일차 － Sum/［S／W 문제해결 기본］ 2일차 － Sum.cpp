#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int T;
  

    for (int testCase = 1; testCase <= 10; ++testCase) {
        
        cin >> T;
        int arr[101][101];

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> arr[i][j];
            }
        }

        int ans = 0;

        for (int i = 0; i < 100; i++) {
            int sum1 = 0;
            int sum2 = 0;
            for (int j = 0; j < 100; j++) {
                sum1 += arr[i][j];
                sum2 += arr[j][i];
            }

            ans = max(ans, max(sum1, sum2));
        }

        int temp1 = 0;
        int temp2 = 0;
        for (int i = 0; i < 100; i++) {
            temp1 += arr[i][i];
            temp2 += arr[i][99 - i];
        }

        ans = max(ans, max(temp1,temp2));
        
        
        cout << "#" << testCase << " " << ans << "\n";
    }

    return 0;
}
