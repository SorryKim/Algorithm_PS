#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[101][101];

int Move(int start) {
    int x = start;

    for (int y = 99; y >= 0; y--) {
        if (x > 0 && arr[y][x - 1] == 1) {
            // 왼쪽으로 이동
            while (x > 0 && arr[y][x - 1] == 1) {
                x--;
            }
        }
        else if (x < 99 && arr[y][x + 1] == 1) {
            // 오른쪽으로 이동
            while (x < 99 && arr[y][x + 1] == 1) {
                x++;
            }
        }
    }

    return x;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
   
    
    for (int test = 1; test <= 10; test++) {
        int destination;
        cin >> T;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 2) {
                    destination = j;
                }
            }
        }

        int ans = Move(destination);

        cout << "#" << test << " " << ans << "\n";
    }

    return 0;
}
