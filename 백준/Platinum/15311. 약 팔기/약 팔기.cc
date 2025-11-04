#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // 약봉지 갯수
    cout << 2000 << "\n";

    // 1 ~ 999자리
    for (int i = 0; i < 1000; ++i)
        cout << 1 << ' ';
    
    // 1000 ~ 1000 * 1000(백만) 자리 커버
    for (int i = 0; i < 1000; ++i)
        cout << 1000 << ' ';
    
    return 0;
}