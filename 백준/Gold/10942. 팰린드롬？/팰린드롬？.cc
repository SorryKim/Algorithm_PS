#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool DP[2001][2001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Define variable
    int N, M;
    int arr[2001];


    // Input
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    cin >> M;

    // DP 테이블 초기화
    // DP[i][j] : i ~ j까지의 배열이 팰린드롬 여부
    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= 2000; j++) {
            DP[i][j] = false;
        }
    }


    // 수열의 길이가 1, 2인 경우
    for (int i = 1; i <= 2000; i++) {
        DP[i][i] = true;
       
    }

    for (int length = 1; length <= N; length++) {
        
        for (int start = 1; start <= N; start++) {

            int end = start + length;
            if (end > N)
                break;
            if (length == 1) {
                if (arr[start] == arr[end])
                    DP[start][end] = true;
            }
            else {
                if(arr[start] == arr[end] && DP[start + 1][end - 1])
                    DP[start][end] = true;
            }
        }
    }
    
    while (M--) {
        int left, right;
        cin >> left >> right;
        
        cout << DP[left][right] << "\n";
        
    }

    /*cout << "DP 테이블\n";

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << DP[i][j] << " ";
        }
        cout << "\n";
    }*/
    return 0;
}
