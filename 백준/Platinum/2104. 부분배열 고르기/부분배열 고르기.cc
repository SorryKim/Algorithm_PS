#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N + 1), prefix(N + 1, 0);

    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        prefix[i] = prefix[i - 1] + A[i];
    }

    vector<int> L(N + 1), R(N + 1);
    stack<int> st;

    // 왼쪽 확장 범위
    for(int i = 1; i <= N; i++) {
        while(!st.empty() && A[st.top()] >= A[i]) st.pop();
        if(st.empty()) L[i] = 1;
        else L[i] = st.top() + 1;
        st.push(i);
    }

    // 스택 초기화 후 오른쪽 확장 범위
    while(!st.empty()) st.pop();
    for(int i = N; i >= 1; i--) {
        while(!st.empty() && A[st.top()] >= A[i]) st.pop();
        if(st.empty()) R[i] = N;
        else R[i] = st.top() - 1;
        st.push(i);
    }

    long long ans = 0;
    for(int i = 1; i <= N; i++) {
        long long sum = prefix[R[i]] - prefix[L[i] - 1];
        ans = max(ans, sum * A[i]);
    }

    cout << ans << "\n";
    return 0;
}
