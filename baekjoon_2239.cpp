// 스도쿠 / baekjoon_2239.cpp
// https://www.acmicpc.net/problem/2239

#include <iostream>
#include <vector>
using namespace std;

int sudoku[10][10];
vector<pair<int, int>> v;

void Input() {

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            scanf("%1d", &sudoku[i][j]);
            if (sudoku[i][j] == 0) {
                v.push_back({ i,j });
            }
        }
    }

}

void Output() {

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            printf("%d", sudoku[i][j]);
        }
        printf("\n");
    }

}

bool Check(int x, int y, int value) {

    // check Column
    for (int i = 1; i <= 9; i++) {
        if (i == x)
            continue;
        if (sudoku[i][y] == value)
            return false;
    }

    // check Row
    for (int i = 1; i <= 9; i++) {
        if (i == y)
            continue;
        if (sudoku[x][i] == value)
            return false;
    }

    // check Box
    int boxX = x % 3 == 0 ? x / 3 : x / 3 + 1;
    int boxY = y % 3 == 0 ? y / 3 : y / 3 + 1;
    boxX *= 3;
    boxY *= 3;
    for (int i = boxX - 2; i <= boxX; i++) {
        for (int j = boxY - 2; j <= boxY; j++) {
            if (i == x && j == y)
                continue;
            if (sudoku[i][j] == value)
                return false;
        }
    }

    return true;
}


void DFS(int depth) {

    //printf("%d", depth);
    if (depth == v.size()) {
        Output();
        exit(0);
    }

    int x = v[depth].first;
    int y = v[depth].second;

    for (int i = 1; i <= 9; i++) {
        if (Check(x, y, i)) {
            sudoku[x][y] = i;
            DFS(depth + 1);
            sudoku[x][y] = 0;
        }
    }

    return;
}

void Solve() {
    DFS(0);
}

int main() {

    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    Input();
    Solve();

}
