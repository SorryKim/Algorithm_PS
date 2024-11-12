#include <iostream>
using namespace std;

int main() {
   
    int g, p, t;
    cin >> g >> p >> t;

    
    int a = g * p;

    // 그룹 검사 방식의 테스트 키트 수 계산
    int b = g + (t * p);

    // 결과 비교 및 출력
    if (a < b) 
        cout << 1 << '\n'; 
     else if (a > b) 
        cout << 2 << '\n'; 
    else 
        cout << 0 << '\n';
    

    return 0;
}
