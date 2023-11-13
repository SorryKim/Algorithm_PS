#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    int arr[11][11];
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++)
            arr[i][j] = 1;
    }



    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < i; j++) {
            arr[i][j] = arr[i - 1][j] + arr[i-1][j-1];
        } 
    }

    for (int test = 1; test <= T; test++) {
        int N;
        cin >> N;

        cout << "#" << test << "\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++)
                cout << arr[i][j] << " ";
            cout << "\n";
        }
        

        
    }

  
}