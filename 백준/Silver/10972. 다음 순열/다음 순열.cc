#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    
    int target = -1;

    // 마지막으로 증가하는 부분찾기
    for(int i = 0; i < N - 1; i++) {
        if(v[i] < v[i + 1]) target = i;
    }

    // 마지막 순열인 경우
    if(target == -1) {
        cout << -1 << '\n';
        return 0;
    }

    // target보다 큰 값 중 가장 작은 값 찾기
    for(int i = N - 1; i > target; i--) {
        if(v[i] > v[target]) {
            swap(v[i], v[target]);
            break;
        }
    }

    // Step 3: target 이후 부분 정렬 (오름차순)
    reverse(v.begin() + target + 1, v.end());

    for(int i = 0; i < N; i++) cout << v[i] << " ";

    return 0;
}
