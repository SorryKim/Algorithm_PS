#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y;
    cin >> X >> Y;

    long long D = Y - X;

    if (D == 0) {
        cout << 0;
        return 0;
    }

	// 최대로 늘어날 수 있는 값
    long long maxV = sqrt(D); 

    if (maxV * maxV > D)
		maxV--;

    while ((maxV + 1) * (maxV + 1) <= D)
		maxV++;

    long long S = maxV * maxV;
    long long N;

	// 1 ~ maxV ~ 1로 가능한 경우
    if (D == S) 
        N = 2 * maxV - 1;
    else {
        long long temp = (D - S + maxV - 1) / maxV;
        N = 2 * maxV - 1 + temp;
    }

    cout << N;

    return 0;
}