#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<long long> result;

void DFS(string num) {

    if (!num.empty())
        result.push_back(stoll(num));

    // 다음 숫자 생성
    if (num.size() >= 10) 
        return; // 10자리 이상이면 더 이상 줄어드는 수를 만들 수 없음

    char lastDigit = num.empty() ? '9' : num[num.size() - 1]; // 현재 숫자의 마지막 자리
    for (char ch = lastDigit - 1; ch >= '0'; ch--)
        DFS(num + ch);
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    // DFS를 이용해 줄어드는 수 생성
    for (char c = '0'; c <= '9'; c++) 
        DFS(string(1, c));
    
    sort(result.begin(), result.end());
    if (N <= result.size()) cout << result[N - 1] << '\n';
    else cout << -1 << '\n';
    
    return 0;
}
