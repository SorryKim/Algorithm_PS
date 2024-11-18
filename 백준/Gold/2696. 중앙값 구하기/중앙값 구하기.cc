#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--) {
        int M;
        cin >> M;
        vector<int> results;

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < M; i++) {
            int num;
            cin >> num;

            // 최대 힙과 최소 힙의 밸런스를 유지하며 숫자 삽입
            if (maxHeap.empty() || num <= maxHeap.top()) maxHeap.push(num);
            else minHeap.push(num);
            
            // 힙 크기 조정
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            // 홀수 번째 수일 때 중앙값 저장
            if (i % 2 == 0) results.push_back(maxHeap.top());
        }

        // 결과 출력
        cout << results.size() << "\n";

        for (int i = 0; i < results.size(); i++) {
            cout << results[i] << " ";
            if ((i + 1) % 10 == 0 || i == (results.size() - 1)) cout << "\n";
        }
    }

    return 0;
}
