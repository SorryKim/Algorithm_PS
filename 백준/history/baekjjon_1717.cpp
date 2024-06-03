// 집합의 표현  / baekjjon_1717.cpp
// https://www.acmicpc.net/problem/1717

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int parent[1000001];

// 해당원소의 부모를 찾는 메소드
int getP(int x) {
    
    if (parent[x] == x)
        return x;

    return parent[x] = getP(parent[x]);
}

// 집합을 합치는 메소드
void unionP(int x, int y) {

    x = getP(x);
    y = getP(y);

    if (x > y)
        parent[x] = y;
    else
        parent[y] = x;
}

// find 연산
void findP(int x, int y) {

    x = getP(x);
    y = getP(y);
    if (x == y)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
}

void Input() {
    
    cin >> n >> m;

    for (int i = 0; i <= n; i++) 
        parent[i] = i;
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> c >> a >> b;

        if (c == 0)
            unionP(a, b);
        
        else
            findP(a, b);
    }
}

void Solve() {

   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    //Solve();
}
