#include <iostream>
using namespace std;

int main() {
    int birthYear, birthMonth, birthDay;
    int refYear, refMonth, refDay;

    cin >> birthYear >> birthMonth >> birthDay;
    cin >> refYear >> refMonth >> refDay;

    // 만 나이 계산
    int manAge = refYear - birthYear;
    if (refMonth < birthMonth || (refMonth == birthMonth && refDay < birthDay))
        manAge--; // 생일이 지나지 않았다면 만 나이를 하나 줄임
    

    // 세는 나이 계산
    int countingAge = refYear - birthYear + 1;
    // 연 나이 계산
    int yearAge = refYear - birthYear;

    // 결과 출력
    cout << manAge << '\n';
    cout << countingAge << '\n';
    cout << yearAge << '\n';

    return 0;
}
