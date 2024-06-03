// 도서관 / baekjoon_1461.cpp
// https://www.acmicpc.net/problem/1461

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int book[51];
int point = 0;
long long result = 0;

void Input() {

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> book[i];
        if (book[i] < 0)
            point++;
    }
}


void Solve() {

    sort(book, book + N);

    for (int i = 0; i < point; i += M) 
        result += abs(book[i] * 2);
    

    for (int i = N - 1; i >= point; i -= M) 
        result += abs(book[i] * 2);
    

    result -= max(abs(book[0]), abs(book[N - 1]));

    cout << result;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    Input();
    Solve();

}
