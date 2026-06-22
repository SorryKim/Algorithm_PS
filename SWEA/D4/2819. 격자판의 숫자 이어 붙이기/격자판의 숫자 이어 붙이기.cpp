#include <iostream>
#include <vector>
#include <set>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, string now, int (&board)[4][4], set<string> &numbers){

    now += '0' + board[x][y];

    if(now.length() == 7){
        numbers.insert(now);
        return;
    }

    for(int i = 0; i < 4; i++){

        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < 4 && ny >= 0 && ny < 4){
            dfs(nx, ny , now, board, numbers);
        }
    }

    return;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int T;
    cin >> T;

    for(int TC = 1; TC <= T; TC++){

        int board[4][4];
        set<string> numbers;

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cin >> board[i][j];
            }
        }

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                dfs(i, j, "", board, numbers);
            }
        }

        cout << "#" << TC << " " << numbers.size() << "\n";
    }

    return 0;
}