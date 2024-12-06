#include <iostream>
#include <algorithm>
using namespace std;

// CCW 계산 함수
int CCW(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C) {
    long long result = 1LL * (B.first - A.first) * (C.second - A.second) 
                     - 1LL * (B.second - A.second) * (C.first - A.first);
    
    if (result > 0) return 1;  // 반시계 방향
    if (result < 0) return -1; // 시계 방향
    
    return 0;                  // 일직선
}

// 두 선분이 교차하는지 확인하는 함수
bool Check(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C, pair<long long, long long> D) {
    
    int ccw1 = CCW(A, B, C);
    int ccw2 = CCW(A, B, D);
    int ccw3 = CCW(C, D, A);
    int ccw4 = CCW(C, D, B);

    // 두 선분이 일반적으로 교차하는 경우
    if (ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0) {

        // 일직선인 경우, 경계 포함 여부 추가 확인
        if (ccw1 == 0 && ccw2 == 0 && ccw3 == 0 && ccw4 == 0) {
            if (min(A.first, B.first) <= max(C.first, D.first) &&
                min(C.first, D.first) <= max(A.first, B.first) &&
                min(A.second, B.second) <= max(C.second, D.second) &&
                min(C.second, D.second) <= max(A.second, B.second)) return true;
            return false;
        }
        return true;
    }

    return false;
}

int main() {

    long long x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    pair<long long, long long> A = {x1, y1};
    pair<long long, long long> B = {x2, y2};
    pair<long long, long long> C = {x3, y3};
    pair<long long, long long> D = {x4, y4};

    cout << (Check(A, B, C, D) ? 1 : 0) << '\n';
    return 0;
}
