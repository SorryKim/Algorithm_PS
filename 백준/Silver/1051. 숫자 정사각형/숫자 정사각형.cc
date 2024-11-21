#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int arr[51][51];
    int answer = 1;
    
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++)
            arr[i][j] = s[j] - '0';
    }


    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            for(int length = 1; length + x < M; length++){
                if(y + length < N){
                    int a = arr[y][x];
                    int b = arr[y][x + length];
                    int c = arr[y + length][x];
                    int d = arr[y + length][x + length];

                    if(a == b && b == c && c == d){
                        answer = max(answer, (length + 1) * (length + 1));
                    }
                }
            }
        }
    }

    cout << answer << '\n';
    
    return 0;
}
