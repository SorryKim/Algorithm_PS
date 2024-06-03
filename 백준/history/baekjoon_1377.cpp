// 버블소트 / baekjoon_1377.cpp
// https://www.acmicpc.net/problem/1377

#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int,int> A[500001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        A[i].first = num;
        A[i].second = i;
    }


    // 문제에서 제공한 버블소트 코드
    // 사용하면 시간 초과남
    // 출력된 값은 몇 번째 수행에서 버블 정렬이 종료되는지이다.
    // bubble sort의 시간복잡도는 O(n^2)

	/*bool changed = false;
    for (int i = 1; i <= N + 1; i++) {
        changed = false;
        for (int j = 1; j <= N - i; j++) {
            if (A[j] > A[j + 1]) {
                changed = true;
                swap(A[j], A[j + 1]);
            }
        }
        if (changed == false) {
            cout << i << '\n';
            break;
        }
    }*/

    sort(A, A + N);
    int result = 0;

    // 버블소트에서 시행횟수 1번당 좌측으로의 인덱스 변화는 1번밖에 일어날 수가 없다.
    // 따라서 좌측으로의 인덱스변화가 가장 큰 값이 버블소트의 횟수이다.
    for (int i = 0; i < N; i++) {
       if(A[i].second - i >= 0)
            result = max(result, abs(i - A[i].second)); // 원래인덱스에서 얼마나 움직였는가 
    }

    cout << result + 1;
}
