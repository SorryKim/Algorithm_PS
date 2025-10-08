#include <iostream>
#include <vector>

using namespace std;

int N;
char board[401][401];

// x, y 채우기 시작 지점
void draw(int depth, int x, int y){

    if(depth > 2 * N - 1) return;
    int len = 2* depth - 1;

    for(int i = x; i < x + len; i++){
        board[i][y] = '*';
        board[i][y + len - 1] = '*';
    }
    
    for(int i = y; i < y + len; i++){
        board[x][i] = '*';
        board[x + len - 1][i] = '*';
    }

    draw(depth + 2, x - 2, y - 2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 1; i <= 400; i++){
        for(int j = 1; j <= 400; j++){
            board[i][j] = ' ';
        }
    }

    draw(1, 2 * N - 1, 2 * N - 1);

    for(int i = 1; i <= 4 * N - 3; i++){
        for(int j = 1; j <= 4 * N - 3; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }
    

}