#include <iostream>
#include <string>
using namespace std;

int main() {
    string x;
    cin >> x;

    // 소수점 위치 찾기
    size_t dot = x.find('.');

    // 소수점 이전 부분만 출력 (정수 부분)
    if (dot != string::npos)
        cout << x.substr(0, dot) << '\n';
    else
        cout << x << '\n'; // 혹시 소수점이 없는 경우

    return 0;
}
