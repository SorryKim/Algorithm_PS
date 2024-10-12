#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double A, B;
    cin >> A >> B;
    const double c = 299792458.0; // 빛의 속도

    // 상대성 속도 덧셈 공식 적용
    double a = A + B; // 분자
    double b = 1.0 + (A * B)/c/c; // 분모
    double answer = a / b; // 총알의 지면 기준 속도

    cout << fixed << setprecision(10) << answer << '\n';
    return 0;
}
