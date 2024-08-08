#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    vector<int> A, B;

    // Input
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        A.push_back(num);
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        B.push_back(num);
    }

    vector<int> answer;
    int maxA, idxA, maxB, idxB;
    bool flag = true;

    while (true)
    {
        if (A.empty() || B.empty())
        {
            flag = false;
            break;
        }

        // 공통 원소 중 최댓값 찾기
        idxA = max_element(A.begin(), A.end()) - A.begin();
        idxB = max_element(B.begin(), B.end()) - B.begin();
        maxA = A[idxA];
        maxB = B[idxB];

        // 최댓값 전 원소들 삭제
        if (maxA == maxB)
        {
            answer.push_back(maxA);
            A.erase(A.begin(), A.begin() + idxA + 1);
            B.erase(B.begin(), B.begin() + idxB + 1);
        }
        else if (maxA > maxB)
            A.erase(A.begin() + idxA);
        else
            B.erase(B.begin() + idxB);
    }

    cout << answer.size() << "\n";
    for (auto a : answer)
        cout << a << " ";
}